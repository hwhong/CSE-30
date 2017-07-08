/*
 * Filename: testfilenameCompare.c
 * Author: Hwa Chien Hong
 * Userid: cs30xnp
 * Description: Unit test program to test the assembly function filenameCompare.
 * Date: 3/3/17
 * Sources of Help: Tutor, Website links from website
 */ 

#include <string.h>

#include "test.h"
#include "pa4.h"


/*
 * Unit Test for filenameCompare.s
 *
 * 
 * int filenameCompare( const void * p1, const void * p2 )
 * 
 * Compares two file names passed in for sorting purposes. 
 * Returns 0 if the file names are the same, -1 if the first name
 * is smaller, or +1 if the first name is larger.
 */

void testfilenameCompare() {
  printf( "Testing filenameCompare()\n" );
  
  //----------------TEST 1----------------
  struct fileInfo f1; 
  struct fileInfo f2; 
  
  f1.filename = "helloWorld";
  f2.filename = "jelloWorld";
  TEST( filenameCompare( &f1, &f2 ) < 0 );
  
  //----------------TEST 2----------------
  struct fileInfo f3; 
  struct fileInfo f4; 
  
  f3.filename = "helloWorld";
  f4.filename = "helloWorld";
  TEST( filenameCompare( &f3, &f4 ) == 0 );

  //----------------TEST 3----------------
  struct fileInfo f5; 
  struct fileInfo f6; 
  
  f5.filename = "cse";
  f6.filename = "esc";
  TEST( filenameCompare( &f5, &f6 ) < 0 );
  
  //----------------TEST 4----------------
  struct fileInfo f7; 
  struct fileInfo f8; 
  
  f7.filename = "z";
  f8.filename = "a";
  TEST( filenameCompare( &f7, &f8 ) == 1 );

  //----------------TEST 5----------------
  struct fileInfo f9; 
  struct fileInfo f10; 
  
  f9.filename = "World";
  f10.filename = "World";
  TEST( filenameCompare( &f9, &f10 ) == 0 );

  printf( "Finished running tests on filenameCompare()\n" );
}


int main() {
  testfilenameCompare();

  return 0;
}
