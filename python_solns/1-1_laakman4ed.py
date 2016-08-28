#!/usr/bin/env python

'''
*   Problem Source: Cracking the Coding Interview 4th edition by Gayle Laakman
*   Prompt:
*     1.1 Implement an algorithm to determine if a string has all unique characters. What if you cannot use additional data structures?
'''

import sys

#################
#  CHECKUNIQUE  #
#################
# use a variable to store only unique characters
# from the input string.
# if the associated value is greater than 1,
# then return false for uniqueness question
# O(n) in the number of characters
def checkUnique( myString ) :
  result = True
  temp = ""

  #  iterate over string characters, insert into temp,
  #  else hit a duplicate
  for currChar in myString :
    if currChar in temp :
      result = False
      break
    else :
      temp += currChar

  return result ;

############
#  DRIVER  #
############
def driver() :
  if( not len( sys.argv ) > 1 ) :
    sys.exit( "ERROR: Please run as ./1-1_laakman4ed.py <stringToExamine>" )

  myString = sys.argv[1]
  result   = checkUnique( myString )

  print "String to test          :  " + myString
  print "Only unique characters? :  " + str( result )


########################
# THREAD OF EXECUTION  #
########################
driver()
