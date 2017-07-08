/*
 * Filename: findAnagrams.c
 * Author: Hwa Chien Hong
 * Userid: A92072250
 * Description: findAnagrams program handle the interactive mode of the program
 * it first prompts the user to enter a word and then prints any matching
 * anagrams of that word, excluding the word itself
 *
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

int findAnagrams( struct HashTable const * table ) {
 char buf[BUFSIZ] = {0};
 (void)printf(STR_USER_PROMPT);

 // iterates until the user enters ^D
 while( fgets( buf, BUFSIZ, stdin) != NULL ) {
    // Replace newline character with the \0 character
    *(strchr( buf, '\n')) = '\0';

    // create a new anagram struct for the word being read
    struct Anagram anagram;
    
    // error occured
    if( initAnagram(buf, &anagram) != 0)  return -1;
      
    // calculate the index of the matching anagram
    int index = getTableIndex( anagram.sortedWord, DEFAULT_SIZE);

    struct Anagram * pointer = (((table->entryPtr)+index)->anagramPtr);

    unsigned int outerCount = 0, innerCount = 0; 
    char dest[BUFSIZ] = {0};

    // Iterating through the array of anagrams
    for(pointer = (((table->entryPtr)+index)->anagramPtr);
          outerCount < (((table->entryPtr)+index)->numAnagrams); 
                                                   ++outerCount, ++pointer) {
      char* toCompare = (pointer -> sortedWord);
      // Found Match of sortedWord
      if(strncmp((anagram.sortedWord), toCompare,
                                          strlen(anagram.sortedWord)) == 0) {
        // grab the pointer that traverses through the words array
        char** words = (pointer->words);
        for( words = pointer->words; innerCount < (pointer->numWords);
                                                      ++words, ++innerCount){
          // The word is different than the word being read
          if((strlen(*words)==strlen(buf)) && 
                                strncasecmp(*words, buf, strlen(buf)) != 0) { 
            // append up to the result
            (void)strncat(strcat(dest, STR_SPACE_CHAR), *words, BUFSIZ);
          }
        }
        innerCount = 0;
      }
    }
    
    // There are anagrams to this word entered
    if( strlen(dest) != 0) {
      (void)printf( STR_FOUND_ANAGRAMS );
      (void)printf( "%s \n", dest );
    } else {
      (void)printf( STR_NO_ANAGRAMS );
    }
    //reset the list, so that wont be printed twice
    (void) memset(dest, 0, strlen(dest));
 
    // print the prompt out again for the user
    (void) printf(STR_USER_PROMPT);
  }

  // successful allocation, therefore return 0
  return 0;
}
