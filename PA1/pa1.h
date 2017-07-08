/* 
 * Filename: pa1.h
 * Author: TODO
 * Userid: TODO
 * Description: Constants and function prototypes used in PA1.
 * Date: TODO
 * Sources of Help: Given.
 */

#ifndef PA1_H
#define PA1_H

/* Local function prototypes for PA1 (written in Assembly or C) */

long isInBounds(long min, long dist, long num);
long isOdd(long num);
void drawZ(long width, long zChar, long borderChar, long fillerChar);
long numOfDigits( long num );
//long printChar( long val );

#define EXPECTED_ARGS 5       /* Includes program name and cmd line args */

/* Indices in argv array */
#define WIDTH_INDEX  1
#define Z_INDEX      2
#define BORDER_INDEX 3
#define FILLER_INDEX 4

#define MIN_WIDTH 3
#define MAX_WIDTH 1001
#define LOWER_CHAR_BOUND 32     /* Lower bound ASCII value inclusive */
#define UPPER_CHAR_BOUND 126    /* Upper bound ASCII value inclusive */

#define BASE 10

#define USAGE "\nUsage: ./pa1 width zChar borderChar fillerChar\n"\
"    width -- an odd integer representing the width of the Z pattern, border\n"\
"             is derived from this, but not included in it. \n"\
"             Must be in the range of [3-1001]\n"\
"    zChar -- the character used to draw the actual Z shape,  must not be\n"\
"             the same as the border or filler characters.\n"\
"             Must be in the range of ASCII [32-126]\n"\
"    borderChar -- character to use to draw the border.\n"\
"                  Must be in the range of ASCII [32-126]\n"\
"    fillerChar -- character used to fill the drawing.\n"\
"                  Must be in the range of ASCII [32-126]\n"

#define INVALID_LONG  "Width %s is not a valid long.\n"
#define INVALID_CHAR  "%s %s is not a valid single character.\n"
#define TOO_BIG_NUM   "Value %s cannot be converted to long in base 10"
#define OUT_OF_BOUNDS "%s %d not in bounds [%d-%d].\n"
#define NUM_EVEN      "Width %ld is not odd.\n"

#define WIDTH       "Width"
#define FILLER_CHAR "Filler character"
#define BORDER_CHAR "Border character"
#define Z_CHAR      "Z character"

#define EXCLUSIVE "The Z character must be different from the filler and "\
                  "border characters.\n"

#endif /* PA1_H */
