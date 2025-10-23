#include "array/ArrayList.h"
#include "lib.h"

template<typename T>
void testArrayListSortingTemplate(const string& typeName) {
    cout << "=== Test ArrayList<" << typeName << "> Sorting ===\n\n";

    ArrayList<T> arr;
    arr.add(5);
    arr.add(1);
    arr.add(4);
    arr.add(2);
    arr.add(8);

    cout << "Original: " << arr.toString() << endl;

    // ==== Test bubbleSort ====
    cout << "\n--- Test bubbleSort ---\n";
    ArrayList<T> arr1(arr);
    arr1.bubbleSort();
    cout << "After bubbleSort: " << arr1.toString() << endl;

    // ==== Test selectionSort ====
    cout << "\n--- Test selectionSort ---\n";
    ArrayList<T> arr2(arr);
    arr2.selectionSort();
    cout << "After selectionSort: " << arr2.toString() << endl;

    // ==== Test insertionSort ====
    cout << "\n--- Test insertionSort ---\n";
    ArrayList<T> arr3(arr);
    arr3.insertionSort();
    cout << "After insertionSort: " << arr3.toString() << endl;

    // ==== Test shellSort ====
    cout << "\n--- Test shellSort ---\n";
    ArrayList<T> arr4(arr);
    arr4.shellSort();
    cout << "After shellSort: " << arr4.toString() << endl;

    // ==== Test quickSort ====
    cout << "\n--- Test quickSort ---\n";
    ArrayList<T> arr5(arr);
    arr5.quickSort();
    cout << "After quickSort: " << arr5.toString() << endl;

    // ==== Test mergeSort ====
    cout << "\n--- Test mergeSort ---\n";
    ArrayList<T> arr6(arr);
    arr6.mergeSort();
    cout << "After mergeSort: " << arr6.toString() << endl;

    // ==== Test heapSort ====
    cout << "\n--- Test heapSort ---\n";
    ArrayList<T> arr7(arr);
    arr7.heapSort();
    cout << "After heapSort: " << arr7.toString() << endl;

    cout << "\n=== END TEST ArrayList<" << typeName << "> ===\n\n";
}

void test_sorting() {
    testArrayListSortingTemplate<int>("int");
    // testArrayListSortingTemplate<double>("double");
    // testArrayListSortingTemplate<string>("string");

    // testSLinkedListSortingTemplate<int>("int");
    // testDLinkedListSortingTemplate<int>("int");
}
