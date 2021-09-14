// Challenge 03: Palindrom Permutations
// This lab checks if its possible to make palindrome permutations
// COSC 302 
// Swasti Mishra

// Libraries
# include <iostream>
# include <unordered_map>

using namespace std ;

// This function does the heavy lifting by checking if there is a 
//    palindrome permutation
int palindromePermCheck( string phrase ){
  
  // Variables
  int oddCount = 0 ;
  unordered_map< char , int > map ;

  // Inserts the letters from the phrase into the map 
  for ( unsigned int i = 0 ; i < phrase.length() ; i++ ){
    if ( ( phrase.at( i ) != ' ' ) && ( phrase.at( i ) != '?' ) && ( phrase.at( i ) != '.' ) && ( phrase.at( i ) != '\n' ) ){
      map[ phrase.at( i ) ]++ ;
    }
  }

  // Searches for the number of odd letters
  for ( auto i = map.begin() ; i != map.end() ; i++ ){
    
    // Increments the number of odd letters
    if ( ( i->second ) % 2 != 0 ){
      oddCount++ ;
    }

    // Checks if there are an appropriate amount for a palindrome permutation
    if (oddCount >= 2){
      cout << "\"" << phrase << "\" is not a palindrome permutation\n" ; 
      return 0 ;
    }
  }
  
  // Otherwise, outputs that it is correct
  cout << "\"" << phrase << "\" is a palindrome permutation\n" ;
  return 0 ;
}

// Passes the line into the permutation palindrome checker
int main() {
  string phrase ;
  while ( getline( cin , phrase ) ){
    palindromePermCheck( phrase ) ;
  }
  
  return 0 ;
}