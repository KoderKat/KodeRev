/**
*   Problem Source: Cracking the Coding Interview 4th edition by Gayle Laakman
*   Substitute '%20' for all whitespace in a string.
*/

#include <iostream>
#include <string>

std::string mySub( std::string origStr )
{
  std::string newStr = "" ;

  char currChar = '\0' ;
  for( unsigned int i = 0 ; i < origStr.size() ; i++ )
  {
    currChar = origStr[ i ] ;
    if( (currChar == ' ') || (currChar == '\n') || (currChar == '\t') )
      newStr += "%20" ;
    else
      newStr += currChar ;
  }

  return newStr ;
}

int main( int argc, char** argv )
{
  std::string origStr = "" ;

  if( argv[1] )
    origStr = argv[1] ;
  else
  {
    std::cout << "ERROR: Too few inputs. Run as ./a.out <stringToTest>" << std::endl ;
    abort() ;
  }

  std::string newStr = mySub( origStr ) ;
  std::cout << "origStr     :  " << origStr << std::endl ;
  std::cout << " newStr     :  " <<  newStr << std::endl ;

  return 0 ;
}
