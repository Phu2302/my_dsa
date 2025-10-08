#include "array/ArrayList.h"
#include "lib.h"

template <typename T>
void testArrayListTemplate() {
    ArrayList<T> arr;
    cout << "=== Test ArrayList<" << typeid(T).name() << "> ===\n\n";

    // ==== Test add(e) ====
    cout << "--- Test add(e) ---\n";
    arr.add((T)10);
    arr.add((T)20);
    arr.add((T)30);
    cout << "After add(10,20,30): " << arr.toString() << endl;
    arr.add((T)40);
    arr.add((T)50);
    cout << "After add(40,50): " << arr.toString() << endl;

    // ==== Test add(index, e) ====
    cout << "\n--- Test add(index, e) ---\n";
    arr.add(0, (T)99);   // chèn đầu
    cout << "After add(0,99): " << arr.toString() << endl;
    arr.add(3, (T)77);   // chèn giữa
    cout << "After add(3,77): " << arr.toString() << endl;
    arr.add(arr.size(), (T)88); // chèn cuối
    cout << "After add(size(),88): " << arr.toString() << endl;

    // ==== Test get ====
    cout << "\n--- Test get(index) ---\n";
    cout << "get(0): " << arr.get(0) << endl;
    cout << "get(2): " << arr.get(2) << endl;
    cout << "get(" << arr.size()-1 << "): " << arr.get(arr.size()-1) << endl;

    // ==== Test set ====
    cout << "\n--- Test set(index, e) ---\n";
    arr.set(0, (T)111);
    cout << "After set(0,111): " << arr.toString() << endl;
    arr.set(2, (T)222);
    cout << "After set(2,222): " << arr.toString() << endl;
    arr.set(arr.size()-1, (T)333);
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
    cout << "Index of 30: " << arr.indexOf((T)30) << endl;
    cout << "Index of 999: " << arr.indexOf((T)999) << endl;
    cout << "Contains 20? " << (arr.contains((T)20) ? "Yes" : "No") << endl;
    cout << "Contains 999? " << (arr.contains((T)999) ? "Yes" : "No") << endl;

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
    arr.add((T)1);
    arr.add((T)2);
    arr.add((T)3);
    ArrayList<T> arr2(arr);
    cout << "Original: " << arr.toString() << endl;
    cout << "Copy: " << arr2.toString() << endl;

    // ==== Test operator= ====
    cout << "\n--- Test operator= ---\n";
    ArrayList<T> arr3;
    arr3 = arr;
    cout << "Assigned arr3 = arr: " << arr3.toString() << endl;

    // ==== Test Iterator ====
    cout << "\n=== Test Iterator ===\n";

    ArrayList<T> arr4;
    arr4.add((T)10); arr4.add((T)20); arr4.add((T)30);
    for (auto it = arr4.begin(); it != arr4.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    // Test it++
    auto it1 = arr4.begin();
    cout << *it1++ << endl;
    cout << *it1 << endl;

    // Test --it
    auto it2 = arr4.end();
    --it2;
    cout << *it2 << endl;

    // Test it--
    auto it3 = arr4.end();
    auto old = it3--;
    cout << (old != arr4.end() ? "old not end" : "old is end") << endl;
    cout << *it3 << endl;

    // ==== Test Iterator Constructor ====
    cout << "\n--- Test Iterator Constructor ---\n";
    ArrayList<T> arr5;
    arr5.add((T)100);
    arr5.add((T)200);

    try {
        typename ArrayList<T>::Iterator itA(&arr5, 0);
        cout << "*itA: " << *itA << endl;
        typename ArrayList<T>::Iterator itB(&arr5, 2);
        cout << "itB == end()? " << (itB != arr5.end() ? "No" : "Yes") << endl;

        typename ArrayList<T>::Iterator itC(&arr5, -1); // invalid
        cout << *itC << endl;
    } catch (out_of_range& e) {
        cout << "Caught exception: " << e.what() << endl;
    }

    // ==== Test Iterator operator= ====
    cout << "\n--- Test Iterator operator= ---\n";
    typename ArrayList<T>::Iterator itX = arr5.begin();
    typename ArrayList<T>::Iterator itY = arr5.end();

    cout << "*itX before assign: " << *itX << endl;
    itY = itX;
    cout << "*itY after assign: " << *itY << endl;

    cout << "\n=== END TEST ===\n\n";
}

// Hàm test public để main.cpp gọi
void test_array() {
    testArrayListTemplate<int>();      // test với int
    // testArrayListTemplate<double>(); // có thể mở thêm
    // testArrayListTemplate<string>();
}