/**
*   Problem Source: Cracking the Coding Interview 4th edition by Gayle Laakman
*   Prompt:
*     1.1 Implement an algorithm to determine if a string has all unique characters. What if you cannot use additional data structures?
*/

#include <iostream>
#include <map>
#include <stdio.h>
#include <string>

// use a map to uniquely store each character
// if the associated value is greater than 1,
// then return false for uniqueness question
// O(n) in the number of characters
bool checkUnique_map( std::string myString )
{
  bool result = true ;

  // map of characters in the given string
  // key = character from string
  // val = number of times character appeared in input string
  std::map< char, int > myMap ;

  // iterate over string characters, insert into map,
  // else hit a duplicate
  for( unsigned int i = 0 ; i < myString.size() ; i++ )
  {
    char currChar = myString[ i ] ;
    if( myMap.insert( std::make_pair( currChar, 1 ) ).second == false )
      result = false ;
  }

  return result ;
}

// sort the characters in the string.
// Iterate over the sorted string.
// If two successive chars are equal, then
// hit a duplicate.
// O(n^2) in number of characters
bool checkUnique_sorting( std::string myString )
{
  bool result = true ;

  // bubble sort
  bool flag = true ;
  while( flag )
  {
    flag = false ;
    unsigned int max = myString.size() ;
    for( unsigned int i = 0 ; i < max ; i++ )
    {
      if( myString[i] != '\0' && myString[i+1] != '\0' )
      {
        if( myString[ i ] < myString[ i+1 ] )
        {
          continue ;
        }
        else if( myString[ i+1 ] < myString[ i ] )
        {
          char temp       = myString[ i ] ;
          myString[ i ]   = myString[ i+1 ] ;
          myString[ i+1 ] = temp ;
          flag            = true ;
          max             = max - 1 ;
        }
        else 
          break ;
      }
    } 
  }

  std::cout << "Sorted input string               :  " << myString << std::endl ;

  // check for duplicates
  for( unsigned int i = 0 ; i < myString.size() ; i++ )
  {
    if( myString[ i ] == myString[ i+1 ] )
      result = false ;
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
  std::string myString = argv[1] ;
  bool result_map      = true ;
  bool result_sorting  = true ;

  result_map     = checkUnique_map( myString  ) ;
  result_sorting = checkUnique_sorting( myString ) ;

  std::cout << "String to test                    :  " << myString << std::endl ;
  std::cout << "Only unique characters? (map)     :  " << result_map << std::endl ;
  std::cout << "Only unique characters? (sorting) :  " << result_sorting << std::endl ;

  return 0 ;
}
