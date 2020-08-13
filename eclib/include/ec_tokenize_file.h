/* global */
/* sentence space */
enum CharType { AT_BEGINING, WHITE_SPACE, TEXT, COLON, SINGLE_QUOTE, DOUBLE_QUOTE, END_QUOTE, BACK_SLASH };

/* sentence type */
enum { FILE_NAME, CLASS, METHOD, FUNCTION, STDFUNCTION, COMMENT };

/* line type */
enum { STATEMENT, EMPTY_LINE, FUNCTION_DEF, FUNCTION_CALL, CLASS_DEF, CLASS_CALL };

/* key words */
enum {AUTO, BREAK, CASE, CHAR, CONST, CONTINUE, DEFAULT, DO, DOUBLE, ELSE, ENUM, EXTERN, FLOAT, FOR, GOTO, IF, INT, LONG, REGISTER, RETURN, SHORT, SIGNED, SIZEOF, STATIC, STRUCT, SWITCH, UNION, UNSIGNED, VOID, VOLATILE, WHILE};


char scapes[] = {'\n','\a', '\"', '\t', '\\'};

char *comment[] = {"//", "/*", "*/"};

char *data_types[] = {"int", "double", "float", "long"};

char *data_prefix[] = {"signed", "unsigned"};

char arithmatic_operators[] = {'+', '-', '/', '%'};

char *relational_operators[] = {"==", "!=", ">", "<", ">=", "<="};

char precedence[] = { '*', '/', '%', '+', '-' };

char *associativity[] = { "< ", "<=" };


/* standard functions */
char *std_ec_funcs[] = { "print", "scan", "open" };
char *rltd_c_funcs[] = { "printf", "scanf", "fopen" }; /* related c functions */
char *rltd_hdrs[] = { "stdio.h" ,  "stdio.h" ,  "stdio.h" }; /* related headers */

/* strucures */
struct sentence {
	int sentence_type;
	char *sentence;
};

typedef struct sentence Sentence;
typedef Sentence *SentencePtr;

/* sentence Queue */
struct sentenceQueueNode {
	
	Sentence *sentencedata;
	struct sentenceQueueNode *nextPtr;
};

typedef struct sentenceQueueNode SentenceQueueNode;
typedef SentenceQueueNode *SentenceQueueNodePtr;

/* line */
struct lineNode {
	int line_type;
	struct sentenceQueueNode *sentenceHeadPtr;
	struct sentenceQueueNode *sentenceTailPtr;
};

typedef struct lineNode LineNode;
typedef LineNode *LineQueueNodePtr;

/* lines Queue */
struct linesQueueNode {
	LineNode *linePtr;
	struct linesQueueNode *nextPtr;
};

typedef struct linesQueueNode LinesQueueNode;
typedef LinesQueueNode* LinesQueueNodePtr;

/* file */
struct fileNode {
	LinesQueueNode *linesPtr;
};

typedef struct fileNode FileNode;
typedef FileNode* FileNodePtr;


/* files */
struct filesList {
	char *filename;
	FileNode *filePtr;
	struct filesList *nextPtr;
};

typedef struct filesList FileList;
typedef FileList *FileListPtr;

/* prototypes */
void tokenizefile(char *filename) ;
void enqueueSentenceQueue(SentenceQueueNodePtr *sentenceHeadPtr, SentenceQueueNodePtr *sentenceTailPtr, char text_string[], int str_len);
