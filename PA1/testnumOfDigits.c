/*
 * Filename: testnumOfDigits.c
 * Author: Hwa Chien Hong
 * Userid: A92072250
 * Description: Unit test program to test the function numOfDigits.
 * Date: 1/20/17
 * Sources of Help: TODO
 */ 

#include <limits.h>	/* For LONG_MIN and LONG_MAX */
#include "pa1.h"	/* For numOfDigits() function prototype */
#include "test.h"	/* For TEST() macro and stdio.h */

/*
 * Unit Test for numOfDigits.c
 *
 * long numOfDigits( long num );
 *
 * Counts the number of digits in a given number
 *
 * Returns the number of digits in num
 * Returns -1 if number is negative to start with 
 */

void testnumOfDigits( )
{
  (void) printf( "Testing numOfDigits()\n" );

  /* Test around 0 */
  TEST( numOfDigits(1) == 1 );
  TEST( numOfDigits(3) == 1 );
  TEST( numOfDigits(5) == 1 );
  TEST( numOfDigits(0) == 1 );

  TEST( numOfDigits(10) == 2 );
  TEST( numOfDigits(15) == 2 );
  TEST( numOfDigits(17) == 2 );
  TEST( numOfDigits(20) == 2 );
    
  TEST( numOfDigits(111) == 3 );
  TEST( numOfDigits(122) == 3 );
  TEST( numOfDigits(134) == 3 );
  TEST( numOfDigits(145) == 3 );

  TEST( numOfDigits(100000) == 6 );
  TEST( numOfDigits(1234) == 4 );
  TEST( numOfDigits(10101010) == 8 );
  TEST( numOfDigits(1234567) == 7 );
  
  TEST( numOfDigits(-9) == -1 );
  TEST( numOfDigits(-19) == -1 );
  TEST( numOfDigits(-89) == -1 );
  TEST( numOfDigits(-99) == -1 );
  
  TEST( numOfDigits(1029384756) == 10 );
  TEST( numOfDigits(0) == 1 );
  TEST( numOfDigits(-309) == -1 );
  TEST( numOfDigits(9) == 1 );
  
  (void) printf( "Finished running tests on numOfDigits()\n" );
}

int main( )
{
    testnumOfDigits( );
    return 0;
}
