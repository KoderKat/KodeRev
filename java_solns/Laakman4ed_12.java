/**
*   Problem Source: Cracking the Coding Interview 4th edition by Gayle Laakman
*   Reverse a c-string.
*/

public class Laakman4ed_12
{
  public static void main( String[] args )
  {
    if( args.length < 1 )
    {
      System.out.println( "ERROR: Run as java Laakman4ed_12 <stringToReverse>" ) ;
      System.exit( 0 ) ;
    }
  
    String orig    = args[0] ;
    String reverse = "" ; 

    String tmp = orig + '\0' ;
    int size   = tmp.length() ;
 
    int i = size - 1 ; // equality catches the trailing \0
    while( i >= 0 )
    {
      System.out.println( "Char = " + tmp.charAt(i) ) ;
  
      reverse += tmp.charAt(i) ;
 
      i = i - 1 ;
    }
  
    System.out.println( "Orig     : " + orig ) ; 
    System.out.println( "Reverse  : " + reverse ) ;
  }
}
