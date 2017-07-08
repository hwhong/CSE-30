/*
 * Filename: testtimeCompare.c
 * Author: Hwa Chien Hong
 * Userid: cs30xnp
 * Description: Unit test program to test the assembly function timeCompare.
 * Date: 3/3/17
 * Sources of Help: Tutor, websites links from course
 */ 

#include <string.h>

#include "test.h"
#include "pa4.h"


/*
 * Unit Test for timeCompare.s
 *
 * 
 * int timeCompare( const void * p1, const void * p2 )
 * 
 * Compares two file names passed in for sorting purposes. 
 * Returns 0 if the mod times  are the same, -1 if the first time
 * is older, or +1 if the first mod is newer.
 */

void testtimeCompare() {
  printf( "Testing timeCompare()\n" );

  //----------TEST 1-----------
  struct fileInfo f1; 
  struct fileInfo f2; 
  f1.statInformation.st_mtime = 1;
  f2.statInformation.st_mtime = 1;
  
  TEST( timeCompare( &f1, &f2 ) == 0 );

  //----------TEST 2-----------
  struct fileInfo f3; 
  struct fileInfo f4; 

  f3.statInformation.st_mtime = 1;
  f4.statInformation.st_mtime = 2;
  
  //(void)fprintf(stderr, "%d \n", f3.statInformation.st_mtime);
  //(void)fprintf(stderr, "%d \n", f4. statInformation.st_mtime);

  TEST( timeCompare( &f3, &f4 ) == -1 );
  //(void)fprintf(stderr, "%d \n", timeCompare(&f3, &f4));
  
  //----------TEST 3-----------
  struct fileInfo f5; 
  struct fileInfo f6; 
  f5.statInformation.st_mtime = 2;
  f6.statInformation.st_mtime = 1;
  
  TEST( timeCompare( &f5, &f6 ) == 1 );

  //----------TEST 4-----------
  struct fileInfo f7; 
  struct fileInfo f8; 
  f7.statInformation.st_mtime = 100;
  f8.statInformation.st_mtime = 95;
  
  TEST( timeCompare( &f7, &f8 ) == 1 );

  //----------TEST 5-----------
  struct fileInfo f9; 
  struct fileInfo f10; 
  f9.statInformation.st_mtime = 6;
  f10.statInformation.st_mtime = 6;
  
  TEST( timeCompare( &f9, &f10 ) == 0 );

  printf( "Finished running tests ontimeCompare()\n" );
}


int main() {
  testtimeCompare();

  return 0;
}
