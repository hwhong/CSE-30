/*
 * Filename: testloadDict.c
 * Author: Hwa Chien Hong
 * Userid: cs30xnp
 * Description: Unit test program to test the function loadDict().
 * Date: 2/17/17
 * Sources of Help: Tutor, StackExchange, and website links from class web
 */ 

#include "test.h"    /* For TEST() macro and stdio.h */
#include "pa3.h"     /* For loadDict() function prototype */
#include <string.h>
#include <stdlib.h>

/*
 * Unit Test for loadDict.s
 *
 * int loadDict( void const * p1, void const * p2 );
 *
 * Compares the two characters passed in.  Returns -1 if the first character
 * is smaller, 0 if the characters are the same, or +1 if the first character
 * is larger.
 */
void testloadDict()
{
  (void) printf( "Testing loadDict()\n" );
  
   struct HashTable table;
   table.entryPtr = calloc(DEFAULT_SIZE, sizeof(struct TableEntry));
   
   loadDict(DEFAULT_DICT_FILENAME, &table);
   //loadDict("tempDictSmall", &table);
   //struct HashTable * point = &table;
   //findAnagram(point);
  
  (void) printf( "Finished running tests on loadDict()\n" );
}


int main() {
  testloadDict();

  return 0;
}
