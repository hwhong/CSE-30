/*
 * Filename: testtoggle.c
 * Author: Hwa Chien Hong
 * Userid: cs30xnp
 * Description: Unit test program to test the function toggle().
 * Date: 2/4/17
 * Sources of Help: Tutor, Course Website Links 
 */ 

#include "test.h"    /* For TEST() macro and stdio.h */
#include "pa2.h"     /* For toggle() function prototype */


/*
 * Unit Test for toggle.s
 *
 * void toggle( unsigned int lightBank[], const unsigned int pattern0, 
 *                                     const unsigned int pattern1);
 * 
 * toggles the lights in the lightBank based on which bit are toggle in the bit
 * patterns passed in.
 */
void testtoggle()
{
  unsigned int lightBank[2];
  int pattern0;
  int pattern1; 

  (void) printf( "Testing toggle()\n" );

  /* test 1 */
  lightBank[0] = 0xCAFEBABE;
  lightBank[1] = 0xDECAFBAD;
  
  pattern0 = 0x420C5E30;
  pattern1 = 0xDEADBEEF;
 
  toggle( lightBank, pattern0, pattern1 );
  TEST( lightBank[0] == 0x88F2E48E && lightBank[1] == 0x0674542 );
  printf("%x + %x \n", lightBank[0], lightBank[1]);

  /* test 2 */
  lightBank[0] = 0xBAE13BAE;
  lightBank[1] = 0x12345678;
  
  pattern0 = 0x00000000;
  pattern1 = 0xFFFFFFFF;
 
  toggle( lightBank, pattern0, pattern1 );
  TEST( lightBank[0] == 0xBAE13BAE && lightBank[1] == 0xEDCBA987 );
  printf("%x + %x \n", lightBank[0], lightBank[1]);

  /* test 3 */
  lightBank[0] = 0x10293847;
  lightBank[1] = 0xC0DEBABE;
  
  pattern0 = 0x77777777;
  pattern1 = 0x10293847;
 
  toggle( lightBank, pattern0, pattern1 );
  TEST( lightBank[0] == 0x675E4F30 && lightBank[1] == 0xD0F782F9 );
  printf("%x + %x \n", lightBank[0], lightBank[1]);

  /* test 4 */
  lightBank[0] = 0x13579000;
  lightBank[1] = 0x08642111;
  
  pattern0 = 0xDEADBEEF;
  pattern1 = 0xBEEF9999;
 
  toggle( lightBank, pattern0, pattern1 );
  TEST( lightBank[0] == 0xCDFA2EEF && lightBank[1] == 0xB68BB888 );
  printf("%x + %x \n", lightBank[0], lightBank[1]);

  /* test 5 */
  lightBank[0] = 0xFFFFFFFF;
  lightBank[1] = 0x9F9F9F9F;;
  
  pattern0 = 0xABCDEF12;
  pattern1 = 0x34567891;
 
  toggle( lightBank, pattern0, pattern1 );
  TEST( lightBank[0] == 0x543210ED && lightBank[1] == 0xABC9E70E );
  printf("%x + %x \n", lightBank[0], lightBank[1]);


  printf( "Finished running tests on toggle()\n" );
}


int main() {
  testtoggle();

  return 0;
}
