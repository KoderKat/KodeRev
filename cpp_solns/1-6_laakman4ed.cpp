/**
*   Problem Source: Cracking the Coding Interview 4th edition by Gayle Laakman
*   Rotate an nxn matrix of chars 90 degrees.
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

void rotate( std::vector< std::vector< char > > origMat )
{
  std::vector< std::vector< char > > newMat ;
  std::vector< char >                tmp ;

  // create new matrix
  //initialize all rows
  int dim = origMat.size() ; // assumes nxn
  for( unsigned int i = 0 ; i < dim ; i++ )
  {
    std::vector< char > initRow ;
    initRow.push_back( '\0' ) ;
    newMat.push_back( initRow ) ;
  }
  // populate rows
  for( unsigned int i = 0 ; i < origMat.size() ; i++ )
  {
    std::vector< char > currRow = origMat.at( i ) ;
    int k = 0 ;
    int j = currRow.size() - 1 ;
    while( j >= 0 )
    {
      std::cout << i << currRow.at(j) << std::endl ;
      newMat.at(k).push_back( currRow.at( j )) ;
      j-- ;
      k++ ;
    }
  }
  // clear initial char
  for( unsigned int i = 0 ; i < dim ; i++ )
  {
    newMat.at(i).erase(newMat.at(i).begin()) ;
  }

  // print original matrix
  std::cout << "orig matrix: " << std::endl ;
  std::vector< std::vector< char > >::const_iterator row_old ;
  std::vector< char >::const_iterator                col_old ;
  for( row_old = origMat.begin() ; row_old != origMat.end() ; row_old++ )
  {
    for( col_old = row_old->begin() ; col_old != row_old->end() ; col_old++ )
    {
      std::cout << *col_old << ' ' ;
    }
    std::cout << std::endl ;
  }

  // print new matrix
  std::cout << "new matrix: " << std::endl ;
  std::vector< std::vector< char > >::const_iterator row_new ;
  std::vector< char >::const_iterator                col_new ;
  for( row_new = newMat.begin() ; row_new != newMat.end() ; row_new++ )
  {
    for( col_new = row_new->begin() ; col_new != row_new->end() ; col_new++ )
    {
      std::cout << *col_new << ' ' ;
    }
    std::cout << std::endl ;
  }
}

int main( int argc, char** argv )
{
  std::vector< std::vector< char > > origMat ;

  // read in data from file
  std::ifstream f ;
  f.open( "2dmat.txt", std::ios::in ) ;
  if( f.is_open() )
  {
    std::vector< char > row ;

    std::string line = "" ;
    while( std::getline( f, line ) )
    {
      for( unsigned int i = 0 ; i < line.size() ; i++ )
      {
        if( line[i] == ' ' )
          continue ;
        else
          row.push_back( line[i] ) ;
      }
      origMat.push_back( row ) ;
      row.clear() ;
    }
  }
  f.close();

  rotate( origMat ) ;

  return 0 ;
}
