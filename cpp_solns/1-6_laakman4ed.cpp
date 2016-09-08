/**
*   Problem Source: Cracking the Coding Interview 4th edition by Gayle Laakman
*   Rotate an nxn matrix of chars 90 degrees.
*/

#include <iostream>
#include <string>

void rotate( char mat[3][4], size_t numRows, size_t numCols )
{
}

int main( int argc, char** argv )
{
  char mat[3][4] = {
    { 'A', 'B', 'C', 'D' },
    { 'E', 'F', 'G', 'H' },
    { 'I', 'J', 'K', 'L' }
  } ;

  int numRows = sizeof( mat ) / sizeof( mat[0] ) ;
  int numCols = sizeof( mat[0] ) / sizeof( mat[0][0] ) ;

  rotate( mat, numRows, numCols ) ;

  return 0 ;
}
