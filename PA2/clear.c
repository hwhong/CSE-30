/*
 * Filename: clear .c
 * Author: Hwa Chien Hong
 * Userid: A92072250
 * Description: a function that clears the lights in the lightBank based on
 * which bits are set in the bit patterns passed in. 
 * Date: 2/10/17
 * Sources of Help: website links on the course website, Tutors 
 */ 

#include "pa2.h"	/* For function prototype */
#include <stdio.h> 
#include <stdlib.h>
#include <errno.h> 
#include <strings.h>

void clear ( unsigned int lightBank[], const unsigned int pattern0, 
const unsigned int pattern1 ) {
  
  int bank0 = lightBank[0];
  int bank1 = lightBank[1]; 

  // first XOR 
  int temp0 = bank0^pattern0; 
  int temp1 = bank1^pattern1;

  // then AND 
  int fin0 = temp0 & bank0;
  int fin1 = temp1 & bank1;

  lightBank[0] = fin0;
  lightBank[1] = fin1; 
}
