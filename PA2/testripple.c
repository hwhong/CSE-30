/*
 * Filename: testripple.c
 * Author: Hwa Chien Hong
 * Userid: cs30xnp
 * Description: Unit test program to test the function ripple().
 * Date: 2/4/17
 * Sources of Help: Tutor, Course Website Links 
 */ 

#include "test.h"    /* For TEST() macro and stdio.h */
#include "pa2.h"     /* For ripple() function prototype */


/*
 * Unit Test for ripple.s
 *
 * void ripple( unsigned int lightBank[], const int rippleCnt )'
 * 
 * ripples the current light patterns in the light banks by rippleCnt places 
 */
void testripple()
{
  unsigned int lightBank[2];
   
  (void) printf( "Testing ripple()\n" );

  /* test 1 */
  lightBank[0] = 0x90000000;
  lightBank[1] = 0x90000000;
  
  ripple( lightBank, 10 );
  //TEST( lightBank[0] == 0xDD6E57F5 && lightBank[1] == 0xD5F6F657 );
  //printf("%x + %x \n", lightBank[0], lightBank[1]);

  /* test 2 */
  lightBank[0] = 0xCAFEBABE;
  lightBank[1] = 0xDECAFBAD;
  
  ripple( lightBank, 28 );
  //TEST( lightBank[0] == 0xEDECAFBA && lightBank[1] == 0xDCAFEBAB );
  //printf("%x + %x \n", lightBank[0], lightBank[1]);

  /* test 3 */
  lightBank[0] = 0x00000000;
  lightBank[1] = 0xFFFFFFFF;
  
  ripple( lightBank, -13 );
  //TEST( lightBank[0] == 0xFFF80000 && lightBank[1] == 0x0007FFFF );
  //printf("%x + %x \n", lightBank[0], lightBank[1]);

  /* test 4 */
  lightBank[0] = 0x12345678;
  lightBank[1] = 0x23456789;
  
  ripple( lightBank, 0 );
  //TEST( lightBank[0] == 0x12345678 && lightBank[1] == 0x23456789 );
  //printf("%x + %x \n", lightBank[0], lightBank[1]);

  // more tests 

  /* test 5 */
  lightBank[0] = 0x12345678;
  lightBank[1] = 0x23456789;
  
  ripple( lightBank, 4 );
  //TEST( lightBank[0] == 0x23456782 && lightBank[1] == 0x34567891 );
  //printf("%x + %x \n", lightBank[0], lightBank[1]);

  /* test 6 */
  lightBank[0] = 0x12345678;
  lightBank[1] = 0x23456789;
  
  ripple( lightBank, -4 );
  //TEST( lightBank[0] == 0x91234567 && lightBank[1] == 0x82345678 );
  //printf("%x + %x \n", lightBank[0], lightBank[1]);
 
  /* test 7 */
  lightBank[0] = 0xAB23CD56;
  lightBank[1] = 0x37892035;
  
  ripple( lightBank, -30 );
  //TEST( lightBank[0] == 0xDE2480D6 && lightBank[1] == 0xAC8F3558 );
  //printf("%x + %x \n", lightBank[0], lightBank[1]);


  printf( "Finished running tests on ripple()\n" );
}


int main() {
  testripple();

  return 0;
}
