/*
 * Filename: testprintChar.c
 * Author: Hwa Chien Hong
 * Userid: A92072250
 * Description: Unit test program to test the function printChar.
 * Date: 1/20/17
 * Sources of Help: TODO
 */ 

#include <limits.h>	/* For LONG_MIN and LONG_MAX */
#include "pa1.h"	/* For printChar() function prototype */
#include "test.h"	/* For TEST() macro and stdio.h */

/*
 * Unit Test for printChar.c
 *
 * long printChar( long val );
 *
 */

void testprintChar( )
{
  (void) printf( "Testing printChar()\n" );
   

 TEST( printChar(96) );
 TEST( printChar(97) );

 TEST( printChar(65) );
 TEST( printChar(98) );
 TEST( printChar(100) );
 TEST( printChar(69) );
 TEST( printChar(70) );
 TEST( printChar(79) );





  (void) printf( "Finished running tests on printChar()\n" );
}

int main( )
{
    testprintChar( );
    return 0;
}
