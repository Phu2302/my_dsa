#include "array/ArrayList.h"
#include <iostream>
using namespace std;

int main() {
    ArrayList arr;
    cout << "=== Test ArrayList ===\n\n";

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
    ArrayList arr2(arr);
    cout << "Original: " << arr.toString() << endl;
    cout << "Copy: " << arr2.toString() << endl;

    // ==== Test operator= ====
    cout << "\n--- Test operator= ---\n";
    ArrayList arr3;
    arr3 = arr;
    cout << "Assigned arr3 = arr: " << arr3.toString() << endl;


    // ==== Test Iterator ====
    cout << "\n=== Test Iterator ===\n";

    // Test operator* and ++it
    cout << "--- Test operator* & ++it ---\n";
    ArrayList arr4;
    arr4.add(10); arr4.add(20); arr4.add(30);
    for (auto it = arr4.begin(); it != arr4.end(); ++it) {
        cout << *it << " ";  // 10 20 30
    }
    cout << endl;

    // Test it++ (post-increment)
    cout << "--- Test it++ ---\n";
    auto it1 = arr4.begin();
    cout << *it1++ << endl;   // in 10, rồi tiến tới 20
    cout << *it1 << endl;     // in 20
    cout << *it1++ << endl;   // in 20, rồi tiến tới 30

    // Test --it (pre-decrement) from end
    cout << "--- Test --it ---\n";
    auto it2 = arr4.end(); // cursor = count
    --it2;                 // trỏ 30
    cout << *it2 << endl;  // 30
    --it2;                 // trỏ 20
    cout << *it2 << endl;  // 20

    // Test it-- (post-decrement)
    cout << "--- Test it-- ---\n";
    auto it3 = arr4.end();
    auto old = it3--;       // old = end(), it3 = phần tử cuối
    cout << (old != arr4.end() ? "old not end" : "old is end") << endl; // old là end
    cout << *it3 << endl;   // 30
    it3--;                  // lùi về 20
    cout << *it3 << endl;   // 20

    // ==== Test Iterator constructor ====
    cout << "\n--- Test Iterator Constructor ---\n";
    ArrayList arr5;
    arr5.add(100);
    arr5.add(200);

    try {
        ArrayList::Iterator itA(&arr5, 0);   // hợp lệ
        cout << "*itA (index 0): " << *itA << endl;  // in 100

        ArrayList::Iterator itB(&arr5, 2);   // hợp lệ (end)
        cout << "itB == arr5.end()? " << (itB != arr5.end() ? "No" : "Yes") << endl;

        ArrayList::Iterator itC(&arr5, -1);  // ❌ không hợp lệ
        cout << *itC << endl; // sẽ không chạy tới đây
    } catch (out_of_range& e) {
        cout << "Caught exception (invalid index): " << e.what() << endl;
    }

    // ==== Test Iterator operator= ====
    cout << "\n--- Test Iterator operator= ---\n";
    ArrayList::Iterator itX = arr5.begin();
    ArrayList::Iterator itY = arr5.end();

    cout << "*itX before assign: " << *itX << endl;  // 100
    itY = itX;   // gán trạng thái
    cout << "*itY after assign: " << *itY << endl;   // 100

    return 0;
}

/*
g++ -I"include/array" src/ArrayList.cpp tests/test_arraylist.cpp -o test_array
./test_array

*/