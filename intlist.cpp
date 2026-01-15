// intlist.cpp
// Implements class IntList
// YOUR NAME(S), AND DATE
// John Yang, 1/14/2026

#include "intlist.h"

#include <iostream>
using std::cout;

// copy constructor
IntList::IntList(const IntList& source) {
    if(source.head == nullptr){
        head = nullptr;
        return;
    }
    // 1 2 3 4
    // we make a node pointer to src head, and make a copy of that head for curr linkedlist
    Node* src = source.head;
    head = new Node;
    head -> info = src -> info;
    head -> next = nullptr;
    Node* last = head;
    src = src -> next;
    while(src){
        Node* new_node = new Node; 
        new_node -> info = src -> info;
        last -> next = new_node;
        last = last -> next; 
        src = src -> next;
    }
}


// destructor deletes all nodes
IntList::~IntList() {
    Node* temp = head;
    while(temp){
        Node* to_del = temp;
        temp = temp -> next;
        delete to_del;
    }
}


// return sum of values in list
int IntList::sum() const {
    if(!head) return 0;
    int count = 0;
    Node* temp = head; 
    while(temp){
        count += temp -> info;
        temp = temp -> next;
    }
    return count;
}

// returns true if value is in the list; false if not
bool IntList::contains(int value) const {
    if(!head) return false; 
    Node* temp = head; 
    while(temp){
        if(temp -> info == value) return true;
        temp = temp -> next;
    }
    return false;
}

// returns maximum value in list, or 0 if empty list
int IntList::max() const {
    if(!head) return 0;
    int max = head -> info;
    Node* temp = head -> next; 
    while(temp){
        if(temp -> info > max){
            max = temp -> info;
        }
        temp = temp -> next;
    }
    return max;
    
}

// returns average (arithmetic mean) of all values, or
// 0 if list is empty
double IntList::average() const {
    double total_val = 0;
    double total_count= 0;
    Node* temp = head; 
    while(temp){
        total_val += temp -> info; 
        total_count += 1;
        temp = temp -> next;
    }
    return total_val/total_count;
}

// inserts value as new node at beginning of list
void IntList::push_front(int value) {
    Node* front = new Node;
    front -> next = head; 
    front -> info = value;
    head = front; 

}

// append value at end of list
void IntList::push_back(int value) {
    Node* end = new Node; 
    end -> info = value; 
    end -> next = nullptr;
    if(head){
        Node* temp = head; 
    while(temp -> next){    
        temp = temp -> next; 
    }
    temp -> next = end; 
    }
    else{
    head = end;
    }
}

// return count of values
int IntList::count() const {
   Node* temp = head; 
   int count = 0;
   while(temp){
    count += 1;
    temp = temp -> next;
   }
   return count;
}


//Assignment operator should copy the list from the source
//to this list, deleting/replacing any existing nodes
IntList& IntList::operator=(const IntList& source){
    IntList copy = IntList(source);
    return copy;
}

// constructor sets up empty list
IntList::IntList(){
    head = nullptr;
    //IMPLEMENT THIS 
}


// DO NOT CHANGE ANYTHING BELOW (READ IT THOUGH)

// print values enclose in [], separated by spaces
void IntList::print() const {
    Node *n = head;
    cout << '[';
    while (n) {
        cout << n->info;
        if (n->next)
            cout << " ";
        n = n->next;
    }
    cout << ']';
}

