/**
*   Problem Source: Cracking the Coding Interview 4th edition by Gayle Laakman
*   Given two strings, check if they are anagrams.
*/

#include <iostream>
#include <string>

std::string sortStr( std::string myStr )
{
  bool checkAgain = true ;
  int  max        = myStr.size() ;
  while( checkAgain )
  {
    checkAgain = false ;
    for( unsigned int i = 0 ; i < max ; i++ )
    {
      char curr = myStr[i] ;
      char next = myStr[i+1] ;
      if( curr == next )
      {
        char temp     = curr ;
        myStr[i]      = next ;
        myStr[i+1]    = curr ;
        max           = max - 1 ;
        checkAgain    = true ;
      }
    }
  }

  // remove spaces
  std::string cleanStr = "" ;
  for( unsigned int i = 0 ; i < myStr.size() ; i++ )
  {
    if( myStr[i] == ' ' )
      continue ;
    else
      cleanStr += myStr[i] ;
  }

  return cleanStr ;
}

// false = not anagrams
// true  = yes anagrams
bool checkAnagram( std::string s1, std::string s2 )
{
  bool result = true ;

  std::string s1_cleanSorted = sortStr( s1 ) ;
  std::string s2_cleanSorted = sortStr( s2 ) ;

  if( s1_cleanSorted.size() == s2_cleanSorted.size() )
  {
    for( unsigned int i = 0 ; i < s1_cleanSorted.size() ; i++ )
    {
      if( s1_cleanSorted[i] == s2_cleanSorted[i] )
        continue ;
      else
      {
        result = false ;
        break ;
      }
    }
  }
  else
    result = false ;

  return result ;
}

int main( int argc, char** argv )
{
  if( argc < 3 )
  {
    std::cout << "ERROR: Please run as ./a.out \"<string1>\" \"<string2>\"" << std::endl ;
    abort() ;
  }

  std::string s1 = argv[1] ;
  std::string s2 = argv[2] ;

  bool result = false ;
  result = checkAnagram( s1, s2 ) ;

  std::string result_str = "" ;
  if( result )
    result_str = "yes" ;
  else
    result_str = "no" ;

  std::cout << " string1    :   " << s1 << std::endl ;
  std::cout << " string2    :   " << s2 << std::endl ;
  std::cout << " anagrams?  :   " << result_str <<  std::endl ;

  return 0 ;
}
