/*
 * Filename: testbuildData.c
 * Author: Hwa Chien Hong
 * Userid: cs30xnp
 * Description: 
 * Date: 3/11/17
 * Sources of Help: Tutor, websites links from course
 */ 

#include <string.h>

#include "test.h"
#include "pa4.h"

void testbuildData() {
  printf( "Testing buildData()\n" );
 /*
 struct fileLines fileLines;
  char * src = (char*) malloc(3);
  char * src2 = (char*) malloc(4);
  strcpy(src, "Bat");
  strcpy(src2, "cake");
  
  char ** lines = calloc(1, sizeof(char *));

  *lines = calloc(strlen(src) + 1, sizeof(char));
  strncpy(*lines, src, strlen(src) + 1);

  char ** newlines = realloc(lines, sizeof(char*) * 2);
  newlines[1] = calloc(strlen(src2) + 1, sizeof(char));
  strncpy(newlines[1], src2, strlen(src2));
  
  fileLines.lines = newlines;
  fileLines.numLines = 2;

  //fileLines.numLines = 1;

  struct distinctHead dh = buildData(&fileLines, FLAG_I);
  
  printf("%s\n", ((*(dh.head)).line));
  printf("%s\n", ((dh.head)[1]).line);
*/
 struct fileLines fileLines;
  char * src = (char*) malloc(3);
  char * src2 = (char*) malloc(3);
  strcpy(src, "Bat");
  strcpy(src2, "Bat");
  
  char ** lines = calloc(1, sizeof(char *));

  *lines = calloc(strlen(src) + 1, sizeof(char));
  strncpy(*lines, src, strlen(src) + 1);

  char ** newlines = realloc(lines, sizeof(char*) * 2);
  newlines[1] = calloc(strlen(src2) + 1, sizeof(char));
  strncpy(newlines[1], src2, strlen(src2));
  
  fileLines.lines = newlines;
  fileLines.numLines = 2;

  //fileLines.numLines = 1;

  struct distinctHead dh = buildData(&fileLines, FLAG_I);
  
  printf("%s\n", ((*(dh.head)).line));
  printf("%d\n", dh.numDistinctLines);
  printf("%d\n", (*(dh.head)).count);

  printf( "Finished running tests onbuildData()\n" );
}


int main() {
  testbuildData();

  return 0;
}
