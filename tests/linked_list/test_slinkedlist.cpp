#include "linked_list/SLinkedList.h"
using namespace std;

int main() {
    cout << "=== Test SinglyLinkedList ===\n\n";
    SLinkedList list;
    for (int i = 0; i < 10; ++i) {
        list.add(i);
    }
    assert(list.get(9) == list.removeAt(9));
    cout << list.toString();
    cout << endl;
    // ==== Test add(e) ====
    /*
    cout << "--- Test Lab ---" << endl;
    int size = 10;
    for (int index = 0; index < size; index++) {
        list.add(list.size(), index);
    }
    cout << list.toString();
    */
    cout << "--- Test Lab ---" << endl;
    list.add(0);
    for (int i= 0; i< 10; i++) {
        list.add(list.size() - 1, list.size());
    }
    cout << list.toString();
    cout << endl;

    cout << "--- Test add(e) ---\n";
    list.add(10);
    list.add(20);
    list.add(30);
    cout << "After add(10,20,30): " << list.toString() << endl; // [10]->[20]->[30]
    list.add(40);
    list.add(50);
    cout << "After add(40,50): " << list.toString() << endl;    // [10]->[20]->[30]->[40]->[50]

    // ==== Test add(index,e) ====
    cout << "\n--- Test add(index,e) ---\n";
    list.add(0, 99);   // chèn đầu
    cout << "After add(0,99): " << list.toString() << endl;
    list.add(3, 77);   // chèn giữa
    cout << "After add(3,77): " << list.toString() << endl;
    list.add(list.size(), 88); // chèn cuối
    cout << "After add(size(),88): " << list.toString() << endl;

    // ==== Test removeAt ====
    cout << "\n--- Test removeAt(index) ---\n";
    cout << "Removed at 0: " << list.removeAt(0) << endl;
    cout << "List: " << list.toString() << endl;
    cout << "Removed at middle: " << list.removeAt(2) << endl;
    cout << "List: " << list.toString() << endl;
    cout << "Removed at last: " << list.removeAt(list.size()-1) << endl;
    cout << "List: " << list.toString() << endl;

    // ==== Test removeItem ====
    cout << "\n--- Test removeItem(value) ---\n";
    cout << "Remove 20? " << (list.removeItem(20) ? "Yes" : "No") << endl;
    cout << "List: " << list.toString() << endl;
    cout << "Remove 999? " << (list.removeItem(999) ? "Yes" : "No") << endl;
    cout << "List: " << list.toString() << endl;
    list.add(20); list.add(20);
    cout << "Add duplicate 20s: " << list.toString() << endl;
    cout << "Remove first 20: " << (list.removeItem(20) ? "Yes" : "No") << endl;
    cout << "List: " << list.toString() << endl;

    // ==== Test empty & size ====
    cout << "\n--- Test empty() & size() ---\n";
    cout << "Size: " << list.size() << endl;
    cout << "Empty? " << (list.empty() ? "Yes" : "No") << endl;
    list.clear();
    cout << "After clear: " << list.toString() << endl;
    cout << "Size: " << list.size() << ", Empty? " << (list.empty() ? "Yes" : "No") << endl;

    // ==== Test get ====
    cout << "\n--- Test get(index) ---\n";
    list.add(1); list.add(2); list.add(3);
    cout << "List: " << list.toString() << endl;
    cout << "get(0): " << list.get(0) << endl;
    cout << "get(1): " << list.get(1) << endl;
    cout << "get(2): " << list.get(2) << endl;

    // ==== Test indexOf & contains ====
    cout << "\n--- Test indexOf & contains ---\n";
    cout << "Index of 2: " << list.indexOf(2) << endl;
    cout << "Index of 99: " << list.indexOf(99) << endl;
    cout << "Contains 3? " << (list.contains(3) ? "Yes" : "No") << endl;
    cout << "Contains 99? " << (list.contains(99) ? "Yes" : "No") << endl;

    cout << "=== Test Iterator for SLinkedList ===\n";

    SLinkedList sll;
    sll.add(1);
    sll.add(2);
    sll.add(3);

    // --- Test Constructor ---
    cout << "\n--- Test Constructor ---\n";
    SLinkedList::Iterator itA = sll.begin();
    cout << "*itA: " << *itA << endl;   // 1

    SLinkedList::Iterator itB = sll.end();
    cout << "itB == end()? " << (itB != sll.end() ? "No" : "Yes") << endl;

    try {
        cout << *itB << endl;   // phải ném lỗi vì end()
    } catch (out_of_range& e) {
        cout << "Caught exception: " << e.what() << endl;
    }

    // --- Test operator= ---
    cout << "\n--- Test operator= ---\n";
    SLinkedList::Iterator it1 = sll.begin();
    SLinkedList::Iterator it2;
    it2 = it1;   // gán
    cout << "*it1 before assign: " << *it1 << endl;
    cout << "*it2 after assign: " << *it2 << endl;

    // --- Test operator* ---
    cout << "\n--- Test operator* ---\n";
    SLinkedList::Iterator it3 = sll.begin();
    cout << "*it3: " << *it3 << endl;   // 1
    ++it3;
    cout << "*it3 after ++: " << *it3 << endl;   // 2
    ++it3;
    cout << "*it3 now: " << *it3 << endl;   // 3

    // --- Test operator!= ---
    cout << "\n--- Test operator!= ---\n";
    SLinkedList::Iterator it4 = sll.begin();
    SLinkedList::Iterator it5 = sll.begin(); ++it5;
    cout << "it4 != it5? " << (it4 != it5 ? "Yes" : "No") << endl;   // Yes
    ++it4;
    cout << "Now it4 != it5? " << (it4 != it5 ? "Yes" : "No") << endl; // No

    // --- Test ++it (prefix) ---
    cout << "\n--- Test ++it ---\n";
    SLinkedList::Iterator it6 = sll.begin();
    cout << "Start: " << *it6 << endl;   // 1
    ++it6;
    cout << "After ++it: " << *it6 << endl; // 2
    ++it6;
    cout << "After ++it: " << *it6 << endl; // 3
    try {
        ++it6; // vượt end
        cout << *it6 << endl; // không được chạy tới đây
    } catch (out_of_range& e) {
        cout << "Caught exception: " << e.what() << endl;
    }

    // --- Test it++ (postfix) ---
    cout << "\n--- Test it++ ---\n";
    SLinkedList::Iterator it7 = sll.begin();
    cout << *it7++ << endl; // in 1, rồi nhảy tới 2
    cout << *it7++ << endl; // in 2, rồi nhảy tới 3
    cout << *it7++ << endl; // in 3, rồi nhảy tới end
    try {
        cout << *it7 << endl; // end -> phải throw
    } catch (out_of_range& e) {
        cout << "Caught exception: " << e.what() << endl;
    }

    return 0;
}

/*
Compile & run:
g++ -I"include/linked list" src/SLinkedList.cpp tests/test_slinkedlist.cpp -o test_sll
./test_sll
*/

/*
g++ -I"include/linked list" src/SLinkedList.cpp tests/test_slinkedlist.cpp -o test_sll
./test_sll
*/