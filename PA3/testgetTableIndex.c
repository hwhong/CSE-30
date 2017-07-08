/*
 * Filename: testgetTableIndex.c
 * Author: Hwa Chien Hong
 * Userid: cs30xnp
 * Description: Unit test program to test the function getTableIndex().
 * Date: 2/17/17
 * Sources of Help: Tutor, StackExchange, and website links from class web
 */ 

#include "test.h"    /* For TEST() macro and stdio.h */
#include "pa3.h"     /* For getTableIndex() function prototype */
#include <stdio.h>
#include <string.h>

/*
 * Unit Test for getTableIndex.s
 *
 * int getTableIndex( char const * ucSorted, size_t tableSize );
 *
 * function calculates the index of the ucSorted String in the hashtable of size
 * tablesize
 */
void testgetTableIndex()
{ 
  char const * word;
  
  (void) printf( "Testing getTableIndex()\n" );

  word = "hash";
 
  TEST( getTableIndex( word, 10 ) == 5 );
  //printf("Correct ans is %d \n", getTableIndex(word, 10) );

  //------------------
  word = "cat";
 
  TEST( getTableIndex( word, 100 ) == 19 );
  //printf("Correct ans is %d \n", getTableIndex(word,100) );

  //------------------
  word = "cse";
 
  TEST( getTableIndex( word, 10 ) == 0 );
  //printf("Correct ans is %d \n", getTableIndex(word, 10) );

  //------------------
  word = "problemset";
 
  TEST( getTableIndex( word, 25 ) == 21 );
  //printf("Correct ans is %d \n", getTableIndex(word, 25) );

  //------------------
  word = "apple";
 
  TEST( getTableIndex( word, 98 ) == 79 );
  //printf("Correct ans is %d \n", getTableIndex(word, 98) );
  
  //-----------------
  word = "AAHHRS";

  TEST( getTableIndex( word, DEFAULT_SIZE ) == 28 );
  printf("Correct ans is %d \n", getTableIndex(word, DEFAULT_SIZE) );
  
  (void) printf( "Finished running tests on getTableIndex()\n" );
}


int main() {
  testgetTableIndex();

  return 0;
}
