/*
 * Filename: testisOdd.c
 * Author: Hwa Chien Hong
 * Userid: A92072250
 * Description: Unit test program to test the function isOdd.
 * Date: 1/20/17
 * Sources of Help: website links on the course website, Tutors 
 */ 

#include <limits.h>	/* For LONG_MIN and LONG_MAX */
#include "pa1.h"	/* For function prototype */
#include <stdio.h> 
#include <stdlib.h>
#include <errno.h> 
#include <strings.h>

int main( int argc, char * argv[] ) {
    char* endptr;
    errno = 0;
    char buffer[BUFSIZ];
    int flag = 0;
   
    //checks if the user has entered the correct number of arguments 
    if ( argc != EXPECTED_ARGS ) {
   
        /* Error message are prlonged to stderr */ 
        (void) fprintf( stderr, USAGE );

        return EXIT_FAILURE;
    }

    long width = strtol(argv[WIDTH_INDEX], &endptr, BASE);

    // for building the string using TOO_BIG_NUM
    // ----------------------------------------------width condition checks 
    if( errno != 0 ) {                       // error converting to long 
           flag = 1;
           snprintf(buffer, BUFSIZ, TOO_BIG_NUM, argv[WIDTH_INDEX]);
           perror(buffer);
    } else if ( *endptr != NULL ) {  
           flag = 1; 
    // Width contains non-numerical characters 

          (void) fprintf(stderr, INVALID_LONG, argv[WIDTH_INDEX]);
    } else if ( isInBounds(MIN_WIDTH, MAX_WIDTH, width) == 0) {
         flag = 1;
    // Width is out of bounds
         (void) fprintf(stderr, OUT_OF_BOUNDS, WIDTH, (int)width,
                                (int)MIN_WIDTH, (int)MAX_WIDTH);
         
    } else if(isOdd(width) != 1){
         (void) fprintf(stderr, NUM_EVEN, width);
         flag = 1;
    }
    


    // --------------------------------------------z_index condition checks 
    if( strlen(argv[Z_INDEX]) != 1 ) {
         flag = 1;
         (void) fprintf(stderr, INVALID_CHAR, Z_CHAR , argv[Z_INDEX]);

    } else if ( isInBounds(LOWER_CHAR_BOUND, UPPER_CHAR_BOUND, *argv[Z_INDEX]) == 0){
         flag = 1;
         (void) fprintf(stderr, OUT_OF_BOUNDS,Z_CHAR, *argv[Z_INDEX],
         (int)LOWER_CHAR_BOUND, (int)UPPER_CHAR_BOUND); 
    }
    

    // ----------------------------------------filterChar condition checks 
    if( strlen(argv[FILLER_INDEX]) != 1) {
         (void) fprintf(stderr, INVALID_CHAR, FILLER_CHAR, argv[FILLER_INDEX]);
         flag = 1;
    } else if ( isInBounds(LOWER_CHAR_BOUND, UPPER_CHAR_BOUND,
    *argv[FILLER_INDEX]) == 0) {
         flag = 1;
         (void) fprintf(stderr, OUT_OF_BOUNDS, FILLER_CHAR, *argv[FILLER_INDEX],
         (int)LOWER_CHAR_BOUND, (int)UPPER_CHAR_BOUND);

    } 
    

    // ---------------------------------------borderChar condition checks
    if( strlen(argv[BORDER_INDEX]) != 1 ) {
         (void) fprintf(stderr, INVALID_CHAR, BORDER_CHAR, argv[BORDER_INDEX]);
         flag = 1;
    } else if ( isInBounds(LOWER_CHAR_BOUND, UPPER_CHAR_BOUND,
    *argv[BORDER_INDEX]) == 0){
         flag = 1;
         (void) fprintf(stderr, OUT_OF_BOUNDS, BORDER_CHAR, *argv[BORDER_INDEX],
         (int)LOWER_CHAR_BOUND, (int)UPPER_CHAR_BOUND);
    } 
    
    long z_char = *argv[Z_INDEX];
    long filler_char = *argv[FILLER_INDEX];
    long border_char = *argv[BORDER_INDEX];
 
    if(flag == 1 || (z_char == filler_char || z_char == border_char)) {
        //fprintf(stderr, "in the if %ld %ld %ld", z_char, filler_char, border_char);
        if (flag != 1) {
          fprintf(stderr, EXCLUSIVE);
        }
        fprintf(stderr, USAGE);
        return EXIT_FAILURE;
    } 


    drawZ( width, z_char, border_char, filler_char );
    return EXIT_SUCCESS; 
}
