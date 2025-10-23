#include "algorithms/sorting.h"
#include "linked_list/SLinkedList.h"
#include "linked_list/DLinkedList.h"
#include "array/ArrayList.h"

// ===========================================================
// ARRAYLIST
// ===========================================================
template <class T>
void ArrayList<T>::bubbleSort() {
    for (int i = 0; i < count - 1; ++i) {
        for (int j = 0; j < count - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                T tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
            }
        }
    }
}

template <class T>
void ArrayList<T>::selectionSort() {
    for (int i = 0; i < count - 1; ++i) {
        int minIndex = i;
        for (int j = i + 1; j < count; ++j) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            T tmp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = tmp;
        }
    }
}

template <class T>
void ArrayList<T>::insertionSort() {
    for (int i = 1; i < count; ++i) {
        T key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

template <class T>
void ArrayList<T>::shellSort() {
    for (int gap = count / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < count; ++i) {
            T temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
    }
}

template <class T>
void ArrayList<T>::quickSort() {
    // TODO: implement quickSort
}

template <class T>
void ArrayList<T>::mergeSort() {
    // TODO: implement mergeSort
}

template <class T>
void ArrayList<T>::heapSort() {
    // TODO: implement heapSort
}



// ===========================================================
// SLinkedList<T> Sorting Implementation
// (Note: traversal bằng node ->next, không arr[])
// ===========================================================

template <class T>
void SLinkedList<T>::bubbleSort() {
    if (head == nullptr) return;
    for (Node* i = head; i != tail; i = i->next) {
        for (Node* j = head; j->next != nullptr; j = j->next) {
            if (j->data > j->next->data) {
                T tmp = j->data;
                j->data = j->next->data;
                j->next->data = tmp;
            }
        }
    }
}

template <class T>
void SLinkedList<T>::insertionSort() {
    if (head == nullptr || head->next == nullptr) return;
    Node* sorted = nullptr;
    Node* current = head;

    while (current != nullptr) {
        Node* next = current->next;

        if (sorted == nullptr || sorted->data >= current->data) {
            current->next = sorted;
            sorted = current;
        } else {
            Node* tmp = sorted;
            while (tmp->next != nullptr && tmp->next->data < current->data)
                tmp = tmp->next;

            current->next = tmp->next;
            tmp->next = current;
        }

        current = next;
    }

    head = sorted;
}

template <class T>
void SLinkedList<T>::mergeSort() {
    // TODO: implement mergeSort cho DSLK đơn
}



// ===========================================================
// DLinkedList<T> Sorting Implementation
// (Duyệt hai chiều head <-> tail)
// ===========================================================

template <class T>
void DLinkedList<T>::bubbleSort() {
    if (head == nullptr) return;
    bool swapped;
    do {
        swapped = false;
        Node* curr = head;
        while (curr->next != nullptr) {
            if (curr->data > curr->next->data) {
                T tmp = curr->data;
                curr->data = curr->next->data;
                curr->next->data = tmp;
                swapped = true;
            }
            curr = curr->next;
        }
    } while (swapped);
}

template <class T>
void DLinkedList<T>::insertionSort() {
    if (head == nullptr) return;
    Node* curr = head->next;
    while (curr != nullptr) {
        T key = curr->data;
        Node* prev = curr->prev;
        while (prev != nullptr && prev->data > key) {
            prev->next->data = prev->data;
            prev = prev->prev;
        }
        if (prev == nullptr)
            head->data = key;
        else
            prev->next->data = key;

        curr = curr->next;
    }
}

template <class T>
void DLinkedList<T>::mergeSort() {
    // TODO: implement mergeSort cho DSLK đôi
}

// ===========================================================
// EXPLICIT INSTANTIATION
// ===========================================================
template class ArrayList<int>;
template class ArrayList<double>;
template class ArrayList<string>;
template class ArrayList<char>;
template class ArrayList<float>;

template class SLinkedList<int>;
template class SLinkedList<double>;
template class SLinkedList<string>;
template class SLinkedList<char>;
template class SLinkedList<float>;

template class DLinkedList<int>;
template class DLinkedList<double>;
template class DLinkedList<string>;
template class DLinkedList<char>;
template class DLinkedList<float>;
