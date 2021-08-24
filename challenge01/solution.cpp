// Challenge 01: Rotating Arrays
// This lab rotates a list of a few numbers to the left or right
// COSC 302 
// Swasti Mishra
// Help from Katie Nuchols and a TA I don't know the name of yet!
// Also Clark Hathaway talked through some of the math with me.

# include <iostream> 
# include <sstream>
using namespace std ;

int main( int argc, char *argv[] ){
    
    int values ;
    int rotations ;
    char direction ;
    // Declaring variables
    
    while ( cin >> values >> rotations >> direction ){
        // Reading in the commands 

        int array[ values ] ;
        // Declaring the array here so that it can initialize with the value

        for ( int temp , i = 0 ; ( i < values ) && ( cin  >> temp ) ; i++ ){
            array[ i ] = temp ; 
        }
        // Reading in the array line
    
        int start = ( rotations % values ) ;
        // Doing a little math here so we don't have to do it later,
        //      this tells us where we need to start counting from

        if ( direction == 'L' ){
            int counter = 0 ;
            for ( int i = 0 ; i < values ; i++ ) {
                cout << ( array[ ( i + start ) % values ] ) ;
                // Using start, starts counting from the start value and
                //      then wraps around 

                counter++ ;
                if ( counter < 5 ){
                    cout << " " ;
                }
                // Adds spaces as needed
            }
            cout << "\n" ;
        }
        // For rotating left
        
        else if ( direction == 'R' ){
            int counter = 0 ;
            for ( int i = 0 ; i < values ; i++ ) {
                cout << ( array[ ( i + values - start ) % values ] ) ;
                // Using start, starts counting from there and then
                //      then wraps around

                counter++ ;
                if ( counter < 5 ){
                    cout << " " ;
                }
                // Adds spaces as needed
            }
            cout << "\n" ;
        }
        // Basically instead of actually doing anything to an array, 
        //      I'm just printing it starting from where we want to 
        //      instead of the beginning. This one is for rotating right.
    }

    return 0;
}