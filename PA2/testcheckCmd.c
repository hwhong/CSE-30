/*
 * Filename: testcheckCmd.c
 * Author: Hwa Chien Hong
 * Userid: cs30xnp
 * Description: Unit test program to test the function checkCmd().
 * Date: 2/4/17
 * Sources of Help: Tutor, Course Website Links 
 */ 

#include "test.h"    /* For TEST() macro and stdio.h */
#include "pa2.h"     /* For checkCmd() function prototype */

/*
 * Unit Test for checkCmd.s
 *
 * void checkCmd( const char * const cmdString, const char * const commands[] );
 * 
 * the function checks to see if the cmdString is in the commands array
 */
void testcheckCmd()
{
  /* Test 1 */
  const char * const commands[] = { COMMANDS, NULL};
  
  /* Testing the commands array */ 
  TEST( checkCmd(SET_CMD, commands) == 0);
  TEST( checkCmd(CLEAR_CMD, commands) == 1);
  TEST( checkCmd(TOGGLE_CMD, commands) == 2);
  TEST( checkCmd(SHIFT_CMD, commands) == 3);
  TEST( checkCmd(ROTATE_CMD, commands) == 4);
  TEST( checkCmd(RIPPLE_CMD, commands) == 5);
  TEST( checkCmd(HELP_CMD, commands) == 6);
  TEST( checkCmd(QUIT_CMD, commands) == 7);
 
  /* Testing the -1 return value */
  TEST( checkCmd(inArr, commands) == -1);
  TEST( checkCmd(notInArr, commands) == -1);
  TEST( checkCmd(COOL_STRING, commands) == -1);
  TEST( checkCmd(LITTLE_STRING, commands) == -1);
  TEST( checkCmd(BIG_STRING, commands) == -1);
 
  /* Testing the null pointers */ 
  const char * const null[] = {NULL};
  const char * const NULL_POINTER = NULL;

  TEST( checkCmd(NULL_POINTER, commands) == -1);
  TEST( checkCmd(BIG_STRING, null) == -1);

  printf( "Finished running tests on checkCmd()\n" );
}


int main() {
  testcheckCmd();

  return 0;
}
