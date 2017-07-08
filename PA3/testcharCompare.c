/*
 * Filename: testcharCompare.c
 * Author: Hwa Chien Hong
 * Userid: cs30xnp
 * Description: Unit test program to test the function charCompare().
 * Date: 2/17/17
 * Sources of Help: Tutor, StackExchange, and website links from class web
 */ 

#include "test.h"    /* For TEST() macro and stdio.h */
#include "pa3.h"     /* For charCompare() function prototype */


/*
 * Unit Test for charCompare.s
 *
 * int charCompare( void const * p1, void const * p2 );
 *
 * Compares the two characters passed in.  Returns -1 if the first character
 * is smaller, 0 if the characters are the same, or +1 if the first character
 * is larger.
 */
void testcharCompare()
{
  char lhs;
  char rhs;

  (void) printf( "Testing charCompare()\n" );

  lhs = 'm';
  rhs = 'j';
  TEST( charCompare( &lhs, &rhs ) == 1 );
  
  /* Test 2 */
  lhs = 'a';
  rhs = 'b';
  TEST( charCompare( &lhs, &rhs ) == -1 );

  /* Test 3 */
  lhs = 'b';
  rhs = 'b';
  TEST( charCompare( &lhs, &rhs ) == 0 );

  /* Test 4 */
  lhs = 'z';
  rhs = 'a';
  TEST( charCompare( &lhs, &rhs ) == 1 );

  /* Test 5 */
  lhs = 'u';
  rhs = 'c';
  TEST( charCompare( &lhs, &rhs ) == 1 );

  /* Test 6 */
  lhs = 'o';
  rhs = 'o';
  TEST( charCompare( &lhs, &rhs ) == 0 );

  /* Test 7*/
  lhs = 'b';
  rhs = 'c';
  TEST( charCompare( &lhs, &rhs ) == -1 );

 /* Test 7*/
  lhs = 'd';
  rhs = 'e';
  TEST( charCompare( &lhs, &rhs ) == -1 );

 /* Test 7*/
  lhs = 'n';
  rhs = 'n';
  TEST( charCompare( &lhs, &rhs ) == 0 );

 /* Test 7*/
  lhs = 'f';
  rhs = 'g';
  TEST( charCompare( &lhs, &rhs ) == -1 );

  (void) printf( "Finished running tests on charCompare()\n" );
}


int main() {
  testcharCompare();

  return 0;
}
