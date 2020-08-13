#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

#ifdef __linux__
#else
#include <windows.h>
#endif

// copy to clipboard work fine solution on windows
/*#include <stdio.h> */
/*#include <windows.h> */
/*#include <iostream.h>*/
/*#include <fstream.h>*/
/*#include <stdlib.h>*/
/*#include <string.h>*/
/*#include <windows.h>*/
/*#include <cstdio> */
/*#include <conio.h>*/

/*int GetClipboardSize() */
/*{ */
  /*OpenClipboard(NULL) ;                          // Obtain clipboard */
  /*HGLOBAL handle = GetClipboardData (CF_TEXT) ;  // get handle to data */
  /*CloseClipboard() ;                             // Close clipboard */
  /*return GlobalSize( handle ) ;                  // return size of data */
/*} */

/*void GetClipboardText( TCHAR * buffer ) */
/*{ */
  /*OpenClipboard(NULL) ;                          // Obtain clipboard  */
  /*HGLOBAL handle = GetClipboardData (CF_TEXT) ;  // get handle to data  */
  /*char* szClipboard = (char*)GlobalLock(handle); // lock data */
  /*lstrcpy( buffer, szClipboard ) ;               // copy clipboard text */
  /*GlobalUnlock (handle) ;                        // unlock data */
  /*CloseClipboard () ;                            // close data */
/*} */

/*int main() */
/*{*/
  /*// Allocate enough memory to save text in clipboard. */
  /*char * szClipboardText = new char[ GetClipboardSize() + 1 ] ; */

  /*// Get the clipboard text. */
  /*GetClipboardText( szClipboardText ) ; */

  /*// Print clipboard text. */
  /*printf( "Clipboard Text: \"%s\"", szClipboardText ); */
/*cout << endl;*/

  /*// Delete the memory. */
  /*delete[] szClipboardText ; */

  /*getchar(); */
/*}*/

void
copy_to_clipbord ()
{
#ifdef __linux__
#else
  const char *Str = "Hello world";
  const size_t strLen = lstrlenA(Str) + 1;
  HGLOBAL hGlobal =  GlobalAlloc(GMEM_MOVEABLE, strLen); //Memory must be moveable!
  memcpy(GlobalLock(hGlobal), Str, strLen);
  GlobalUnlock(hGlobal);
  OpenClipboard(NULL);
  EmptyClipboard();
  SetClipboardData(CF_TEXT, hGlobal);
  CloseClipboard();
#endif
}

#ifdef __linux__
#else

void SetClipboardText( HWND hwnd, TCHAR * szText )
{
  HGLOBAL globalHandle = GlobalAlloc( GHND|GMEM_SHARE,
                                     (lstrlen(szText)+1) * sizeof(TCHAR)) ;

  TCHAR * szClipboard = (TCHAR*)GlobalLock(globalHandle) ;
  lstrcpy( szClipboard, szText ) ;
  GlobalUnlock (globalHandle) ;
  OpenClipboard(hwnd) ;
  EmptyClipboard () ;
  SetClipboardData (CF_TEXT, globalHandle) ;
  CloseClipboard() ;
}
#endif

// man 2 stat and man 2 mkdir
struct stat st = {0};

void make_directory(const char* name)
{
#ifdef __linux__
   mkdir(name, 0777);
#else
   _mkdir(name);
#endif
}

void
test_make_directory ( int argc, char *argv[])
{
  if (stat("New", &st) == -1) {
    make_directory ("New");
  }
}

#ifdef _WIN32
#include <direct.h>

int
remove_directory
(
  const char *path
)
{
 DIR *d = opendir(path);
 size_t path_len = strlen(path);
 int r = -1;

 if (d) {
  struct dirent *p;

  r = 0;
  while (!r && (p=readdir(d))) {
    int r2 = -1;
    char *buf;
    size_t len;

    /* Skip the names "." and ".." as we don't want to recurse on them. */
    if (!strcmp(p->d_name, ".") || !strcmp(p->d_name, ".."))
       continue;

    len = path_len + strlen(p->d_name) + 2;
    buf = malloc(len);

    if (buf) {
       struct stat statbuf;

       snprintf(buf, len, "%s/%s", path, p->d_name);
       if (!stat(buf, &statbuf)) {
          if (S_ISDIR(statbuf.st_mode))
             r2 = remove_directory(buf);
          else
             r2 = unlink(buf);
       }
       free(buf);
    }
    r = r2;
  }
  closedir(d);
 }

 if (!r)
    r = rmdir(path);

 return r;
}



