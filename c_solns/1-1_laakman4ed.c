/***************************************************************************
* Problem Source: Cracking the Coding Interview 4th edition by Gayle Laakman
* Prompt:
*   1.1 Implement an algorithm to determine if a string has all unique characters. What if you cannot use additional data structures?
***************************************************************************/

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// Given string and char, check if char is in string.
// O(n) in the number of characters
bool find( char myString[], char c )
{
  bool result = false ;

  for( int i = 0 ; i < strlen( myString ) ; i = i + 1)
  {
    if( myString[i] == c )
    {
      result = true ;
      break ;
    }
  }

  return result ;
}

bool checkUnique( char* myString )
{
  bool result = true ;

  int size = strlen( myString ) ;
  char temp[ size ] ; // not initialized
  strcat( temp, "" ) ;

  for( int i = 0 ; i < size ; i = i + 1 )
  {
    char currChar = myString[i] ;
    if( find( temp, currChar ) )
    {
      result = false ;
      break ;
    }
    else
    {
      size_t currSize = 1 ;
      char* newCharString = malloc( 1 + 1 ) ;
      newCharString[ 0 ] = currChar ;
      newCharString[ 1 ] = '\0' ;
      strcat( temp, newCharString ) ;
    }
  }

  return result ;
}

int main( int argc, char** argv )
{
  if( argc < 2 )
  {
    printf( "ERROR: Please run as ./a.out <stringToExamine>\n" ) ;
    exit( -1 ) ;
  }

  // get command line argument
  char* myString = argv[1] ;

  bool result = true ;

  result = checkUnique( myString  ) ;

  printf( "String to test          :  %s\n", myString ) ;
  printf( "Only unique characters? :  %d\n", result ) ;

  return 0 ;
}
