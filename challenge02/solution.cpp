// Challenge 02: Closest Numbers
// This lab finds the two numbers with the smallest
//      difference between them
// COSC 302
// Swasti Mishra
// Katie and I talked through this lab together.

// Libraries
# include <vector>
# include <iostream>
# include <algorithm>

using namespace std ;

// Function
void print( vector <int> indices ) ;

int main( int argc, char *argv[] ) {
    
    // Variables
    int elements ;
    int numElements ; 

    // Reads in the number of expected elements
    while ( cin >> numElements ){
        
        // Variables
        vector <int> storage ;
        vector <int> indices ;

        // Puts the actual elements into a vector
        for ( int i = 0 ; i < numElements ; i++ ){
            cin >> elements ; 
            storage.push_back( elements ) ;
        }

        // Sorts the variables and finds the smallest difference so far
        sort( storage.begin() , storage.end() ) ;
        int currentMin = ( storage.at( 1 ) - storage.at( 0 ) ) ;

        // Calculates the differences between each adjacent element
        for ( int i = 1 ; i < numElements ; i++ ){
            currentMin = min( currentMin , ( storage.at( i ) - storage.at( i - 1 ) ) ) ;
        }

        // Pushes back the index of the elements with the smallest difference between them
        for ( int i = 0 ; i < ( numElements - 1 ) ; i++ ){
            if ( currentMin == ( storage.at( i + 1 ) - storage.at( i ) ) ){
                indices.push_back( storage.at( i ) ) ; 
                indices.push_back( storage.at( i + 1 ) ) ;
            }
        }
        print( indices ) ;
    }
    return EXIT_SUCCESS;
}

// Prints the indices
void print( vector <int> indices ){
    for ( unsigned int i = 0 ; i < indices.size() ; i++ ){
        if ( i < ( indices.size() - 1 ) ){
            cout << indices.at( i ) << " " ;
        }
        else{
            cout << indices.at( indices.size() - 1 ) << "\n" ;
        }
    }
}