// remove derectory on linux bsd and osx
int
recursive_delete
(
  const char *dir
)
{
  int ret = 0;
  FTS *ftsp = NULL;
  FTSENT *curr;

  // Cast needed (in C) because fts_open() takes a "char * const *", instead
  // of a "const char * const *", which is only allowed in C++. fts_open()
  // does not modify the argument.
  char *files[] = { (char *) dir, NULL };

  // FTS_NOCHDIR  - Avoid changing cwd, which could cause unexpected behavior
  //                in multithreaded programs
  // FTS_PHYSICAL - Don't follow symlinks. Prevents deletion of files outside
  //                of the specified directory
  // FTS_XDEV     - Don't cross filesystem boundaries
  ftsp = fts_open(files, FTS_NOCHDIR | FTS_PHYSICAL | FTS_XDEV, NULL);
  if (!ftsp) {
      fprintf(stderr, "%s: fts_open failed: %s\n", dir, strerror(curr->fts_errno));
      ret = -1;
      goto finish;
  }

  while ((curr = fts_read(ftsp))) {
    switch (curr->fts_info) {
      case FTS_NS:
      case FTS_DNR:
      case FTS_ERR:
        fprintf(stderr, "%s: fts_read error: %s\n",
                curr->fts_accpath, strerror(curr->fts_errno));
        break;

      case FTS_DC:
      case FTS_DOT:
      case FTS_NSOK:
        // Not reached unless FTS_LOGICAL, FTS_SEEDOT, or FTS_NOSTAT were
        // passed to fts_open()
        break;

      case FTS_D:
        // Do nothing. Need depth-first search, so directories are deleted
        // in FTS_DP
        break;

      case FTS_DP:
      case FTS_F:
      case FTS_SL:
      case FTS_SLNONE:
      case FTS_DEFAULT:
        if (remove(curr->fts_accpath) < 0) {
          fprintf(stderr, "%s: Failed to remove: %s\n",
                  curr->fts_path, strerror(curr->fts_errno));
          ret = -1;
        }
        break;
    }
  }

finish:
  if (ftsp) {
    fts_close(ftsp);
  }

  return ret;
}


#elif defined __linux__
#include <sys/stat.h>
#endif

int is_file_exist (char *filename)
{
  /* try to open file to read */
   FILE *file;
   if (file = fopen(filename, "r")) {
      fclose(file);
      return 1;
   } else {
      return 0;
   }
}

#ifdef _WIN32

// window file path exist
#include <windows.h>
#include <iostream.h>
#include "Shlwapi.h"

void main(void)
{
    // Valid file path name (file is there).
    char buffer_1[ ] = "C:\\TEST\\file.txt";
    char *lpStr1;
    lpStr1 = buffer_1;

    // Invalid file path name (file is not there).
    char buffer_2[ ] = "C:\\TEST\\file.doc";
    char *lpStr2;
    lpStr2 = buffer_2;

    // Return value from "PathFileExists".
    int retval;

    // Search for the presence of a file with a true result.
    retval = PathFileExists(lpStr1);
    if(retval == 1)
    {
        cout << "Search for the file path of : " << lpStr1 << endl;
        cout << "The file requested \"" << lpStr1 << "\" is a valid file" << endl;
        cout << "The return from function is : " << retval << endl;
    }

    else
    {
        cout << "\nThe file requested " << lpStr1 << " is not a valid file" << endl;
        cout << "The return from function is : " << retval << endl;
    }

    // Search for the presence of a file with a false result.
    retval = PathFileExists(lpStr2);

    if(retval == 1)
    {
        cout << "\nThe file requested " << lpStr2 << "is a valid file" << endl;
        cout << "Search for the file path of : " << lpStr2 << endl;
        cout << "The return from function is : " << retval << endl;
    }
    else
    {
        cout << "\nThe file requested \"" << lpStr2 << "\" is not a valid file" << endl;
        cout << "The return from function is : " << retval << endl;
    }
}

#endif
/*OUTPUT*/
/*==============*/
/*Search for the file path of : C:\TEST\file.txt*/
/*The file requested "C:\TEST\file.txt" is a valid file*/
/*The return from function is : 1*/

/*The file requested "C:\TEST\file.doc" is not a valid file*/
/*The return from function is : 0*/
