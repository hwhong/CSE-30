/*
 * Filename: testsortFiles.c
 * Author: Hwa Chien Hong
 * Userid: cs30xnp
 * Description: Unit test program to test the function sortFiles().
 * Date: 3/3/17
 * Sources of Help: Tutor, website links 
 */ 

#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <string.h>

#include "pa4.h"       /* For sortFiles() function prototype */
#include "test.h"      /* For TEST() macro and stdio.h */

#define SYSRUN(CMD) (system(CMD))

static void runTest( int numFiles, char * filenames[], unsigned int flags, 
                     char * expectedOrder[],
                     int expectedNull, char * expectedErr, char * testDesc );

static char * testFileName = ".test_sortFiles_student_file";
static FILE * testFilePtr;
static struct stat recover(FILE * f);

/*
 * Unit Test for sortFiles.c
 * 
 * FILE ** sortFiles( int numFiles, char * filenames[], unsigned int flags );
 *
 * Sorts the files specified by the filenames based on the sort comparison
 * specified by the flags. Then opens the files for reading and returns their
 * file pointers.
 */
static void testsortFiles() {
  int numFiles;
  int expectedNull;
  unsigned int flags;


  /* Test 1 */
  (void) fprintf( stderr, "\nRUNNING TEST 1!\n" );
  numFiles = 1;
  char * filenames1[] = { "badfile" };
  flags = 0;
  char * expectedOrder1[] = { "badfile" }; 
  expectedNull = 1;
  char * expectedErr1 = "badfile: No such file or directory\n";

  runTest( numFiles, filenames1, flags, expectedOrder1, expectedNull, 
           expectedErr1, "Test 1, file does not exist" );

  
  /* Test 2 */
  (void) fprintf( stderr, "\nRUNNING TEST 2!\n" );
  numFiles = 1;
  char * filenames2[] = { "restrictedFile" };
  flags = 0;
  char * expectedOrder2[] = { "restrictedFile" };
  expectedNull = 1;
  char * expectedErr2 = "restrictedFile: Permission denied\n";

  runTest( numFiles, filenames2, flags, expectedOrder2, expectedNull, 
           expectedErr2, "Test 2, do not have permission to open file" );

  /* Test 3 */
  (void) fprintf( stderr, "\nRUNNING TEST 3!\n" );
  numFiles = 5;
  char * filenames3[] = { "cse", "thirty", "is", "pretty", "hard" };
  flags = 0;
  char * expectedOrder3[] = { "cse", "hard", "is", "pretty", "thirty" };
  expectedNull = 0;

  runTest( numFiles, filenames3, flags, expectedOrder3, expectedNull, 
           "", "" );

  /* Test 4 */
  (void) fprintf( stderr, "\nRUNNING TEST 4!\n" );
  numFiles = 2;
  char * filenames4[] = { "noread", "stillnoread" };
  flags = 0;
  char * expectedOrder4[] = { "noread", "stillnoread" };
  expectedNull = 1;
  char * expectedErr4 = "noread: Permission denied\n";

  runTest( numFiles, filenames4, flags, expectedOrder4, expectedNull, 
           expectedErr4, "Test 4, do not have permission to open file" );
 
  /* Test 5 */
  (void) fprintf( stderr, "\nRUNNING TEST 5!\n" );
  numFiles = 4;
  char * filenames5[] = { "cse", "is", "not", "hard" };
  flags = 0x10;
  char * expectedOrder5[] = { "not", "is", "hard", "cse" };
  expectedNull = 0;

  runTest( numFiles, filenames5, flags, expectedOrder5, expectedNull, 
           "", "" );

}


/*
 * Function Name: runTest()
 * Function Prototype: void runTest( unsigned int bank[], char * expectedOutput,
                                     char * testDesc );
 * Description:  Helper function to actually run a test of displayLights.
 *               Prints test description (as specified by testDesc), and
 *               calls displayLights, handling segfaults.
 * Parameters:
 *     arg1: unsigned int bank[] -- bank of lights
 *     arg2: char * expectedOutput -- the expected output to be printed by
 *                                    displayLights()
 *     arg3: char * testDesc -- Description of the test being run
 * Side Effects: Outputs the result of the test to stderr
 * Error Conditions: None
 * Return Value: None
 */
static void runTest( int numFiles, char * filenames[], unsigned int flags, 
              char * expectedOrder[], int expectedNull, char * expectedErr,
              char * testDesc ){
  /* 
   * Begin setup to capture stderr to a file.  You aren't expected to know how
   * to do this, but it never hurts to learn!
   */
  testFilePtr = fopen( testFileName, "w+" );
  int saveErr = dup(fileno(stderr));
  if ( testFilePtr == NULL ) {
    perror( "Could not open test file" );
    exit( 1 );
  }

  if ( dup2( fileno( testFilePtr ), fileno( stderr ) ) == -1 ) {
    perror( "Could not duplicate stderr file descriptor" );
    exit( 1 );
  }
  /* End setup to capture stdout */

  /* buffer for comparing output */
  char buf[BUFSIZ] = {0};

  /* Print test description */
  (void) fprintf( stdout, "%s\n", testDesc );

  /* Sort the files and flush stderr */
  FILE ** sortedFiles = sortFiles(numFiles, filenames, flags);
  (void) fflush( stderr );

  /* Reset file pointer */
  (void) fseek( testFilePtr, 0, SEEK_SET );

  /* Read from test file and compare */
  (void) fgets( buf, BUFSIZ, testFilePtr );

  /* Close file when done and restore stderr*/
  (void) fclose( testFilePtr );
  if ( dup2( saveErr, fileno( stderr ) ) == -1 ) {
    perror( "Could not restore stderr file descriptor" );
    exit( 1 );
  }

  /* Real testing starts here */
  /* That any errors printed matched first */
  TEST( strncmp( buf, expectedErr, BUFSIZ ) == 0 );
  if( strncmp( buf, expectedErr, BUFSIZ ) != 0 ){
    (void) fprintf( stderr, "Expected output: %s\n", expectedErr );
    (void) fprintf( stderr, "Actual output: %s\n\n", buf );
  }

  /* check if an error was expected */
  if( expectedNull ){
    TEST( sortedFiles == NULL );
  }
  else{
    TEST( sortedFiles != NULL );
     
     struct fileInfo * info_array = malloc(sizeof(struct fileInfo)*numFiles);
     
      // Populate the array of fileInfo
      int i;
      for( i = 0; i < numFiles; i++) {
        // Assigning values of stats to the stat variable in fileInfo Struct
        stat(expectedOrder[i], &(info_array[i].statInformation));
          
        // Assigning values of filename to the filename variable in fileInfo Struct
        info_array[i].filename = expectedOrder[i];
      }
    int j;
    for( j = 0; j < numFiles; j++) {
      TEST(recover(sortedFiles[j]).st_dev == (info_array[j]).statInformation.st_dev);
      TEST(recover(sortedFiles[j]).st_ino == (info_array[j]).statInformation.st_ino);
    }
  }
}

struct stat recover(FILE * f){
  int fd;
  struct stat stat;
  
  fd = fileno(f);
  fstat(fd, &stat);
  
  return stat;
}

int main() {

  (void) fprintf( stderr, "Running tests for sortFiles...\n" );
  testsortFiles();
  (void) fprintf( stderr, "\nDone running tests!\n" );


  return 0;
}
