/*
 * Filename: testshift.c
 * Author: Hwa Chien Hong 
 * Userid: cs30xnp
 * Description: Unit test program to test the function shift().
 * Date: 2/4/17
 * Sources of Help: Tutor, Website
 */ 

#include "test.h"    /* For TEST() macro and stdio.h */
#include "pa2.h"     /* For shift() function prototype */


/*
 * Unit Test for shift.s
 *
 * void shift( unsigned int lightBank[], const int shiftCnt );
 * 
 * Shifts the current light pattern in the lightBank by shiftCnt places.
 * If shiftCnt is positive, shift left.  If shiftCnt is negative, shift right.
 */
void testshift()
{
  unsigned int lightBank[2];
  int shiftCnt;

  (void) printf( "Testing shift()\n" );


  /* Shift left by 1 bit */
  lightBank[0] = 0xCAFEBABE;
  lightBank[1] = 0xDECAFBAD;
  shiftCnt = 1;
 
  shift( lightBank, shiftCnt );
  TEST( lightBank[0] == 0x95FD757D && lightBank[1] == 0xBD95F75A );
  //printf("%x + %x \n", lightBank[0], lightBank[1]);

  /* Shift right by 1 bit */
  lightBank[0] = 0xCAFEBABE;
  lightBank[1] = 0xDECAFBAD;
  shiftCnt = -1;

  shift( lightBank, shiftCnt );
  TEST( lightBank[0] == 0x657F5D5F && lightBank[1] == 0x6F657DD6 );
  //printf("%x + %x \n", lightBank[0], lightBank[1]);

  lightBank[0] = 0xCAFEBABE;
  lightBank[1] = 0xDECAFBAD;
  shiftCnt = 0;

  shift( lightBank, shiftCnt );
  TEST( lightBank[0] == 0xCAFEBABE && lightBank[1] == 0xDECAFBAD );
  //printf("%x + %x \n", lightBank[0], lightBank[1]);

  lightBank[0] = 0xCAFEBABE;
  lightBank[1] = 0xDECAFBAD;
  shiftCnt = -13;

  shift( lightBank, shiftCnt );
  TEST( lightBank[0] == 0x000657F5 && lightBank[1] == 0xD5F6F657 );
  printf("%x + %x \n", lightBank[0], lightBank[1]);

  lightBank[0] = 0xCAFEBABE;
  lightBank[1] = 0xDECAFBAD;
  shiftCnt = 28;

  shift( lightBank, shiftCnt );
  TEST( lightBank[0] == 0xEDECAFBA && lightBank[1] == 0xD0000000 );
  //printf("%x + %x \n", lightBank[0], lightBank[1]);

  lightBank[0] = 0x12345678;
  lightBank[1] = 0x87654321;
  shiftCnt = -8;

  shift( lightBank, shiftCnt );
  TEST( lightBank[0] == 0x00123456 && lightBank[1] == 0x78876543 );
  printf("%x + %x \n", lightBank[0], lightBank[1]);

  lightBank[0] = 0x12345678;
  lightBank[1] = 0x87654321;
  shiftCnt = 8;

  shift( lightBank, shiftCnt );
  TEST( lightBank[0] == 0x34567887 && lightBank[1] == 0x65432100 );
  //printf("%x + %x \n", lightBank[0], lightBank[1]);

  lightBank[0] = 0xBAE13BAE;
  lightBank[1] = 0x12367891;
  shiftCnt = 25;

  shift( lightBank, shiftCnt );
  TEST( lightBank[0] == 0x5C246CF1 && lightBank[1] == 0x22000000 );
  //printf("%x + %x \n", lightBank[0], lightBank[1]);

  printf( "Finished running tests on shift()\n" );
}


int main() {
  testshift();

  return 0;
}
