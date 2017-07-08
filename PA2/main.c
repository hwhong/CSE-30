/*
 * Filename: main.c
 * Author: Hwa Chien Hong
 * Userid: A92072250
 * Description: Main program to display lights and operate.
 * Date: 2/11/17
 * Sources of Help: website links on the course website, Tutors 
 */ 

#include <limits.h>	/* For LONG_MIN and LONG_MAX */
#include "pa2.h"	  /* For function prototype */
#include "pa2Strings.h"
#include <stdio.h> 
#include <stdlib.h>
#include <errno.h> 
#include <strings.h>

int main( int argc, char * argv[] ) {
  unsigned int lightBank[] = {0,0};     // initialize bank of lights of two 32-bits int
  const char * const commands[] = { COMMANDS, NULL };
  
  /* variables that assist with main prompt */ 
  FILE * inFile = stdin; 
  char buf[BUFSIZ] = { 0 };
  short prompt = TRUE; 

  // for other variables
  char* endptr; 
  errno = 0;
  int BASE = 0;
  char buffer[BUFSIZ];

  // ensures correct order 
  (void) setvbuf( stdout, NULL, _IONBF, 0 ); //turns off buffering in stdout
  argc--;
  if( argc > MAX_ARGS ) {
    (void) fprintf(stderr, STR_USAGE_MSG, argv[0]);   // too many arguments
    return EXIT_FAILURE; 
  }

  if( argc == MAX_ARGS) { 
    // if not successful open, returns NULL
    if(NULL ==  fopen( argv[1], "r")) {
        perror(argv[1]);            // perror filename as param 
        return EXIT_FAILURE; 
    }  

    inFile = fopen( argv[1], "r");    // successfull open, setting this file as inFile
    prompt = FALSE;
  } else {
    // no file argument 
    prompt = checkPrompt();
  }

  displayLights( lightBank );
  
  // main for loop start 

  for( DISPLAY_PROMPT; fgets( buf, BUFSIZ, inFile ) != NULL; DISPLAY_PROMPT ) {
     
     /* -------------------- Parsing command to operate ----------------------*/

     char *token = strtok( buf, TOKEN_SEPARATORS );
     if( token == NULL) continue; // if token not found, reprompt user 
   
     int command = checkCmd(token, commands);
     if( command == -1) {         // since bad command, reprompt & print error
        (void) fprintf( stderr, STR_BAD_CMD );
        continue;
     }
      
     // HELP entered, print message and reprompt 
     if ( command == 6 ) { 
        (void) fprintf( stderr, STR_HELP_MSG );
         continue;  
     }
     // QUIT entered, break out of for-loop
     if( command == 7 ) break;

     /* --------------------- Parsing for First Argument ---------------------*/
    
     char *command_token = strtok( NULL, TOKEN_SEPARATORS );

     // if argument wasn't found, print msg and reprompt user
     if (command_token == NULL) {
        (void) fprintf( stderr, STR_ARGS_REQ);
        continue; 
     }

     errno = 0;

     // convert argument into an unsigned int 
     unsigned int argument_one = strtoul(command_token, &endptr, BASE );  
     
     //-------------- contains non-numerical character, print msg and reprompt 
     if( *endptr != '\0' ) {
        (void) fprintf( stderr, STR_STRTOLONG_NOTINT, command_token );
        continue; 
     //too large to convert, create err msg and reprompt 
     } else if ( errno != 0) {
        (void) snprintf(buffer, BUFSIZ, STR_STRTOLONG_CONVERTING,
                                                      command_token, BASE);
        perror(buffer);
        continue; 
     }

     /* ----------Passing in vars/Parse Second Arg (if neccessary)----------*/ 
     
     unsigned long int argument_two = 0;
     errno = 0;

     // Parsing the second argument
     if (command == 0 || command == 1 || command == 2) {
         // gets the next argument in line 
         char *command_token_two = strtok( NULL, TOKEN_SEPARATORS );

         //if argument wasn't found, print msg and reprompt user
          if (command_token_two == NULL) {
             (void) fprintf( stderr, STR_TWO_ARGS_REQ );
             continue; 
          }

         // convert argument into an unsigned int 
         argument_two = strtoul( command_token_two, &endptr, BASE );  
     
         // contains non-numerical character, print msg and reprompt 
         if( *endptr != '\0' ) {
             (void) fprintf( stderr, STR_STRTOLONG_NOTINT, command_token_two );
             continue; 
         //too large to convert, create err msg and reprompt 
         } else if ( errno != 0) {
             (void) snprintf( buffer, BUFSIZ, STR_STRTOLONG_CONVERTING,
                                                        command_token_two, BASE );
             perror(buffer);
             continue; 
         }
     }

     //if any extra arguments are present 

     command_token = strtok( NULL, TOKEN_SEPARATORS);
     
     // if another argument was found, print msg and reprompt user
     if (command_token != NULL) {
       (void) fprintf( stderr, STR_EXTRA_ARG, command_token);
       continue; 
     }

     // ------------------Passing and setting arguments ------------------

     switch( command ) {  
        case 0:
           set( lightBank, argument_one, argument_two );
           displayLights( lightBank );
           break;
        case 1: 
           clear( lightBank, argument_one, argument_two );
           displayLights( lightBank );
           break;
       case 2: 
           toggle( lightBank, argument_one, argument_two );
           displayLights( lightBank );
           break;
       case 3:
           shift( lightBank, argument_one );
           displayLights( lightBank );
           break;
       case 4: 
           rotate( lightBank, argument_one ); 
           displayLights( lightBank );
           break;
       case 5: 
           ripple( lightBank, argument_one );
           break;
     }
     
  }

  fclose(inFile);
  if( errno != 0 ) return EXIT_FAILURE;

  return EXIT_SUCCESS;
}
