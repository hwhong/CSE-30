/*
 * Filename: sortFiles.c
 * Author: Hwa Chien Hong
 * Userid: A92072250
 * Description: sort the files from filenames using qsort and the respective
 * compare function according to the flags specified.
 * word into memory. 
 * Date: 3/3/17
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
 * Function name: sortFiles( int numFiles, char * filenames[],
   unsigned int flags )

 * Function prototype: FILE** sortFiles( int numFiles, char * filenames[],
   unsigned int flags )

 * Description: function sorts the files from filenames using qsort and the
 * respective compare function according to the flags specified.

 * Parameters: int numFiles, char * filenames[], unsigned int flags 
 *
 * Side Effects: None.
 * Error Conditions: None. 
 * Return Value: pointer to an array of FILE pointers
 */

FILE** sortFiles( int numFiles, char * filenames[], unsigned int flags ) {
 
  // creating an array of fileInfo struct to hold the needed info
  struct fileInfo * info_array = malloc(sizeof(struct fileInfo)*numFiles);
  if( info_array == NULL) {
    // memory allocation failure
    (void) fprintf(stderr, STR_ERR_MEM_EXCEEDED);
    return NULL;
  }
  
  // Populate the array of fileInfo
  for(int i = 0; i < numFiles; i++) {
    // Assigning values of stats to the stat variable in fileInfo Struct
    if( stat(filenames[i], &(info_array[i].statInformation)) == -1 ) {
        perror(filenames[i]);
        // if error, Null pointer is returned
        return NULL;
    }
    // Assigning values of filename to the filename variable in fileInfo Struct
    info_array[i].filename = filenames[i];
  }
   
  unsigned int rev_mask = 0x10, time_mask = 0x40;
  // Handles sorting and parsing of flag inputs 
  if( (time_mask ^ flags) == (flags - time_mask) ) {
    // time flag is passed
    if( (rev_mask ^ flags) == (flags - rev_mask)) {
      qsort(info_array, numFiles, sizeof(struct fileInfo), revTimeCompare);
    } else {
      qsort(info_array, numFiles, sizeof(struct fileInfo), timeCompare);
    }
  } else {
    // time flag not passed in
    if( (rev_mask ^ flags) == (flags - rev_mask)) {
      qsort(info_array, numFiles, sizeof(struct fileInfo), revFilenameCompare);
    } else {
    // Dont reverse, other word, the default option
      qsort(info_array, numFiles, sizeof(struct fileInfo), filenameCompare);
    }
  }

  // Allocate size for the opened files
  FILE** file_array = malloc(sizeof(FILE*) * numFiles);
  // Memory allocation failure
  if( file_array == NULL) {
    (void) fprintf(stderr, STR_ERR_MEM_EXCEEDED);
    return NULL;
  }

  // Populate the array of FILE Pointers
  for(int j = 0; j < numFiles; j++) {
    errno = 0;
    *(file_array + j) = fopen(info_array[j].filename, "r");
    // unable to be opened, therefore Null pointer returned
    if(errno != 0 || *(file_array + j) == NULL)  {
      perror(info_array[j].filename);
      return NULL;
    }
  }

  return file_array;
}
 
