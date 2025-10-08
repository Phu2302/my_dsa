#include "linked_list/SLinkedList.h"
#include "lib.h"

template<typename T>
void testSLinkedListTemplate(const std::string& typeName) {
    SLinkedList<T> arr;
    cout << "=== Test SLinkedList<" << typeName << "> ===\n\n";

    // ==== Test add(e) ====
    cout << "--- Test add(e) ---\n";
    arr.add(10);
    arr.add(20);
    arr.add(30);
    cout << "After add(10,20,30): " << arr.toString() << endl;
    arr.add(40);
    arr.add(50);
    cout << "After add(40,50): " << arr.toString() << endl;

    // ==== Test add(index, e) ====
    cout << "\n--- Test add(index, e) ---\n";
    arr.add(0, 99);   // chèn đầu
    cout << "After add(0,99): " << arr.toString() << endl;
    arr.add(3, 77);   // chèn giữa
    cout << "After add(3,77): " << arr.toString() << endl;
    arr.add(arr.size(), 88); // chèn cuối
    cout << "After add(size(),88): " << arr.toString() << endl;

    // ==== Test get ====
    cout << "\n--- Test get(index) ---\n";
    cout << "get(0): " << arr.get(0) << endl;
    cout << "get(2): " << arr.get(2) << endl;
    cout << "get(" << arr.size()-1 << "): " << arr.get(arr.size()-1) << endl;

    // ==== Test set ====
    cout << "\n--- Test set(index, e) ---\n";
    arr.set(0, 111);
    cout << "After set(0,111): " << arr.toString() << endl;
    arr.set(2, 222);
    cout << "After set(2,222): " << arr.toString() << endl;
    arr.set(arr.size()-1, 333);
    cout << "After set(last,333): " << arr.toString() << endl;

    // ==== Test removeAt ====
    cout << "\n--- Test removeAt(index) ---\n";
    cout << "Removed at 0: " << arr.removeAt(0) << endl;
    cout << "List: " << arr.toString() << endl;
    cout << "Removed at 2: " << arr.removeAt(2) << endl;
    cout << "List: " << arr.toString() << endl;
    cout << "Removed at last: " << arr.removeAt(arr.size()-1) << endl;
    cout << "List: " << arr.toString() << endl;

    // ==== Test indexOf & contains ====
    cout << "\n--- Test indexOf & contains ---\n";
    cout << "Index of 30: " << arr.indexOf(30) << endl;
    cout << "Index of 999: " << arr.indexOf(999) << endl;
    cout << "Contains 20? " << (arr.contains(20) ? "Yes" : "No") << endl;
    cout << "Contains 999? " << (arr.contains(999) ? "Yes" : "No") << endl;

    // ==== Test size & empty ====
    cout << "\n--- Test size() & empty() ---\n";
    cout << "Size: " << arr.size() << endl;
    cout << "Empty? " << (arr.empty() ? "Yes" : "No") << endl;

    // ==== Test clear ====
    cout << "\n--- Test clear() ---\n";
    arr.clear();
    cout << "After clear: " << arr.toString() << endl;
    cout << "Size: " << arr.size() << ", Empty? " << (arr.empty() ? "Yes" : "No") << endl;

    // ==== Test copy constructor ====
    cout << "\n--- Test copy constructor ---\n";
    arr.add(1);
    arr.add(2);
    arr.add(3);
    SLinkedList<T> arr2(arr);
    cout << "Original: " << arr.toString() << endl;
    cout << "Copy: " << arr2.toString() << endl;

    // ==== Test operator= ====
    cout << "\n--- Test operator= ---\n";
    SLinkedList<T> arr3;
    arr3 = arr;
    cout << "Assigned arr3 = arr: " << arr3.toString() << endl;

    // ==== Test Iterator ====
    cout << "\n=== Test Iterator ===\n";

    SLinkedList<T> arr4;
    arr4.add(10); arr4.add(20); arr4.add(30);
    for (auto it = arr4.begin(); it != arr4.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    // Test it++
    auto it1 = arr4.begin();
    cout << *it1++ << endl;
    cout << *it1 << endl;

    // ==== Test Iterator Constructor ====
    cout << "\n--- Test Iterator Constructor ---\n";
    SLinkedList<T> arr5;
    arr5.add(100);
    arr5.add(200);

    try {
        typename SLinkedList<T>::Iterator itA = arr5.begin();
        cout << "*itA: " << *itA << endl;
        typename SLinkedList<T>::Iterator itB = arr5.end();
        cout << "itB == end()? " << (itB != arr5.end() ? "No" : "Yes") << endl;

        // Test invalid iterator by advancing past end
        typename SLinkedList<T>::Iterator itC = arr5.begin();
        for (int i = 0; i <= arr5.size(); ++i) ++itC; // Vượt quá end()
        cout << "*itC: " << *itC << endl; // Nên ném ngoại lệ
    } catch (std::out_of_range& e) {
        cout << "Caught exception: " << e.what() << endl;
    }

    // ==== Test Iterator operator= ====
    cout << "\n--- Test Iterator operator= ---\n";
    typename SLinkedList<T>::Iterator itX = arr5.begin();
    typename SLinkedList<T>::Iterator itY = arr5.end();

    cout << "*itX before assign: " << *itX << endl;
    itY = itX;
    cout << "*itY after assign: " << *itY << endl;

    // ==== Test front() & back() ====
    cout << "\n--- Test front() & back() ---\n";
    SLinkedList<T> arr6;
    try {
        arr6.front(); // Nên ném ngoại lệ vì danh sách rỗng
    } catch (std::out_of_range& e) {
        cout << "Caught exception on front(): " << e.what() << endl;
    }
    arr6.add(100);
    arr6.add(200);
    cout << "front(): " << arr6.front() << endl;
    cout << "back(): " << arr6.back() << endl;

    // ==== Test pop_front() & pop_back() ====
    cout << "\n--- Test pop_front() & pop_back() ---\n";
    cout << "pop_front(): " << arr6.pop_front() << endl;
    cout << "List after pop_front: " << arr6.toString() << endl;
    cout << "pop_back(): " << arr6.pop_back() << endl;
    cout << "List after pop_back: " << arr6.toString() << endl;

    try {
        arr6.pop_front(); // Nên ném ngoại lệ vì danh sách rỗng
    } catch (std::out_of_range& e) {
        cout << "Caught exception on pop_front(): " << e.what() << endl;
    }

    // ==== Test removeItem ====
    cout << "\n--- Test removeItem(e) ---\n";
    SLinkedList<T> arr7;
    arr7.add(10);
    arr7.add(20);
    arr7.add(10);
    cout << "Before removeItem(10): " << arr7.toString() << endl;
    cout << "removeItem(10): " << (arr7.removeItem(10) ? "Yes" : "No") << endl;
    cout << "After removeItem(10): " << arr7.toString() << endl;
    cout << "removeItem(999): " << (arr7.removeItem(999) ? "Yes" : "No") << endl;
    cout << "After removeItem(999): " << arr7.toString() << endl;

    cout << "\n=== END TEST ===\n\n";
}

void test_slinkedlist() {
    testSLinkedListTemplate<int>("int");  
}