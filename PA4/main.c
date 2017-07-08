/*
 * Filename: main.c
 * Author: Hwa Chien Hong
 * Userid: A92072250
 * Description: the main driver of the program. Its main tasks are to parse the
 * command line arguments, open and merge the input files, sort the content of
 * the merged files then display desired outputs
 * Date: 3/11/17
 * Sources of Help: website links on the course website, Tutors 
 */ 

#include <limits.h>	/* For LONG_MIN and LONG_MAX */
#include "pa4.h"	  /* For function prototype */
#include "pa4Strings.h"
#include <stdio.h> 
#include <stdlib.h>
#include <errno.h> 
#include <strings.h>

/*
 * Function name: main( int argc, char * argv[] )
 * Function prototype: int main( int argc, char * argv[] )
 * Description: parse the command line arguments, open and merge the input files
 * and sort the contents then prints out the desired outputs
 * Parameters: int argc, char * argv[]
 *
 * Side Effects: None.
 * Error Conditions: None. 
 * Return Value: returns SUCCESS or FAILURE depending on results
 */

int main( int argc, char * argv[] ) {
  unsigned int flags = 0;
  int c, option_index = 0, bad = 0, mutual = 0;

  static struct option long_options[] = {
        {FLAG_D_STR, no_argument, NULL, FLAG_D_CHAR},
        {FLAG_U_STR, no_argument, NULL, FLAG_U_CHAR},
        {FLAG_C_STR, no_argument, NULL, FLAG_C_CHAR},
        {FLAG_I_STR, no_argument, NULL, FLAG_I_CHAR},
        {FLAG_R_STR, no_argument, NULL, FLAG_R_CHAR},
        {FLAG_S_STR, no_argument, NULL, FLAG_S_CHAR},
        {FLAG_T_STR, no_argument, NULL, FLAG_T_CHAR},
        {FLAG_H_STR, no_argument, NULL, FLAG_H_CHAR},
        {0,0,0,0}
   };

  while((c=getopt_long(argc, argv, ARG_STR, long_options, &option_index))!= -1){
      // Parsing the various different flags
      switch(c) {
        case FLAG_D_CHAR: 
          mutual += 5;
          flags |= FLAG_D;
          break;
      
        case FLAG_U_CHAR:
          mutual += 5;
          flags |= FLAG_U;
          break;

        case FLAG_C_CHAR:
          flags |= FLAG_C;
          break;

        case FLAG_I_CHAR:
          flags |= FLAG_I;
          break;

        case FLAG_R_CHAR:
          flags |= FLAG_R;
          break;

        case FLAG_S_CHAR:
          flags |= FLAG_S;
          break;

        case FLAG_T_CHAR:
          flags |= FLAG_T;
          break;

        case FLAG_H_CHAR:
          flags |= FLAG_H;
          break;

        // Bad flag case
        case '?':
          bad = -1;
          break;

        default:
          (void) fprintf(stderr, STR_USAGE_SHORT, argv[0], argv[0] );
          return EXIT_FAILURE;
      }
    }
    // Mutually exclusive commands passed in 
    if( mutual == 10) {
      (void) fprintf(stderr, STR_ERR_MUTUAL_EX);
      (void) fprintf(stderr, STR_USAGE_SHORT, argv[0], argv[0]);
      return EXIT_FAILURE;
    }
    // no arguments passed in 
    if((argc - 1) <= 0) {
      (void) fprintf(stderr, STR_USAGE_SHORT, argv[0], argv[0] );
      return EXIT_FAILURE;
    }
    // if the H flag is on
    if((flags ^ FLAG_H) == (flags - FLAG_H)) {
      (void) fprintf(stderr, STR_USAGE_LONG, argv[0]);
      return EXIT_SUCCESS;
    }
  
    // Bad flag check
    if(bad == -1) {
      (void) fprintf(stderr, STR_USAGE_SHORT, argv[0], argv[0] );
         return EXIT_FAILURE;
    }
   
    char * filenames[argc-optind];
    int idx = optind, numFiles = argc - optind;

    // Place all input files in a char array
    for(int i = 0; i < numFiles; i++, idx++) {
        filenames[i] = argv[idx];
    }
    
    FILE ** files = sortFiles(numFiles, filenames, flags);
    // Error detected
    if( files == NULL ) return EXIT_FAILURE;

    struct fileLines fileLines = mergeFiles(files, numFiles);
    // Error detected
    if( fileLines.numLines == -1) return EXIT_FAILURE;
    
    // Sort flag on, check
    if( (flags ^ FLAG_S) == flags - FLAG_S) {

      // case insensitivity flag set
      if( (flags ^ FLAG_I) == flags - FLAG_I) {
        qsort( fileLines.lines, fileLines.numLines, sizeof(char*),
      compareLinesIgnoreCase);

      } else {
      // compares case senstively 
         qsort( fileLines.lines, fileLines.numLines, sizeof(char*),
      compareLines);

      }
    }

    struct distinctHead distinctHead = buildData(&fileLines, flags);
    
    // display the final outputs 
    if( (flags ^ FLAG_D) == flags-FLAG_D) {
       displayOutput(distinctHead, flags, duplicate);
    
    // Displays uniquely
    } else if ((flags ^ FLAG_U) == flags-FLAG_U) {
      displayOutput(distinctHead, flags, unique);

    } else displayOutput(distinctHead, flags, regular);

    //free(distinctHead);
    //free(distinctLines);

    return EXIT_SUCCESS;    
}
 
