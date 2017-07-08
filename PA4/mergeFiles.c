/*
 * Filename: mergeFiles.c
 * Author: Hwa Chien Hong
 * Userid: A92072250
 * Description: function will merge the array of opened files line by line into
 * a single dynamically allocated lines array
 * Date: 3/10/17
 * Sources of Help: website links on the course website, Tutors 
 */ 

#include <limits.h>	/* For LONG_MIN and LONG_MAX */
#include "pa4.h"	  /* For function prototype */
#include "pa4Strings.h"
#include <stdio.h> 
#include <stdlib.h>
#include <errno.h> 
#include <strings.h>

/*
 * Function name: mergeFile( FILE ** files, int numFiles )
 * Function prototype: struct fileLines mergeFile( FILE ** files, int numFiles)
 * Description: merge the array of opened files line by line into a single
 * dynamically allocated lines array
 * Parameters: FILE ** files, int numFiles 
 *
 * Side Effects: None.
 * Error Conditions: None. 
 * Return Value: a struct of fileLines
 */

struct fileLines mergeFiles( FILE ** files, int numFiles ) {
  char buf[BUFSIZ] = {0}; 
  int count = numFiles, i = -1, firstTime = -1;
  int boolean[numFiles];
                                                                       
  struct fileLines fileLines;
                                     
  fileLines.numLines = 0;
  char ** line = calloc(1, sizeof(char*));
 
  while(count != 0) {
    if( fgets(buf, BUFSIZ, files[(i+1)%numFiles]) != NULL ) {
      // null terminate the line read
      *(strchr( buf, '\n')) = '\0';

      if(firstTime == -1) {
        // allocate memory for the first index of the array
        line[0] = calloc(strlen(buf) + 1, sizeof(char));
        (void) strncpy(line[0], buf, strlen(buf));
        firstTime = 0;
        fileLines.numLines = 1;
      } else {
        // Not the first time getting a word

        // Dynamically allocate memory for additional line added
        char ** newlines=realloc(line, sizeof(char*)*(fileLines.numLines) + 1);
      
        // Memory allocation failure
        if( newlines == NULL ) {
          (void) fprintf(stderr, STR_ERR_MEM_EXCEEDED);
          fileLines.lines = NULL;
          fileLines.numLines = -1;
          return fileLines;
        }

        // Allocate individual index memory
        newlines[(fileLines.numLines)] = calloc(strlen(buf) + 1, sizeof(char));
        
        // Copy word read to the char array
        (void) strncpy(newlines[(fileLines.numLines)], buf, strlen(buf));
      
        fileLines.lines = newlines;
        // Increment number of lines added
        (fileLines.numLines)++;
        line = newlines;
      }
      i++;
    } else {
      // Finished reading from one file

      // check if it is already -1, don't want to double count
      // if not -1, means file is done, and first time encountering it 
      if( boolean[(i+1)%numFiles] != -1) {
         boolean[(i+1)%numFiles] = -1;
         if(--count == 0) break;
      }
      i++;
    }
  }  
   
  // Close all the files  
  while( count < numFiles) (void) fclose(files[count++]);
  
  return fileLines;
}
 
