/*
 * Filename: checkCmd.c
 * Author: Hwa Chien Hong
 * Userid: A92072250
 * Description: a function that checks to see if cmdString is in the commans 
 *              array. 
 * Date: 2/3/17
 * Sources of Help: website links on the course website, Tutors 
 */ 

#include "pa2.h"	/* For function prototype */
#include <stdio.h> 
#include <stdlib.h>
#include <errno.h> 
#include <strings.h>

int checkCmd( const char * const cmdString, const char * const commands[] ) {
  int i;
  // if either pointers are null, then -1 is returned 
  if (cmdString == NULL || commands == NULL) return -1; 

  //for(int i = 0; i < commands.length; i++) {
  //    if (compares(cmdString, commands[i], cmdStringlength)==0) { 
  //        return i;
  //    }
  //}
  //return -1; 
   
  // the commands array contains a sentinel null pointer at the end 
  
  // traverse through the char array, and look for the same string 
  for( i = 0; commands[i]!= '\0'; ++i) {
      // strncmp returns 0, if both string are the same 
      if(strncmp(cmdString, commands[i], BUFSIZ) == 0) return i;
  }

  return -1;
}
