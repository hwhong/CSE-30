/*
 * Filename: testisInBounds.c
 * Author: TODO
 * Userid: TODO
 * Description: Unit test program to test the function isInBounds.
 * Date: TODO
 * Sources of Help: TODO
 */ 

#include <limits.h>	/* For LONG_MIN and LONG_MAX */
#include "pa1.h"	/* For isInBounds() function prototype */
#include "test.h"	/* For TEST() macro and stdio.h */

/*
 * Unit Test for isInBounds.c
 *
 * long isInBounds( long min, long dist, long num );
 *
 * Checks to see if num is within the bounds of min and min + dist.
 *
 * Returns -1 if dist is less than zero.
 * Returns 1 if num is between min and min + dist (inclusive).
 * Returns 0 otherwise.
 */

void testisInBounds( )
{
  (void) printf( "Testing isInBounds()\n" );

  TEST( isInBounds( 0, 0, 1 ) == 0 );
  TEST( isInBounds( 0, 0, 0 ) == 1 );
  TEST( isInBounds( 0, 0, -1 ) == 0 );
  TEST( isInBounds( 3, 2, 4 ) == 1);
  TEST( isInBounds( 3, 2, 6 ) == 0);

  TEST( isInBounds( -1, 1, -2 ) == 0 );
  TEST( isInBounds( -1, 1, -1 ) == 1 );
  TEST( isInBounds( -1, 1, 0 ) == 1 );
  TEST( isInBounds( -1, 1, 1 ) == 0 );
  TEST( isInBounds( -1, 1, 2 ) == 0 );
  
  // Tests for when dist is negative 
  TEST( isInBounds( -1, -2, -2 ) == -1 );
  TEST( isInBounds( -1, -10, -1 ) == -1 );
  TEST( isInBounds( -1, -5, 0 ) == -1 );
  TEST( isInBounds( -1, -11, 1 ) == -1 );
  TEST( isInBounds( -1, -2, 2 ) == -1 );
   
  TEST( isInBounds( 5, 6, 7 ) == 1 );
  TEST( isInBounds( 5, 6, 11 ) == 1 );
  TEST( isInBounds( -10, 10, -4 ) == 1 );
  TEST( isInBounds( -1, 10, 9 ) == 1 );
  TEST( isInBounds( -50, 100, 50 ) == 1 );
  



  (void) printf( "Finished running tests on isInBounds()\n" );
}

int main( )
{
    testisInBounds( );
    return 0;
}
