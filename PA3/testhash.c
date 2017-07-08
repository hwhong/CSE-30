/*
 * Filename: testhash.c
 * Author: Hwa Chien Hong
 * Userid: cs30xnp
 * Description: Unit test program to test the function hash().
 * Date: 2/17/17
 * Sources of Help: Tutor, StackExchange, and website links from class web
 */ 

#include "test.h"    /* For TEST() macro and stdio.h */
#include "pa3.h"     /* For hash() function prototype */
#include <stdio.h>
#include <string.h>

/*
 * Unit Test for hash.s
 *
 * int hash( char const * str );
 *
 * function creates an integer hash key from str by using an algorithm similar
 * to Java's String.hashCode()
 */
void testhash()
{ 
  char const * word;
  
  (void) printf( "Testing hash()\n" );

  word = "hash";
 
  TEST( hash( word ) == 26020835 );
  //printf("hash is %d \n", hash(word) );

  //------------------------------
  word = "cat";

  TEST( hash( word ) == 696419 );
  //printf("cat is %d \n", hash(word) );
  
  //------------------------------
  word = "cse";

  TEST( hash( word ) == 697070 );
  //printf("cse is %d \n", hash(word));

  //-----------------------------
  word = "problemset";

  TEST( hash( word ) == -1570033796 );
  //printf("problemset is %d \n", hash(word) );

  //-----------------------------
  word = "apple";

  TEST( hash( word ) == 950407705 );
  //printf("apple is %d \n", hash(word) );

  (void) printf( "Finished running tests on hash()\n" );
}


int main() {
  testhash();

  return 0;
}
