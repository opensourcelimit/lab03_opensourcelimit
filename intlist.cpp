// intlist.cpp
// Implements class IntList
// YOUR NAME(S), AND DATE

#include "intlist.h"

#include <iostream>
using std::cout;

// copy constructor
IntList::IntList(const IntList& source) {
    //IMPLEMENT THIS
    Node* traverse = source.first;
    while(traverse){
    Node* copyNode = new Node;
    copyNode->info = traverse->info;
    append(copyNode->info);
    traverse = traverse->next;
    }
}

// destructor deletes all nodes
IntList::~IntList() {
 Node* traverse = first;
 while(traverse){
    Node* destroy = traverse;
    traverse = traverse->next;
    delete destroy;
 }
 first = nullptr;

}


// return sum of values in list
int IntList::sum() const {
   int sum = 0;
   for(Node* traverse = first; traverse != nullptr; traverse = traverse->next){
     sum += traverse->info;

   }


   return sum;
}

// returns true if value is in the list; false if not
bool IntList::contains(int value) const {
   Node* traverse = first;
   while(traverse){
       if(traverse->info ==  value){ return true;}
    traverse = traverse->next;
    }

   return false;
}

// returns maximum value in list, or 0 if empty list
int IntList::max() const {
    if(first == nullptr){return 0;}
    Node* traverse = first->next;
    int max = first->info;
    
    while(traverse){
    if(traverse->info > max){ max = traverse->info;}
     traverse = traverse->next;
    }

    return max; // REPLACE THIS NON-SOLUTION
}

// returns average (arithmetic mean) of all values, or
// 0 if list is empty
double IntList::average() const {
    if(first == nullptr){return 0;}
   double average = static_cast<double>(sum())/count();
   return average;// REPLACE THIS NON-SOLUTION
}

// inserts value as new node at beginning of list
void IntList::insertFirst(int value) {
   Node* newNode = new Node;
   newNode->info = value;

   newNode->next = first;
   first = newNode;
}

//Assignment operator should copy the list from the source
//to this list, deleting/replacing any existing nodes
IntList& IntList::operator=(const IntList& source){
    //IMPLEMENT
    return *this;
}



// DO NOT CHANGE ANYTHING BELOW (READ IT THOUGH)

// constructor sets up empty list
IntList::IntList() : first(0) { }


// append value at end of list
void IntList::append(int value) {
    if (first == 0) { // empty list
        first = new Node;
        first->info = value;
        first->next = 0;
    }
    else {
        Node *n = first;
        while (n->next) // not last node yet
            n = n->next;
        n->next = new Node;
        n->next->info = value;
        n->next->next = 0;
    }
}

// print values enclose in [], separated by spaces
void IntList::print() const {
    Node *n = first;
    cout << '[';
    while (n) {
        cout << n->info;
        if (n->next)
            cout << " ";
        n = n->next;
    }
    cout << ']';
}

// return count of values
int IntList::count() const {
    int result = 0;
    Node *n = first;
    while (n) {
        ++result;
        n = n->next;
    }
    return result;
}
