/**
*   Problem Source: Cracking the Coding Interview 4th edition by Gayle Laakman
*   Prompt:
*     1.2 Write code to reverse a c-style string.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main( int argc, char** argv )
{
  if( argc < 2 )
  {
    printf( "ERROR: Run as ./a.out <stringToReverse>\n" ) ;
    exit( -1 ) ;
  }

  char* orig    = argv[1] ;
  int size      = strlen( orig ) ;
  char reverse[ size ] ;
  memset( reverse, 0, size ) ; // initialize reverse

  int i = size ; // equality catches the trailing \0
  while( i >= 0 )
  {
    printf( "Char = %c\n", orig[i] ) ;

    // convert char into str
    char* tmp = malloc( 2 ) ;
    tmp[0]    = orig[i] ;
    tmp[1]    = '\0' ;
    strcat( reverse, tmp ) ;

    i = i - 1 ;
  }

  printf( "Orig     : %s\n", orig ) ; 
  printf( "Reverse  : %s\n", reverse ) ;

  return 0 ;
}
