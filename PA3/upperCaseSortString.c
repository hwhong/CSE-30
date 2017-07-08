/*
 * Filename: upperCaseSortString .c
 * Author: Hwa Chien Hong
 * Userid: A92072250
 * Description: a function that will take the src string and will store a copy
 * in dest where all the characters are converted to uppercase and sorted in 
 * alphabetical order. 
 * Date: 2/17/17
 * Sources of Help: website links on the course website, Tutors 
 */ 

#include "pa3.h"	/* For function prototype */
#include <stdio.h> 
#include <stdlib.h>
#include <errno.h> 
#include <strings.h>
#include <ctype.h>

void upperCaseSortString ( char const * src, int n, char * dest ) {
 
  // First make a copy of the string passed in
  char * copy = malloc( 1 + n );
  char * pointer;
 
  (void) strcpy (copy, src);
  
  // transform each char in the copy to uppercase letter
  for(pointer = copy; *pointer != '\0'; ++pointer) {
    *pointer = toupper(*pointer);
    //printf("%c \n", *pointer);
  }
  // actually sort the elements in the copied string
  qsort(copy, strlen(copy), sizeof(char), charCompare);
 
  // Assign char to dest one by one
  char * copyPointer= copy;
  char * destPointer = dest;
  for(copyPointer = copy; *copyPointer != '\0'; ++copyPointer, ++destPointer) {
    *destPointer = *copyPointer;
  }
  *destPointer = '\0';
}
