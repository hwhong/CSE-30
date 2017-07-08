/*
 * Filename: displayOutput.c
 * Author: Hwa Chien Hong
 * Userid: A92072250
 * Description: takes the array of distinctLine structs created in buildData()
 * and displays the output lines according to outputMode passed in
 * Date: 3/11/17
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
 * Function name: displayOutput( struct distinctHead distinctHead, 
   unsigned int flags, enum outputMode outputMode )

 * Function prototype: void displayOutput( 
   struct distinctHead distinctHead, unsigned int flags, enum
   outputMode outputMode )

 * Description: function takes the array of distinctLIne structs created in
 * buildData and displays the output lines according to the output mode

 * Parameters: struct distinctHead distinctHead, unsigned int flags, enum
                                                     outputMode outputMode )
 *
 * Side Effects: None.
 * Error Conditions: None. 
 * Return Value: void
 */

void displayOutput( struct distinctHead distinctHead, unsigned int flags, enum
                                                     outputMode outputMode ) {
  if(outputMode == duplicate) {
    
    // Traverse through the whole distinctLine array
    for(int i = 0; i < distinctHead.numDistinctLines; i++) {

        // If the count of each line needs to be printed
        if((flags ^ FLAG_C)==(flags-FLAG_C)) {

          // if its a duplicate
          if((distinctHead.head)[i].count != 1) {
             (void) printf(STR_COUNT_PREFIX, (distinctHead.head)[i].count);
             (void) printf("%s\n", (distinctHead.head)[i].line);
          }
        
        // The count flag is not set
        } else {
           if((distinctHead.head)[i].count != 1) (void) printf("%s\n",
           (distinctHead.head)[i].line);
        } 
    }

  } else if (outputMode == unique) {
     // Traverse through the whole distinctLine array
    for(int i = 0; i < distinctHead.numDistinctLines; i++) {

        // If the count of each line needs to be printed
        if((flags ^ FLAG_C) == (flags-FLAG_C)) {

          // if its an unique entry
          if((distinctHead.head)[i].count == 1) {
             (void) printf(STR_COUNT_PREFIX, (distinctHead.head)[i].count);
             (void) printf("%s\n", (distinctHead.head)[i].line);
          }
        
        // The count flag is not set
        } else {
           if((distinctHead.head)[i].count == 1) (void) printf("%s\n",
           (distinctHead.head)[i].line);
        } 
    }

  } else {
     // Traverse through the whole distinctLine array
    for(int i = 0; i < distinctHead.numDistinctLines; i++) {

        // If the count of each line needs to be printed
        if((flags ^ FLAG_C) == (flags - FLAG_C)) {
          (void) printf(STR_COUNT_PREFIX, (distinctHead.head)[i].count);
          (void) printf("%s\n", (distinctHead.head)[i].line);
        // The count flag is not set
        } else {
          (void) printf("%s\n", (distinctHead.head)[i].line);
        } 
    }
  }
}
