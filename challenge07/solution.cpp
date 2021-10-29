// Challenge 07: Adding List-Based Integers
// COSC302
// This lab adds up linked lists
// Swasti Mishra
// 10/28/21

# include <iostream> 
# include <string>
# include <algorithm>

using namespace std ;

typedef struct node_s {
    int i ;
    struct node_s *next ;
} Node ;

// List Class
class List {
    public:
        List() ;
        ~List() ;
        List& operator=( const List& );
        void push( int i );
        void print( Node* j ) ;
        Node *head;
        
} ;

// Constructor
List::List(){
    head = new Node;
}

// Destructor
List::~List(){
    Node *i , *n ;
    i = head -> next ;
    head -> next = nullptr ;
    while ( i != nullptr ) {
        n = i ;
        i = i -> next ;
        delete n ;
    }
    delete i ;
}

// Pushes values into the node.
// Referenced from an old file in a previous class.
void List::push( int i ){
    Node *n , *j ;
    j = head ;
    while ( j -> next != nullptr ) j = j-> next ;
    n = new Node ;
    n -> i = ( i ) ;
    n -> next = nullptr ;
    j -> next = n ;
}   

// Print Function
void List::print( Node* j ){
    j = head ;
    string out ;
    while( j != nullptr ){
        char c ;
        c = '0' + j -> i ;
        j = j -> next ;
        out += c ;
    }
    reverse ( out.begin(), out.end() ) ;
    out.pop_back() ;
    cout << out << '\n' ;
}   

// The sum function!
void sum ( Node* list1 , Node* list2 ) {
    List resulting ;
    string output ;
    int result = 0 ;
    int carry = 0 ;

    list1 = list1 -> next ;
    list2 = list2 -> next ;
    while( ( list1 != nullptr ) || ( list2 != nullptr ) ){
        
        // These two loops account for the lists being of
        //      different lengths 
        if ( list1 != nullptr ){
            result += ( list1 ->  i ) ;
            list1 = list1 -> next ; 
        }
        if ( list2 != nullptr ){
            result += ( list2 -> i ) ;
            list2 = list2 -> next ;
        }
        
        result = carry + result ;
        carry = 0 ;

        // Accounts for the numbers that need to be carried
        if ( result >= 10 ){
            resulting.push( result % 10 ) ;
            carry = result / 10 ;
        }
        else {
            resulting.push( result ) ;
        }

        // Resets the result to zero
        result = 0 ;
    }

    // If there is leftover in the carry, it appends it to the beginning
    if ( carry != 0 ){
        resulting.push( carry ) ;
    }

    // Sends to the print function
    resulting.print( resulting.head -> next ) ;
}

// Driver Function
int main(int argc, char *argv[]) {

    string firstString ;
    string secondString ;
    List list1 ;
    List list2 ;

    // Reads in the first string
    while ( cin >> firstString ){
        
        // Pushes into the first list
        reverse( firstString.begin(), firstString.end() ) ;
        for ( char c: firstString ){
            list1.push( c - '0' ) ;
        }   
        
        // Pushes into the second list
        cin >> secondString ;
        reverse( secondString.begin(), secondString.end() ) ;
        for ( char c: secondString ){
            list2.push( c - '0' ) ;
        }
        
        // Deletes the lists at the end of the loop    
        sum( list1.head , list2.head ) ;   
        list1.~List() ;
        list2.~List() ; 
    } 
    return 0 ;
}


