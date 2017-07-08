/*
 * Filename: testclear.c
 * Author: Hwa Chien Hong
 * Userid: cs30xnp
 * Description: Unit test program to test the function clear().
 * Date: 2/4/17
 * Sources of Help: Tutor, Course Website Links 
 */ 

#include "test.h"    /* For TEST() macro and stdio.h */
#include "pa2.h"     /* For clear() function prototype */

/*
 * Unit Test for clear.s
 *
 * void clear( unsigned int lightBank[], const unsigned int pattern0,
 *             const unsigned int pattern1 );
 * 
 * the function checks to see if the cmdString is in the commands array
 */
void testclear( ) {
  unsigned int lightBank[] = { 0xFF00FF00, 0xAAAAAAAA };
  unsigned int pattern0 = 0xFF000000;
  unsigned int pattern1 = 0x88888888;

  /* Test 1 */ 
  clear( lightBank, pattern0, pattern1 );
  TEST( lightBank[0] == 0x0000FF00 && lightBank[1] == 0x22222222 );
  printf("%x + %x \n", lightBank[0], lightBank[1]);

  unsigned int lightBank2[] = { 0xFFFFFFFF, 0x00000000 };
  unsigned int pattern20 = 0x11111111;
  unsigned int pattern21 = 0xFFFFFFFF;

  /* Test 2 */ 
  clear( lightBank2, pattern20, pattern21 );
  TEST( lightBank2[0] == 0xEEEEEEEE && lightBank2[1] == 0x00000000 );
  printf("%x + %x \n", lightBank2[0], lightBank2[1]);

  unsigned int lightBank3[] = { 0x92929292, 0xFFFFFFFF };
  unsigned int pattern30 = 0x11111111;
  unsigned int pattern31 = 0x0F0F0F0F;

  /* Test 3 */ 
  clear( lightBank3, pattern30, pattern31 );
  TEST( lightBank3[0] == 0x82828282 && lightBank3[1] == 0xF0F0F0F0 );
  printf("%x + %x \n", lightBank3[0], lightBank3[1]);

  unsigned int lightBank4[] = { 0x11111111, 0x22222222 };
  unsigned int pattern40 = 0x11111111;
  unsigned int pattern41 = 0x22222222;

  /* Test 4 */ 
  clear( lightBank4, pattern40, pattern41 );
  TEST( lightBank4[0] == 0x00000000 && lightBank4[1] == 0x00000000 );
  printf("%x + %x \n", lightBank4[0], lightBank4[1]);

  unsigned int lightBank5[] = { 0xC2C2C2C2, 0xFFFFFFFF };
  unsigned int pattern50 = 0x12121212;
  unsigned int pattern51 = 0x11111111;

  /* Test 5 */ 
  clear( lightBank5, pattern50, pattern51 );
  TEST( lightBank5[0] == 0xC0C0C0C0 && lightBank5[1] == 0xEEEEEEEE );
  printf("%x + %x \n", lightBank5[0], lightBank5[1]);


 
  printf( "Finished running tests on clear()\n" );
}


int main() {
  testclear();

  return 0;
}
