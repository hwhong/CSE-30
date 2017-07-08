/*
 * Filename: testupperCaseSortString.c
 * Author: Hwa Chien Hong
 * Userid: cs30xnp
 * Description: Unit test program to test the function upperCaseSortString().
 * Date: 2/17/17
 * Sources of Help: Tutor, Course Website Links 
 */ 

#include "test.h"    /* For TEST() macro and stdio.h */
#include "pa3.h"     /* For upperCaseSortString() function prototype */
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

/*
 * Unit Test for upperCaseSortString.s
 *
 * void upperCaseSortString( char const * src, int n, char * dest );
 * 
 * the function takes the src string and will store all all capitalized copy in
 * dest
 */
void testupperCaseSortString()
{
  char const * src = "testing";
  int n = strlen(src);
  char * dest1 = (char *) malloc(n + 1);
  
  /* Test 1 */ 
  char * correct = "EGINSTT";
  upperCaseSortString(src, n, dest1);
  TEST( strcmp(correct, dest1) == 0 );
  //printf("Result becomes %s \n", dest1);
 
  /* Test 2 */ 
  src = "nba";
  n = strlen(src);
  correct = "ABN";
  char * dest2 = (char *) malloc(n + 1);
  upperCaseSortString(src, n, dest2);
  TEST( strcmp(correct, dest2) == 0 );
  //printf("Result becomes %s \n", dest2);
 
  /* Test 3 */ 
  src = "";
  n = strlen(src);
  correct = "";
  char * dest3 = (char *) malloc(n + 1);
  upperCaseSortString(src, n, dest3);
  TEST( strcmp(correct, dest3) == 0 );
  //printf("Result becomes %s \n", dest3);
 
  /* Test 4 */ 
  src = "pokemon";
  n = strlen(src);
  correct = "EKMNOOP";
  char * dest4 = (char *) malloc(n + 1);
  upperCaseSortString(src, n, dest4);
  TEST( strcmp(correct, dest4) == 0 );
  //printf("Result becomes %s \n", dest4);
 
  /* Test 5 */
  src = "computerscienceandengineering";
  n = strlen(src);
  correct = "ACCCDEEEEEEGGIIIMNNNNNOPRRSTU";
  char * dest5 = (char *) malloc(n + 1);
  upperCaseSortString(src, n, dest5);
  TEST( strcmp(correct, dest5) == 0 );
  //printf("Result becomes %s \n", dest5);
 
  /* Test 6 */
  src = "ifinishedtheassignmentpartone";
  n = strlen(src);
  correct = "AADEEEEFGHHIIIIMNNNNOPRSSSTTT";
  char * dest6 = (char *) malloc(n + 1);
  upperCaseSortString(src, n, dest6);
  TEST( strcmp(correct, dest6) == 0 );
  //printf("Result becomes %s \n", dest5);
 
  printf( "Finished running tests on upperCaseSortString()\n" );
}

int main() {
  testupperCaseSortString();

  return 0;
}
