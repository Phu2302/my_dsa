#ifndef SORTING_H
#define SORTING_H

#include "lib.h"

/*
 * Utility Function: printList
 * ---------------------------
 * In ra toàn bộ danh sách (ArrayList, SLinkedList, v.v.)
 * miễn là lớp đó hỗ trợ:
 *   - size()
 *   - get(int index)
 * Dùng trong debug các thuật toán sắp xếp.
 */
template <class ListType>
void printList(const ListType& list, const string& title = "List") {
    cout << title << ": [";
    for (int i = 0; i < list.size(); ++i) {
        cout << list.get(i);
        if (i < list.size() - 1) cout << ", ";
    }
    cout << "]" << endl;
}

/*
 * Overload cho mảng thuần T*
 * --------------------------
 * In ra mảng thông thường (nếu bạn test thuật toán thuần).
 */
template <class T>
void printList(const T* arr, int n, const string& title = "Array") {
    cout << title << ": [";
    for (int i = 0; i < n; ++i) {
        cout << arr[i];
        if (i < n - 1) cout << ", ";
    }
    cout << "]" << endl;
}

#endif // SORTING_H
