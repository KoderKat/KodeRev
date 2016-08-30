#!/usr/bin/env python

'''
*   Problem Source: Cracking the Coding Interview 4th edition by Gayle Laakman
*   Reverse a c-string.
'''

import sys

############
#  DRIVER  #
############
def driver() :
  if( len( sys.argv ) < 2 ) :
    sys.exit( "ERROR: Run as ./1-2_laakman4ed.py <stringToReverse>" )

  orig    = sys.argv[1] + '\0'
  reverse = ""

  i = len( orig ) -1
  while( i >= 0 ) :
    print "Char = " + orig[i]
    reverse += orig[i]
    i = i - 1

  print "Orig     : " + orig
  print "Reverse  : " + reverse

########################
# THREAD OF EXECUTION  #
########################
driver()

