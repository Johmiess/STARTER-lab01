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
        // std::cout << new_node -> info << std::endl;
        last -> next = new_node;
        last = last -> next; 
        src = src -> next;
    }
    tail = last; 
}


// destructor deletes all nodes
IntList::~IntList() {
    Node* temp = head;
    while(temp){
        Node* to_del = temp;
        temp = temp -> next;
        delete to_del;
    }
    head = nullptr;
    tail = nullptr;
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
    if(!head) return 0;
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
    tail -> next = end; 
    tail = end;
    }
    else{
    head = end;
    tail = end;
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
    if(this == &source) return *this;
    Node* temp = head; 
    while(temp){
        Node* t_d = temp;
        temp = temp -> next;
        delete t_d;
    }
    head = nullptr;
    tail = nullptr;
    print();
    source.print();
    std::cout << std::endl;

    if(source.head == nullptr){
        return *this;
    }

    head = new Node;
    head -> info = source.head -> info;
    head -> next = nullptr;
    tail = head; // Fix: Update tail to point to the new node
    Node* src = source.head -> next;
    print();
    while(src){
        push_back(src -> info);
        src = src -> next;
    }
    print();
    return *this;
}

// constructor sets up empty list
IntList::IntList(){
    head = nullptr;
    tail = nullptr;
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

