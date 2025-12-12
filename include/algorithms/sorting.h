#ifndef SORTING_H
#define SORTING_H

#include "lib.h"
#include "array/ArrayList.h"
#include "linked_list/SLinkedList.h"
#include "linked_list/DLinkedList.h"

template <class T>
void ArrayList<T>::printList() const {
    cout << "[";
    for (int i = 0; i < count; i++) {
        cout << arr[i];
        if (i < count - 1) cout << ", ";
    }
    cout << "]" << endl;
}


#endif // SORTING_H
