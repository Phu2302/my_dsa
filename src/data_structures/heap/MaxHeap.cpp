#include "heap/Heap.h"

// ======================= CONSTRUCTOR / DESTRUCTOR =======================

template<class T>
MaxHeap<T>::MaxHeap() : Heap<T>() {
    // O(1)
}

template<class T>
MaxHeap<T>::~MaxHeap() {
    // O(1)
}


// ======================= COMPARISON =======================

template<class T>
bool MaxHeap<T>::compare(const T& a, const T& b) const {
    // Time complexity: O(1)
    if (a > b) return true;
    return false;
}


// ======================= EXPLICIT INSTANTIATION =======================

template class MaxHeap<int>;
template class MaxHeap<double>;
template class MaxHeap<string>;
