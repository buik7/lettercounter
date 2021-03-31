/*******************************************************************************
*
* Purpose: Assignment #3 solution.
* 
* Author: Kevin Browne
*
*******************************************************************************/
#include <stdio.h>
#include <string.h>
#include <ctype.h>

void print_count(int count[], int total, int offset);
#define NUM_LETTER 26

int main()
{
  char buffer[1024], input, curchar;
  int i = 0, count_lower[NUM_LETTER], count_upper[NUM_LETTER];

  // request and read in the string from the user
  printf("Enter text for analysis: ");
  while ( (input = getchar()) != '\n' ) {
    buffer[i++] = input;
  }
  buffer[i] = '\0';

  // set the letter counts to zero
  for (i = 0; i < NUM_LETTER; i++) count_lower[i] = count_upper[i] = 0;
  
  // Count the occurrences of each letter a-z and A-Z in the buffer string, 
  // storing the counts into count_lower and count_upper.  We store the 
  // count for each character in alphabetical order in the counter arrays. 
  // Knowing that ASCII characters a-z are stored from 97-122, and ASCII 
  // characters A-Z are stored from 65-90, we can store the counts using 
  // 97 and 65 as 'offset' values.
  for (i = 0; i < strlen(buffer); i++) {
    if (buffer[i] >= 97 && buffer[i] <= 122) count_lower[buffer[i] - 97]++;
    if (buffer[i] >= 65 && buffer[i] <= 90) count_upper[buffer[i] - 65]++;
  }

  // Create the letter analysis table
  printf("\n\nLetter Analysis Complete!");
  printf("\n\nLetter    Occurrences    Percentage\n");
  printf("*****************************************\n");
  print_count(count_lower, strlen(buffer), 97);
  print_count(count_upper, strlen(buffer), 65);

  // Find the max and min occuring character in the string
  int max, min;
  char max_char, min_char;
  max = min = count_lower[0];
  max_char = min_char = 'a';

  // check the lowercase characters, use 97 as the offset to identify the char
  for (i = 0; i < NUM_LETTER; i++) {
    if (count_lower[i] < min)
    {
      min_char = i + 97;
      min = count_lower[i];
    }
    if (count_lower[i] > max)
    {
      max_char = i + 97;
      max = count_lower[i];
    }
  }

  // check the upper case characters, use 65 as the offset to identify the char
  for (i = 0; i < NUM_LETTER; i++) {
    if (count_upper[i] < min)
    {
      min_char = i + 65;
      min = count_upper[i];
    }
    if (count_upper[i] > max)
    {
      max_char = i + 65;
      max = count_upper[i];
    }
  }

  // Output the max and min occuring character
  printf("\nMost frequently occurring character: %c\n", max_char);
  printf("Least frequently occurring character: %c\n", min_char);

  return 0;
}

// prints the counts of characters from a-z or A-Z (based on offset provided),
// also prints the percentage of the total for each character
void print_count(int count[], int total, int offset)
{
  for (int i = 0; i < NUM_LETTER; i++) {
  printf("%-10c%-15d%-15.4f\n", 
         i + offset,
         count[i],
         (((float) count[i]) / total) * 100);
  }
}

