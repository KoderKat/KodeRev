public class Laakman4ed_11
{
  // O(n) in number of characters
  public static boolean find( String s, char c)
  {
    boolean result = false ;

    for( int i = 0 ; i < s.length() ; i++ )
    {
      if( s.charAt(i) == c )
        result = true ;
      else 
        result = false ;
    }

    return result ;
  }

  // use a string to store each unique character
  // O(n^2) in the number of characters
  public static boolean checkUnique( String myString )
  {
    boolean result = true ;

    // iterate over string characters
    // save unique characters to temp
    // if new char is in temp, it's a duplicate
    String temp = "" ;
    for( int i = 0 ; i < myString.length() ; i++ )
    {
      char currChar = myString.charAt(i) ;
      if( find( temp, currChar ) == true )
      {
        result = false ;
        break ;
      }
      else
        temp += currChar ;
    }

    return result ;
  }

  public static void main( String[] args ) 
  {
    if( args.length < 1 )
    {
      System.out.println( "ERROR: run as java Laakman4ed_11 <stringToExamine>" ) ;
      System.exit( 0 ) ;
    }

    String myString = args[ 0 ] ;
    boolean result  = checkUnique( myString  ) ;

    System.out.println( "String to test          :  " + myString ) ;
    System.out.println( "Only unique characters? :  " + result ) ;
  }
}
