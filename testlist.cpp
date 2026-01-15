// testlist.cpp
// Tests intlist.cpp

#include "intlist.h"

#include <cstdlib> // provides atoi
#include <iostream>
#include <cassert>
using namespace std;

void test_empty_list() {
    cout << "--- Testing Empty List ---" << endl;
    IntList empty;
    assert(empty.count() == 0);
    assert(empty.sum() == 0);
    assert(empty.max() == 0);
    assert(empty.average() == 0.0);
    assert(empty.contains(1) == false);
    cout << "PASSED: Empty list checks" << endl;
}

void test_deep_copy_assignment() {
    cout << "\n--- Testing Assignment Operator (Deep Copy) ---" << endl;
    IntList list1;
    list1.push_back(10);
    list1.push_back(20);
    
    IntList list2;
    list2 = list1; // Assignment

    cout << "List 1: "; list1.print(); cout << endl;
    cout << "List 2 (assigned from 1): "; list2.print(); cout << endl;

    // Modify list2 and ensure list1 is untouched
    list2.push_back(30);
    cout << "Modified List 2 (added 30): "; list2.print(); cout << endl;
    cout << "List 1 (should be 10 20): "; list1.print(); cout << endl;

    assert(list2.count() == 3);
    assert(list1.count() == 2);
    assert(list1.contains(30) == false);
    cout << "PASSED: Assignment Deep Copy" << endl;
}

void test_assignment_edge_cases() {
    cout << "\n--- Testing Assignment Edge Cases ---" << endl;
    // 1. Assign Empty to Valid
    IntList list1;
    list1.push_back(5);
    IntList empty;
    list1 = empty;
    assert(list1.count() == 0);
    cout << "PASSED: Assign Empty to Valid" << endl;

    // 2. Assign Valid to Empty
    IntList list2;
    list2.push_back(99);
    empty = list2;
    assert(empty.count() == 1);
    assert(empty.contains(99));
    cout << "PASSED: Assign Valid to Empty" << endl;

    // 3. Self Assignment
    list2 = list2;
    assert(list2.count() == 1);
    assert(list2.contains(99));
    cout << "PASSED: Self Assignment" << endl;
}

void test_copy_constructor() {
    cout << "\n--- Testing Copy Constructor (Deep Copy) ---" << endl;
    IntList list1;
    list1.push_back(100);
    list1.push_back(200);

    IntList list2(list1); // Copy Constructor

    list2.push_front(50); // Modify copy
    
    assert(list2.count() == 3);
    assert(list1.count() == 2);
    assert(!list1.contains(50));
    
    cout << "PASSED: Copy Constructor Deep Copy" << endl;
}

// creates two lists (one empty), and does simple tests of list methods
int main(int argc, char *argv[]) {

    test_empty_list();
    test_deep_copy_assignment();
    test_assignment_edge_cases();
    test_copy_constructor();

    cout << "\n--- Running Original Main Logic ---" << endl;
    IntList list1, list2;
    int first = 0, second = 0, last = 0, initial_size;
    
    cout << "passed constructor" << endl;

    // append command line arguments to list1
    if (argc < 2) {
        cout << "Note: No args provided for interactive part test (skipping cmd line args test)" << endl;
    } else {
        initial_size = argc - 1;
        for (int i = 1; i < argc; i++) {
            int value = atoi(argv[i]);
            list1.push_back(value);
            if (i == 1)
                first = value;
            if (i == 2)
                second = value;
            if (i == initial_size)
                last = value;
        }

        cout << "push back" << endl;

        // print and test methods for list1
        cout << "List 1: \n   ";
        list1.print();
        cout << endl << "   count: " << list1.count() << endl;
        int sum = list1.sum();
        cout << "   sum: " << sum << endl;
        cout << "   contains " << first << " ? "
            << (list1.contains(first)? "yes" : "no") << endl;
        cout << "   contains " << second << " ? "
            << (list1.contains(second)? "yes" : "no") << endl;
        cout << "   contains " << last << " ? "
            << (list1.contains(last)? "yes" : "no") << endl;
        cout << "   contains " << sum << " ? "
            << (list1.contains(sum)? "yes" : "no") << endl;
        cout << "   max: " << list1.max() << endl;
        cout.setf(ios::fixed);
        cout.setf(ios::showpoint);
        cout.precision(3);
        cout << "   average: " << list1.average() << endl;
        cout << "   List after push_front(sum): \n   ";
        list1.push_front(sum);
        list1.print();
        cout << endl;
    }

    // test methods for empty list2 (just need one contains test though)
    cout << "Empty list 2: \n   ";
    list2.print();
    cout << endl << "   count: " << list2.count() << endl;
    cout << "   sum: " << list2.sum() << endl;
    cout << "   contains 1 ? "
        << (list2.contains(1)? "yes" : "no") << endl;
    cout << "   max: " << list2.max() << endl;
    cout << "   average: " << list2.average() << endl;
    cout << "   List 2 after push_front(3), then push_front(1): \n   ";
    list2.push_front(3);
    list2.push_front(1);
    list2.print();
    cout << endl;

    cout << "fin print" << endl;
   
    return 0;
}
