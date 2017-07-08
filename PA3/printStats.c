/*
 * Filename: printStats.c
 * Author: Hwa Chien Hong
 * Userid: A92072250
 * Description: printStats program handle the interactive mode of the program
 * it first prompts the user to enter a word and then prints any matching
 * anagrams of that word, excluding the word itself
 *
 * Date: 2/19/17
 * Sources of Help: website links on the course website, Tutors 
 */ 

#include <limits.h>	/* For LONG_MIN and LONG_MAX */
#include "pa3.h"	  /* For function prototype */
#include "pa3Strings.h"
#include <stdio.h> 
#include <stdlib.h>
#include <errno.h> 
#include <strings.h>

/*
  struct Anagram {
    char sortedWord[BUFSIZ];
    size_t numWords;
    char ** words;
  }
 */

void printStats( struct HashTable const * table, int index ) {
  
  // Grabing the correct entry corresponding to the index
  struct TableEntry * entry = (table->entryPtr)+index;
  // Grabing the anagram pointer at that index
  struct Anagram * ana = (entry->anagramPtr);
  
  struct Anagram * most_word_pointer;
  struct Anagram * least_word_pointer;

  unsigned int collisions = (entry->numAnagrams);

  int correct_Collision = (entry->numAnagrams);
  unsigned int totalWords = 0, temp_most_count = 0,
                         temp_least_count = INT_MAX, count = 0;
  
  // numAnagrams and collisions are the same
  for(ana = (entry->anagramPtr); count < collisions; ++count, ++ana) {
    totalWords += (ana->numWords);
    if(temp_most_count <= (ana->numWords)) {
      most_word_pointer = ana;
      temp_most_count = ana->numWords;
    }
    if(temp_least_count> (ana->numWords)) {
      least_word_pointer = ana;
      temp_least_count = ana->numWords;
    }
  }

  // get the first word that appears
  char word_most[]={0};
  (void)strcpy(word_most, *(most_word_pointer->words));
  
  char word_least[]={0};
  (void)strcpy(word_least, *(least_word_pointer->words));

  // Printing out the stats here
  (void)printf(STR_STATS_FOR_INDEX, index);
  (void)printf(STR_COLLISIONS, correct_Collision);
  (void)printf(STR_NUM_WORDS, totalWords);
  (void)printf(STR_MAX_ANAGRAMS, word_most, temp_most_count-1);
  (void)printf(STR_MIN_ANAGRAMS, word_least, temp_least_count-1);
}
