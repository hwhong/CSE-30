/*
 * Filename: loadDict.c
 * Author: Hwa Chien Hong
 * Userid: A92072250
 * Description: loadDict program to open and read the dictionary file word by
 * word into memory. 
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


int loadDict( char * filename, struct HashTable * table ) {
  FILE * file = stdin;
  char buf[BUFSIZ] = {0}; 
  char * read = "r";
  errno = 0;

  // encounters an error when opening the file
  if( NULL == fopen( filename, read) ) {

    //print the proper error message here    
    if( errno == EACCES ) (void) fprintf( stderr, STR_ERR_FILE_PERMISSION );
    if( errno == ENOENT ) (void) fprintf( stderr, STR_ERR_FILE_INVALID );
   
    // return here
    return -1; 
  }
 
  // reads the file here
  file = fopen( filename, read);
   
  // performing operations for each word in the dictionary
  for( ; fgets( buf, BUFSIZ, file) != NULL; ) {
      
      // NULL terminate the word read by replacing the newline character with a
      // null character
      *(strchr( buf, '\n')) = '\0'; 
      //(void) fprintf(stderr, "after strchr \n"); 
      struct Anagram anagram;
      // call to create temporary Anagram
      if( initAnagram( buf, &anagram) != 0) return -1;
      
      // Get the table index of the anagram
      int index = getTableIndex( anagram.sortedWord, table->size );

      // Go to the TableEntry corresponding to the table index and check whether
      // or not the Anagram array has been initialized

      // In the case that it has been initialized
      if ((((table->entryPtr) + index)->anagramPtr) != NULL ) {

         // get the starting pointer
         struct TableEntry * te = (table -> entryPtr)+index;
  
         struct Anagram * ana_pointer = (te -> anagramPtr);      
         unsigned int flag = 0, count = 0;

         // iterating the Anagram to find the match of sortedWord
         for(ana_pointer = (((table->entryPtr)+index)->anagramPtr);
                      count < (((table->entryPtr)+index)->numAnagrams); 
                                                 ++count, ++ana_pointer ) {
            // match   
            char * toCompare = ana_pointer->sortedWord;

            if ( strcmp( anagram.sortedWord, toCompare) == 0){
              flag = 1;
               
              // reallocate space for the additional word
              // i.e the individual space of the words array
              // * The way to allocate memory
              char** words = realloc(ana_pointer->words, 
                                     sizeof(char*) *(ana_pointer->numWords+1));

              // Check for memory allocation failure
              if( words == NULL) {
                  free(words);
                  (void) fprintf(stderr, STR_ERR_MEM_EXCEEDED);
                  return -1;
              }
              // allocating for the actual word in the array of pointers
              words[ana_pointer->numWords] = 
                                         calloc(strlen(buf) + 1, sizeof(char));
              
              // actually adding the word into the word array
              (void) strncpy(words[ana_pointer->numWords], buf, strlen(buf));

              // increases the count of number of words in anagram
              (ana_pointer->numWords)++; 
              (ana_pointer -> words) = words; 
              break;
            }

         }
         count = 0;

         // dosent match
         if(!flag) {
            // increasing the size of anagram array by 1
            // ana_pointer = realloc(ana_pointer,
            // * the sizeof should be *new_ana_pointer
            struct Anagram * new_ana_pointer = realloc(te->anagramPtr,
                                sizeof(*new_ana_pointer) * (te->numAnagrams + 1));
        
            // memory allocation failure
            if(new_ana_pointer == NULL) {
                free(ana_pointer);
                (void) fprintf(stderr, STR_ERR_MEM_EXCEEDED);
                return -1;
            }
            
            // append the temp strcut anagram to the array of anagrams
            new_ana_pointer[((table->entryPtr)+index)->numAnagrams] = anagram;
            // increases num of anagrams in this tableEntry
            (((table->entryPtr)+index)->numAnagrams)++;
            //reassign to the new anagram pointer
            (te->anagramPtr) = new_ana_pointer;
         }

      } else {
      // the tableEntry has no yet been initialized a struct Anagram array for
      // this index
        struct Anagram* array = malloc(sizeof(struct Anagram));
        
        // setting the first entry of this new array to the temp struct
        array[0] = anagram;

        // assign the pointer to the entryPointer's member variable
        (((table->entryPtr)+index)->anagramPtr) = array;
     
        // incremenet number of anagrams in this tableEntry
        (((table->entryPtr)+index)->numAnagrams)++;
      }
  }
  // success loading
  return 0;
}
