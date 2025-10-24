#include "algorithms/sorting.h"
#include "linked_list/SLinkedList.h"
#include "linked_list/DLinkedList.h"
#include "array/ArrayList.h"




// ===========================================================
// ARRAYLIST
// ===========================================================
template <class T>
void ArrayList<T>::bubbleSort() {
    // TODO
    if (count <= 1) return;
    for (int i = 0; i < count-1; i++){
        bool swapped = false;
        for (int j = 0; j < count-i-1; j++){
            if (arr[j] > arr[j+1]){
                T temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                swapped = true;
            }
        }
        printList();
        if (swapped == false) break;
    }
}

template <class T>
void ArrayList<T>::selectionSort() {
    // TODO
    if (count <= 1) return;
    for (int i = 0; i < count-1; i++){
        int minIdx = i;
        for (int j = i + 1; j < count; j++){
            if (arr[j] < arr[minIdx]) minIdx = j;
        }

        if (minIdx != i){
            T temp = arr[i];
            arr[i] = arr[minIdx];
            arr[minIdx] = temp; 
        }
        printList();
    }
}

template <class T>
void ArrayList<T>::insertionSort() {
    // TODO
    if (count <= 1) return;
    for (int i = 1; i < count; i++){
        int j = i;
        while (j >= 0 && (arr[j-1] > arr[j])){
            T temp = arr[j];
            arr[j] = arr[j-1];
            arr[j-1] = temp;
            j--;
        }
        printList();
    }
}

template <class T>
void ArrayList<T>::shellSort() {
    // TODO
    if (count <= 1) return;
    
    for (int gap = count/2; gap > 0; gap /= 2){
        for (int i = gap; i < count; i++){
            int j = i;
            while (j >= gap && arr[j-gap] > arr[j]){
                T temp = arr[j];
                arr[j] = arr[j-gap];
                arr[j-gap] = temp;
                j -= gap;
            }
        }
        printList();
    }
}

template <class T>
int ArrayList<T>::partition(int low, int high) {
    T pivot = arr[low];
    int left = low;
    int right = high;

    while (left < right){
        // right side
        while (left < right){
            if (arr[right] < pivot){
                arr[left] = arr[right];
                left++;
                break;
            }
            right--;
        }

        // left side
        while (left < right){
            if (arr[left] > pivot){
                arr[right] = arr[left];
                right--; 
                break;
            }
            left++;
        }
    }

    arr[left] = pivot;  // when left = right
    cout << "pivot = " << pivot << " -> ";
    printList();
    return left;
}

template <class T>
void ArrayList<T>::quickSortHelper(int low, int high) {
    if (low < high) {
        int pivotIndex = partition(low, high);
        quickSortHelper(low, pivotIndex - 1);
        quickSortHelper(pivotIndex + 1, high);
    }
}

template <class T>
void ArrayList<T>::quickSort() {
    if (count <= 1) return;
    quickSortHelper(0, count - 1);
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
    // TODO
}

template <class T>
void SLinkedList<T>::insertionSort() {
    // TODO
}

template <class T>
void SLinkedList<T>::mergeSort() {
    // TODO
}



// ===========================================================
// DLinkedList<T> Sorting Implementation
// ===========================================================

template <class T>
void DLinkedList<T>::bubbleSort() {
    // TODO
}

template <class T>
void DLinkedList<T>::insertionSort() {
    // TODO
}

template <class T>
void DLinkedList<T>::mergeSort() {
    // TODO
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
