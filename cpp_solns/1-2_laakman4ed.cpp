/**
*   Problem Source: Cracking the Coding Interview 4th edition by Gayle Laakman
*   Prompt:
*     1.2 Write code to reverse a c-style string.
*/

#include <iostream>
#include <string>

int main( int argc, char** argv )
{
  if( argc < 2 )
  {
    std::cout << "ERROR: Run as ./a.out <stringToReverse>" << std::endl ;
    abort() ;
  }

  std::string orig    = argv[1] ;
  std::string reverse = "" ;

  int i = orig.size() ; // equality catches the trailing \0
  while( i >= 0 )
  {
    std::cout << "Char = " << orig[i] << std::endl ;
    reverse += orig[i] ;
    i-- ;
  }

  std::cout << "Orig     : " << orig << std::endl ;
  std::cout << "Reverse  : " << reverse << std::endl ;

  return 0 ;
}
