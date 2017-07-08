/*
 * Filename: buildData.c
 * Author: Hwa Chien Hong
 * Userid: A92072250
 * Description: take the content of the merged input files and will filter out
 * consecutive duplicated lines.
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
 * Function name: buildData( struct fileLines * fileLines, unsigned int flags )
 * Function prototype: struct distinctHead buildData( struct fileLines * 
                                               fileLines, unsigned int flags  )
 * Description: takes the content for the merged input files and filter out
 *              consecutive duplicated lines
 * Parameters: struct fileLines * fileLines, unsigned int flags 
 *
 * Side Effects: None.
 * Error Conditions: None. 
 * Return Value: a struct of distinctHead
 */

struct distinctHead buildData( struct fileLines * fileLines, 
                                                         unsigned int flags ) {
  struct distinctHead dh;
  // Preamptively set the variables to the default values, in case of memory
  // allocation failures. 
  dh.head = NULL;
  dh.numDistinctLines = 0;
  
  // Initializing the first of the distinctLine array
  struct distinctLine * dist_arr = (struct distinctLine *) 
                                         malloc(sizeof(struct distinctLine *));
  // Memory allocation failure, return an empty distinctHead
  if( dist_arr == NULL ){
    (void) fprintf(stderr, STR_ERR_MEM_EXCEEDED );
    return dh;
  }

  // If the result of flag XOR ignore case flag is 0, then we ignores the case
  if((flags ^ FLAG_I) == (flags - FLAG_I)) {
   
    // Ignore cases
    int leftOff = 0;
    // Sorting it here
    for(int i = 0; i < (fileLines->numLines); i++) {
      // First element of distinctLine, nothing else to compare 
      if(i == 0) {
        (*dist_arr).line = ((*fileLines).lines)[i];
        (*dist_arr).count = 1;
   
        //-------------------
        // dh is distinctHead
        //------------------
        dh.head = dist_arr;
        dh.numDistinctLines = 1;
      
      } else {
        //------------------------------------------------
        // If the current line we are one is the same
        // as the previous distinctLine, only increment the count 
        //------------------------------------------------
        if(strcasecmp(dist_arr[leftOff].line, ((*fileLines).lines)[i]) == 0) {
           dist_arr[leftOff].count++;
        } else {
          //-------------------------------------------
          // If the current line we are on is different
          // Need to realloc, and add the additional line
          //-------------------------------------------

          dist_arr = (struct distinctLine *) realloc(dist_arr,
                         (dh.numDistinctLines + 1)*sizeof(struct distinctLine));
          
          // Memory allocation failure, need to return what we have currently
          if( dist_arr == NULL ) {
            (void) fprintf(stderr, STR_ERR_MEM_EXCEEDED);
            return dh;
          }

          dist_arr[leftOff+1].line = ((*fileLines).lines)[i];
          dist_arr[leftOff+1].count = 1;

          // Reassigning the member variables for distinctHead
          dh.head = dist_arr;
          dh.numDistinctLines++;
          leftOff++;
        }
      }
    }

  } else {
    // Don't Ignore case
    int leftOff = 0;
    for(int i = 0; i < (fileLines->numLines); i++) {
      // First element of distinctLine, nothing else to compare 
      if(i == 0) {
        (*dist_arr).line = ((*fileLines).lines)[i];
        (*dist_arr).count = 1;
        
        //-------------------
        // dh is distinctHead
        //------------------
        dh.head = dist_arr;
        dh.numDistinctLines = 1;
      } else {
        //------------------------------------------------
        // If the current line we are one is the same
        // as the previous distinctLine, only increment the count 
        //------------------------------------------------
        if(strcmp(dist_arr[leftOff].line, (fileLines->lines)[i]) == 0) {
           dist_arr[leftOff].count++;
        
        } else {
          //-------------------------------------------
          // If the current line we are on is different
          // Need to realloc, and add the additional line
          //-------------------------------------------

          dist_arr = (struct distinctLine *) realloc(dist_arr,
                         (dh.numDistinctLines + 1)*sizeof(struct distinctLine));
          
          // Memory allocation failure, need to return what we have currently
          if( dist_arr == NULL ) {
            (void) fprintf(stderr, STR_ERR_MEM_EXCEEDED);
            return dh;
          }

          dist_arr[leftOff+1].line = (fileLines->lines)[i];
          dist_arr[leftOff+1].count = 1;

          // Reassigning the member variables for distinctHead
          dh.head = dist_arr;
          dh.numDistinctLines++;
          leftOff++;
        }
      }
    }
  }
  return dh;
}
 
