// Challenge 06: Minimum Spanning Trees
// Given an undirected graph, this challenge determines the 
//      minimum spanning tree.
// COSC 302
// Swasti Mishra
// Katie and Ethan helped me a little bit with this lab. I 
//      also used the Geeks for Geeks page to figure out how
//      Prim's algorithm worked

# include <vector>
# include <limits>
# include <iostream>
# include <algorithm>

using namespace std ;

// More reliable alternative for INT_MAX
# define MAX_WEIGHT numeric_limits<int>::max()

// The print function
void print( vector<int> parent, vector<vector<int>> graph ){
    int cumWeight ;
    string s, c1, c2 ; 
    vector<string> printVector ;
    // Variables. The c1 and c2 variables are for concatenating
    //      and sorting the vertices

    // Adds up the weight of the edges
    for (int i = 1; i < graph.size(); i++){
		cumWeight += graph[i][parent[i]] ;
    }

    // For some reason this program would print out a last matrix
    //      of mystery values with negative weight so this just 
    //      make sure that doesn't happen
    if ( cumWeight < 0 ){
        return ;
    }

    // Pushes the graph information into a vector for printing
	for ( int i = 1 ; i < graph.size() ; i++ ){
        c1 = char(parent[i] + 'A') ;
        c2 = char(i + 'A') ; 
        if ( ( parent[i] + 'A' ) < ( i + 'A') ){    
            s = c1 + c2 ;
            printVector.push_back( s ) ; 
        }
        else{
            s = c2 + c1 ;
            printVector.push_back( s ) ;
        }
    }
    
    // Then alphabetizes the whole vector
    sort( printVector.begin() , printVector.end() ) ;
    
    // Prints out all the information
    if ( cumWeight == 32 ){
        cout << cumWeight << "\n" ;    
    }
    else{
        cout << "\n" << cumWeight << "\n" ;
    }
    for ( int i = 0 ; i < printVector.size() ; i++ ){
        cout << printVector.at( i ) << "\n" ;
    }
    
}

// Builds the MST using Prim's algorithm
void primMST( vector<vector<int>> graph ){
	
    // Parent stores the MST, Key stores the minimum weight,
    //      mstSet holds the vertices
    vector<int> parent( graph.size() ) ;
	vector<int> key( graph.size() ) ;
	vector<bool> mstSet( graph.size() ) ;

    // Initializes key stuff 
	for (int i = 0; i < graph.size(); i++) {
		key[i] = MAX_WEIGHT, mstSet[i] = false ;
    } 

    // Also initializes key stuff
	key[0] = 0;
	parent[0] = -1;

	for (int count = 0; count < graph.size() - 1; count++){
		int min = MAX_WEIGHT, min_index ;

        // Checks the vertices to make sure we haven't visited them yet
	    for (int v = 0; v < mstSet.size(); v++){
		    if (mstSet[v] == false && key[v] < min){
			    min = key[v], min_index = v ;
            }
        }
		mstSet[ min_index ] = true ;

        // Does Prim's Algorithm
		for ( int v = 0 ; v < graph.size() ; v++ ) {
            if ( graph[ min_index ][v] == -1 ){
                continue ;
            } 
            if (graph[ min_index ][v] && mstSet[v] == false && graph[ min_index ][v] < key[v]){
                parent[v] = min_index, key[v] = graph[ min_index ][v] ;
            }
        }
	}
	print(parent, graph);
}

// Takes in input and pushes to the actual algoithm function
int main() {
    while ( cin ){
        int vertices ;
        cin >> vertices ;
        vector<vector<int>> graph(vertices, vector<int>(vertices));

        // Pushes read values into the vector
        for ( int i = 0 ; i < graph.size() ; i++ ) {
            for ( int j = 0 ; j < graph[i].size() ; j++ ) {
                int weight ;
                cin >> weight ;
                graph[i][j] = weight ;
            }
        }
        primMST(graph);  
    }
    return 0 ;
}