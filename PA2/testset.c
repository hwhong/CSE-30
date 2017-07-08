/*
 * Filename: testset.c
 * Author: Hwa Chien Hong
 * Userid: cs30xnp
 * Description: Unit test program to test the function set().
 * Date: 2/4/17
 * Sources of Help: Tutor, Course Website Links 
 */ 

#include "test.h"    /* For TEST() macro and stdio.h */
#include "pa2.h"     /* For set() function prototype */


/*
 * Unit Test for set.s
 *
 * void set( unsigned int lightBank[], const unsigned int pattern0, 
 *                                     const unsigned int pattern1);
 * 
 * sets the lights in the lightBank based on which bit are set in the bit
 * patterns passed in.
 */
void testset()
{
  unsigned int lightBank[2];
  int pattern0;
  int pattern1; 

  (void) printf( "Testing set()\n" );

  /* test 1 */
  lightBank[0] = 0x00100001;
  lightBank[1] = 0x1F00F001;
  
  pattern0 = 0x420C5E30;
  pattern1 = 0xF001F008;
 
  set( lightBank, pattern0, pattern1 );
  TEST( lightBank[0] == 0x421C5E31 && lightBank[1] == 0xFF01F009 );
  //printf("%x + %x \n", lightBank[0], lightBank[1]);

  /* test 2 */ 
  lightBank[0] = 0x00000000;
  lightBank[1] = 0x00000000;
  
  pattern0 = 0x420C5E30;
  pattern1 = 0xF001F008;
 
  set( lightBank, pattern0, pattern1 );
  TEST( lightBank[0] == 0x420C5E30 && lightBank[1] == 0xF001F008 );
  //printf("%x + %x \n", lightBank[0], lightBank[1]);

  /* test 3 */ 
  lightBank[0] = 0x10010001;
  lightBank[1] = 0x30030003;
  
  pattern0 = 0xFFFFFFFF;
  pattern1 = 0x30030003;
 
  set( lightBank, pattern0, pattern1 );
  TEST( lightBank[0] == 0xFFFFFFFF && lightBank[1] == 0x30030003 );
  //printf("%x + %x \n", lightBank[0], lightBank[1]);

  printf( "Finished running tests on set()\n" );
}


int main() {
  testset();

  return 0;
}
