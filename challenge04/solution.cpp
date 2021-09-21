// Challenge 04: Kth Smallest Numbers
// This code reads in a number of ints and
//      finds the smallest without sorting
//      or doing k scans
// COSC 302
// Swasti Mishra
// Katie and I discussed this one too, though I think she opted not to use
//      the heap. 

// Libraries
# include <queue>
# include <vector>
# include <iostream>

using namespace std ;


// The function that finds the desired element in the given set
int find( int set[] , int first , int last , long unsigned int desired ){
    
    // I decided to use the STL set!
    priority_queue<int> pq ; 

    int x = ( ( last - first ) + 1 ) ;
    
    // Puts elements on the heap
    for ( int i = 0 ; i < x ; i++ ) {   
        if ( pq.size() == desired ){  
            if ( pq.top() > set[ i ] ) {
                pq.pop() ;
                pq.push( set[ i ] ) ;
            }
        }
        else{ 
            pq.push( set[ i ] ) ;
        }
    }
    // Gets the correct element
    return pq.top() ;
}

// Checks whether the input array is a max heap
char isMaxHeap( int set[] , int numElements ){
    for ( int i = 0 ; i <= ( ( numElements - 2 )/ 2 ) ; i++ ){
        
        // Special case for when the input only has one element 
        if ( numElements == 1 ){
            return 'Y' ;
        }

        // Calculates for the rest of the cases 
        if  ( ( set[ ( 2 * i ) + 1 ] > set[ i ] ) ||
            ( ( set[ ( 2 * i ) + 2 ] > set[ i ] ) && 
            ( ( ( 2 * i ) + 2 ) < numElements ) )
            ){
            return 'N' ;
        }
    }

    // If passed other cases, returns that the array is a max heap
    return 'Y' ;
}

// Reads in the file
int main(int argc, char *argv[]) {
    
    // Saves how many numbers are in the set and which element we
    //      are looking for
    int numElements ;
    long unsigned int desired ;

    // Pushes the elements into an array
    while( cin >> numElements >> desired ){
        int set[ numElements ] ;
        for ( int i = 0 ; i < numElements ; i++ ){
            cin >> set[ i ] ;
        }

        // Outputs whether its a max heap and what the element is
        cout << isMaxHeap( set , numElements ) << "  " 
        << find( set , 0 , numElements - 1 , desired ) << "\n" ;
    }
    
    return 0 ; 
}
