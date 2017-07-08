/*
 * Filename: compareLines.c
 * Author: Hwa Chien Hong
 * Userid: A92072250
 * Description: compares two strings case-sensitively
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
 * Function name: compareLines( const void * p1, const void * p2 )
 * Function prototype: int compareLines( const void * p1, const void * p2)
 * Description: function compares (case-sensitively) two input strings using
 * strcmp, compare routine will be passed to qsort() when comparing lines for
 * sorting
 * Parameters: const void * p1, const void * p2 
 *
 * Side Effects: None.
 * Error Conditions: None. 
 * Return Value: an integer to signifies compare result
 */

int compareLines( const void * p1, const void *p2) { 
  // calls strcmp to compare sensitively 
  int res = strcmp(*((char**)p1), *((char**)p2));
  if(res < 0) res = -1;
  else if(res > 0) res = 1;

  return res;
}
 
