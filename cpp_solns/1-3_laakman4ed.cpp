/**
*   Problem Source: Cracking the Coding Interview 4th edition by Gayle Laakman
*   Given a string which may contain duplicate characters, remove the duplicate characters.
*   Do not use additional data structures. A few extra variables are fine.
*/

#include <iostream>
#include <string>

std::string getSorted( std::string myString )
{
  // bubble sort
  bool checkAgain = true ;
  while( checkAgain )
  {
    checkAgain = false ;
    int max = myString.size() ;
    for( unsigned int i = 0 ; i < max ; i++ )
    {
      // ordered chars ok
      if( myString[ i ] < myString[ i+1 ] )
      {
        continue ;
      }
      // out of order chars
      else if( myString[ i+1 ] < myString[ i ] )
      {
        char temp       = myString[ i ] ;
        myString[ i ]   = myString[ i+1 ] ;
        myString[ i+1 ] = temp ;
        checkAgain      = true ; // made a swap, check again
        max             = max - 1 ;
      }
    }
  }

  return myString + '\0' ;
}

std::string removeDups( std::string myString )
{
  std::string result = "" ;

  std::string sortedStr = getSorted( myString ) ;
  std::cout << "sorted str = " << sortedStr << std::endl ;

  for( unsigned int i = 0 ; i < sortedStr.size() ; i++ )
  {
    char currChar = sortedStr[i] ;
    char nextChar = sortedStr[i+1] ;

    // only save unique chars
    if( currChar == nextChar )
      continue ;
    else
      result += currChar ;
  }

  return result ;
}

int main( int argc, char** argv )
{
  if( argc < 2 )
  {
    std::cout << "ERROR: Please run as ./a.out <stringToExamine>" << std::endl ;
    abort() ;
  }

  std::string inString  = argv[1] ;
  std::string outString = removeDups( inString ) ;

  std::cout << "Input string          : " << inString << std::endl ;
  std::cout << "String w/o duplicates : " << outString << std::endl ;

  return 0 ;
}
