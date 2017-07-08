/*
 * Filename: testisOdd.c
 * Author: Hwa Chien Hong
 * Userid: A92072250
 * Description: Unit test program to test the function isOdd.
 * Date: 1/20/17
 * Sources of Help: TODO
 */ 

#include <limits.h>	/* For LONG_MIN and LONG_MAX */
#include "pa1.h"	/* For isOdd() function prototype */
#include "test.h"	/* For TEST() macro and stdio.h */

/*
 * Unit Test for isOdd.c
 *
 * long isOdd( long num );
 *
 * Checks to see if num is odd or not
 *
 * Returns 1 if number is odd
 * Returns 0 if number is even
 */

void testisOdd( )
{
  (void) printf( "Testing isOdd()\n" );

  /* Test around 0 */
  TEST( isOdd(1) == 1 );
  TEST( isOdd(3) == 1 );
  TEST( isOdd(5) == 1 );
  TEST( isOdd(7) == 1 );

  TEST( isOdd(2) == 0 );
  TEST( isOdd(4) == 0 );
  TEST( isOdd(6) == 0 );
  TEST( isOdd(8) == 0 );
    
  TEST( isOdd(11) == 1 );
  TEST( isOdd(12) == 0 );
  TEST( isOdd(13) == 1 );
  TEST( isOdd(14) == 0 );

  TEST( isOdd(16) == 0 );
  TEST( isOdd(17) == 1 );
  TEST( isOdd(18) == 0 );
  TEST( isOdd(19) == 1 );
  
  
  (void) printf( "Finished running tests on isOdd()\n" );
}

int main( )
{
    testisOdd( );
    return 0;
}
