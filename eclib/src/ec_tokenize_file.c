#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <assert.h>

#include "ec_tokenize_file.h"

void tokenizefile(char *filename)
{
	printf("Source file: %s\n compiling ...\n", filename);

	SentenceQueueNodePtr sentenceHeadPtr = NULL;
	SentenceQueueNodePtr sentenceTailPtr = NULL;

	char c;
	char text_string[80];
	int text_string_len = 0;
	int str_len = 0;

	int white_space = 0;

	int last_character = AT_BEGINING;

	FILE *fPtr;

	if (( fPtr = fopen( filename, "r")) == NULL ) {
     		printf("File opening Error: %s file not found\n", filename);
		exit(EXIT_SUCCESS);
	}
	else {
		while((c = fgetc(fPtr)) != EOF) {
			switch ( c ) {
				case ':':
					if ( last_character == TEXT ) {
						text_string[str_len] = '\0'; /* terminating string */
						str_len++; /* for \0 */
						enqueueSentenceQueue(&sentenceHeadPtr, &sentenceTailPtr, text_string, str_len);
					}

					enqueueSentenceQueue(&sentenceHeadPtr, &sentenceTailPtr, ": ", 2);

					str_len = 0;
					last_character = COLON;

					break;

				case ' ':
					if ( last_character == TEXT ) {
						text_string[str_len] = '\0'; /* terminating string */
						str_len++;
						enqueueSentenceQueue(&sentenceHeadPtr, &sentenceTailPtr, text_string, str_len);
						str_len = 0;

						last_character = WHITE_SPACE;
					}
					else if ( last_character == AT_BEGINING  || last_character == DOUBLE_QUOTE || last_character == SINGLE_QUOTE) {
						text_string[str_len++] = c;
					}

					break;

				case '\'':
					if ( last_character == BACK_SLASH ) {
						text_string[str_len++] = c;
						last_character = SINGLE_QUOTE;
					}
					else if ( last_character == SINGLE_QUOTE ) {
						text_string[str_len] = '\0'; /* terminating string */
						str_len++;
						enqueueSentenceQueue(&sentenceHeadPtr, &sentenceTailPtr, text_string, str_len);
						str_len = 0;

						last_character = END_QUOTE;
					}


					last_character = SINGLE_QUOTE;
					break;

				case '"':
					if ( last_character == BACK_SLASH ) {
						text_string[str_len++] = c;
						last_character = DOUBLE_QUOTE;
					}
					else if ( last_character == DOUBLE_QUOTE) {
						text_string[str_len++] = c;
						text_string[str_len] = '\0'; /* terminating string */
						str_len++;
						enqueueSentenceQueue(&sentenceHeadPtr, &sentenceTailPtr, text_string, str_len);
						str_len = 0;

						last_character = END_QUOTE;
					}
					else {
						text_string[str_len++] = c;
						last_character = DOUBLE_QUOTE;
					}

					break;

				case '\\':
					text_string[str_len++] = c;
					last_character = BACK_SLASH;
					break;

				case '\n':
					/* enqueueLinsQueue(&linesentenceHeadPtr, &lineTailPtr,  */
					last_character = AT_BEGINING;
					break;

				default:
					if ( last_character == AT_BEGINING && str_len > 0 ) { /* append begining indentation white spaces */
						text_string[str_len] = '\0'; /* terminating string */
						str_len++;
						str_len = 0;

						last_character = TEXT;
					}
					else if ( last_character == DOUBLE_QUOTE || last_character == SINGLE_QUOTE) {
						text_string[str_len++] = c;
					}
					else {
						text_string[str_len++] = c;
						last_character = TEXT;
					}

					break;
			}
		}

		fclose(fPtr);
	}

	printf("Source file: %s\n compile ...\n", filename);
}


void enqueueSentenceQueue(SentenceQueueNodePtr *sentenceHeadPtr, SentenceQueueNodePtr *sentenceTailPtr, char text_string[], int str_len)
{
	SentenceQueueNodePtr newPtr;
	Sentence *sentencePtr;

	newPtr = malloc(sizeof(SentenceQueueNode));

	if ( newPtr != NULL ) {
		sentencePtr = malloc(sizeof(str_len));
		if ( sentencePtr != NULL) {
			newPtr->sentencedata = sentencePtr;
			newPtr->nextPtr = NULL;
		}
		/* if no any node exist insert node at head */
		if ( *sentenceHeadPtr == NULL ) {
			*sentenceHeadPtr = newPtr;
		}
		else {
			(*sentenceTailPtr)->nextPtr = newPtr;
		}

		*sentenceTailPtr =newPtr;
	}
	else {
		perror("No memory available");
		exit(EXIT_FAILURE);
	}
}
