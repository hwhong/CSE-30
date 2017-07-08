/*
 * Filename: main.c
 * Author: Hwa Chien Hong
 * Userid: A92072250
 * Description: main driver for the program. Main tasks are to parse the 
 * command line arguments, build the hashtable, and enter eiter interavtive
 * or statistics mode
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
#include <ctype.h>

int main( int argc, char * argv[] ) {
  char filename[] = DEFAULT_DICT_FILENAME;
  char * endptr;
  long UPPER_BOUND = 1000;
  int TABLE_SIZE = DEFAULT_SIZE, TABLE_INDEX = 1, c, BASE = 10, infoFlag = 0;
  errno = 0;
  int table_size;
  // Expected arguments -f -s -i (not required -h)
  while(( c = getopt(argc, argv, ARG_STR)) != -1) {
    switch( c ) {
    //-----------------------------CASE 1 [FILE]-------------------------------
    case CHAR_FILE_FLAG:
      (void) strncpy(filename,optarg, strlen(optarg) + 1);
      break;
    //-----------------------------CASE 2 [SIZE]------------------------------
    case CHAR_SIZE_FLAG:
      errno = 0;
      table_size = (int)strtol(optarg, &endptr, BASE);
      
      // checks whether the input is an int
      if( *endptr != '\0' ) {
         (void) fprintf(stderr, STR_ERR_NOTINT, optarg);
         usage(stderr, USAGE_SHORT, argv[0]);
         return EXIT_FAILURE;
         
      // the input is an integer, but cannot be converted
      } else if( errno != 0) {
         (void) fprintf(stderr, STR_ERR_CONVERTING, optarg, BASE);
         usage(stderr, USAGE_SHORT, argv[0]);
         return EXIT_FAILURE;
      }
      TABLE_SIZE = table_size;
      endptr = '\0';
      errno = 0;

      break;
    //------------------------------CASE 3 [INFO]------------------------------
    case CHAR_INFO_FLAG:
      infoFlag = -1;
      
      // checks if the input is valid, i.e numeric?
      int table_index = (int)strtol(optarg, &endptr, BASE);
      if( *endptr != '\0' ) {
         (void) fprintf(stderr, STR_ERR_NOTINT, optarg);
         usage(stderr, USAGE_SHORT, argv[0]);
         return EXIT_FAILURE;

      // checks whether the input can be converted, is it too big?
      } else if( errno != 0) {
         (void) fprintf(stderr, STR_ERR_CONVERTING, optarg, BASE);
         usage(stderr, USAGE_SHORT, argv[0]);
         return EXIT_FAILURE;
      }
      TABLE_INDEX = table_index;
      endptr = '\0';
     errno = 0;

      break;
    //------------------------------CASE 4 [HELP]------------------------------
    case CHAR_HELP_FLAG:
      usage(stderr, USAGE_LONG, argv[0]);
      (void) fprintf(stderr, "Going in");
      return EXIT_SUCCESS;
    //-----------------------------CASE 5 [DEFAULT]----------------------------
    default: // in the case of ?
      usage(stderr, USAGE_SHORT, argv[0]);
      return EXIT_FAILURE;
    }
  }  
  // Extra arguments inputted 
  if(optind < argc) {
    (void) fprintf(stderr, STR_ERR_EXTRA_ARGS, argv[optind]);
    usage(stderr, USAGE_SHORT, argv[0]);
    return EXIT_FAILURE;
  }

  // Hashtable size not within range
  if( isInBounds(1, UPPER_BOUND, TABLE_SIZE) != 1) {
    (void) fprintf(stderr, STR_ERR_RANGE, STR_ERR_SIZE, 
                                        MIN_SIZE, MAX_SIZE);
    usage(stderr, USAGE_SHORT, argv[0]);
    return EXIT_FAILURE;
  }

   // Hashtable index not within range
  if( isInBounds(0, TABLE_SIZE, TABLE_INDEX) != 1) {
  
    (void) fprintf(stderr, STR_ERR_RANGE, STR_ERR_INDEX, 0, TABLE_SIZE-1);
    usage(stderr, USAGE_SHORT, argv[0]);
    return EXIT_FAILURE;
  }

  // allocating for TableEntry array in the hashtable
  struct TableEntry *entryPtr = calloc(TABLE_SIZE,sizeof(struct TableEntry));

  // failure to allocate memory for tableEntry in the hashtable
  if( entryPtr == NULL) {
    free(entryPtr);
    (void) fprintf(stderr, STR_ERR_MEM_EXCEEDED);
    usage(stderr, USAGE_SHORT, argv[0]);
    return EXIT_FAILURE;
  }

  // allocating space for the struct hashtable
  struct HashTable table;
  
  // initialize hashtable struct variables 
  table.entryPtr = entryPtr;
  table.size = TABLE_SIZE;

  // populate the dictionary
  if(loadDict(filename, &table) == -1) {
    usage(stderr, USAGE_SHORT, argv[0]);
    return EXIT_FAILURE;
  }
  
  if( infoFlag == -1) printStats( &table, TABLE_INDEX );
  else (void) findAnagrams(&table);
  
  // Free all the memory previously allocated 
  unsigned int i, j, k;
  for( i = 0; i < table.size; i++) {
     struct TableEntry* entry = (table.entryPtr);
     for( j = 0; j < (entry->numAnagrams); j++) {
       struct Anagram * anagram = (entry->anagramPtr);
       char ** words = (anagram->words);
       for( k = 0; k < (anagram->numWords); k++) {
         free(words+k);
       }
       free(anagram+j);
     }
     free(entry+i);
  }
   
   return EXIT_SUCCESS;
}
