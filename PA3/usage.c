/*
 * Filename: usage.c
 * Author: Hwa Chien Hong
 * Userid: A92072250
 * Description: print the appropriate usage message to the specified stream.
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


void usage( FILE * stream, enum usageMode u, const char * progName ) { 
  if(u == USAGE_SHORT) {
    (void)fprintf(stream, STR_USAGE_SHORT, progName, progName);
  } else { 
    (void) fprintf(stream, STR_USAGE_LONG, progName, MIN_SIZE, MAX_SIZE);
  }
}
