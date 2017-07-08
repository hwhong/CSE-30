/*
 * Filename: initAnagram.c
 * Author: Hwa Chien Hong
 * Userid: A92072250
 * Description: initAnagram program to initialize an anagram struct for the src
 * string passed in
 * Date: 2/19/17
 * Sources of Help: website links on the course website, Tutors 
 */ 

#include <limits.h>	/* For LONG_MIN and LONG_MAX */
#include "pa3.h"	  /* For function prototype */
#include "pa3Strings.h"
#include <stdio.h> 
#include <stdlib.h>
#include <errno.h> 
#include <strings.h>

/*
  struct Anagram {
    char sortedWord[BUFSIZ];
    size_t numWords;
    char ** words;
  }
 */

int initAnagram( char const * src, struct Anagram * anagram ) {
  
  // allocating for sortedWord member variable
  char dest[BUFSIZ] = {0};
  
  // allocating for the pointer itself 
  char ** words = calloc(1, sizeof(char*));

  // free if unable to allocate
  if( words == NULL ) {
    return -1;
  }

  // allocating for the first index in the array
  *words = calloc(strlen(src) + 1, sizeof(char));

  // free if unable to allocate
  if( words == NULL) {
    free(words);
    (void) fprintf(stderr, STR_ERR_MEM_EXCEEDED);
    return -1;
  }

  // copy over the src to the first space in the array
  (void)strncpy( *words, src, strlen(src) + 1 );
 
  // actually sorted the string in this function call
  upperCaseSortString( src, strlen(src), dest );
  
  // accessing the members of the struct 
  (void)strncpy(anagram -> sortedWord, dest, BUFSIZ);
  anagram -> words = words;
  //strncpy(anagram -> words, words, BUFSIZ);
  anagram -> numWords = 1;
      
  // successful allocation, therefore return 0
  return 0;
}
