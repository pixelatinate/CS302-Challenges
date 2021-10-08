// Challenge 05: Graph Paths
// Given a directed graph, this code determines if 
//    there is a path between two nodes in the graph.
// COSC 302
// Swasti Mishra
// Katie and I talked this lab through together!

# include <list>
# include <vector>
# include <iostream>
using namespace std ;

// Constructs the matrix/directed graph from input
// A LOT of help from multiple stackoverflow answers: 
//    https://stackoverflow.com/questions/5493474/graph-implementation-c
//    https://stackoverflow.com/questions/45295807/unable-to-access-contents-of-file-scope-variable-from-another-function
class Graph{ 
  public:
    
    int V ;    
    list<int> *adjacents ;

    // Constructor
    Graph( int V ){
      this->V = V ;
      adjacents = new list<int>[ V ] ;
    }

    // Adds an edge to the graph
    void addEdge( int v , int w ){
      adjacents[v].push_back(w) ;
    }
    
    // Checks if the nodes are connected
    bool cComponents( int x , int y ){
      list<int> cC ;
      list<int>::iterator i ;
      bool *visited = new bool[ V ] ;
      
      // They're definitely connected
      if ( x == y ){
        return true ;
      }
      
      // Tells us if we've already been to a node before
      for ( int i = 0 ; i < V ; i++ ){
        visited[i] = false ;
      }
      
      // Updates the visited list
      visited[ x ] = true ;
      cC.push_back( x ) ;
      
      // Checks if our connected components lust has anything in it
      while ( !cC.empty() ){
        x = cC.front() ;
        cC.pop_front() ;
        
        for ( i = adjacents[x].begin() ; i != adjacents[x].end(); i++ ){
          if ( *i == y ){
            return true ;
          }
          
          if ( !visited[ *i ] ){
            visited[ *i ] = true ;
            cC.push_back( *i ) ;
          }
        }
      }
      return false ;
    }
} ;

int main( int argc, char *argv[] ){
  int firstCheck ;
  int secondCheck ;
  int counter = 0 ;

  // Reads the input file
  while( cin >> firstCheck ){ 
    char firstVertex ;
    char secondVertex ; 
    char c ;
    vector<int> input ;
    vector<char> letters ;
    counter++ ;
    
    // Just prints a line 
    if( counter > 1 ){
      cout << "\n" ;
    }

    // Read in links 
    for( int i = 0 ; i < ( firstCheck * 2 ) ; i++ ){
      cin >> c ;
      int buff = ( c - 65 ) ;
      input.push_back( buff ) ;
    }
    cin >> secondCheck ;
    
    // Adds all remaining elements that need to be checked for edges
    for( unsigned i = 0 ; i < ( secondCheck * 2 ) ; i++ ){
      cin >> c ;
      letters.push_back( c ) ;
    }

    // Goes through input and adds edges
    Graph graph( input.size() ) ;
    for( unsigned i = 0 ; i < input.size() ; i = ( i + 2 ) ){
      firstVertex = input.at( i ) ;
      secondVertex = input.at( i + 1 ) ;
      graph.addEdge( firstVertex , secondVertex ) ;
    }

    // Prints output
    for( int j = 0; j < letters.size() ; j = ( j + 2 ) ){
      firstVertex = ( letters.at( j ) - 65 ) ;
      secondVertex = ( letters.at( j + 1 ) - 65 ) ;
      if( ( graph.cComponents( firstVertex, secondVertex ) ) == true ){
        cout << "In Graph " << counter << " there is a path from " << letters.at(j) << " to " << letters.at(j+1) <<"\n" ; 
      }
      if( ( graph.cComponents( firstVertex, secondVertex ) ) == false ){
        cout << "In Graph " << counter << " there is no path from " << letters.at(j) << " to " << letters.at(j+1) << "\n" ;
      }
    }
  } 
  return 0;
}