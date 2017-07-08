/*
 * Filename: testinitAnagram.c
 * Author: Hwa Chien Hong
 * Userid: cs30xnp
 * Description: Unit test program to test the function initAnagram().
 * Date: 2/17/17
 * Sources of Help: Tutor, StackExchange, and website links from class web
 */ 

#include "test.h"    /* For TEST() macro and stdio.h */
#include "pa3.h"     /* For initAnagram() function prototype */
#include <string.h>


/*
 * Unit Test for initAnagram.s
 *
 * int initAnagram( void const * p1, void const * p2 );
 *
 * Compares the two characters passed in.  Returns -1 if the first character
 * is smaller, 0 if the characters are the same, or +1 if the first character
 * is larger.
 */
void testinitAnagram()
{
  

  (void) printf( "Testing initAnagram()\n" );

  struct Anagram anagram;

  initAnagram("test", &anagram);
  TEST( anagram.numWords == 1);
  TEST( strcmp(anagram.sortedWord, "ESTT") == 0);
  TEST( strcmp((anagram.words)[0], "test" ) == 0);

  (void) printf( "Finished running tests on initAnagram()\n" );
}


int main() {
  testinitAnagram();

  return 0;
}
