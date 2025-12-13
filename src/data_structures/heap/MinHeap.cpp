#include "heap/Heap.h"

// ======================= CONSTRUCTOR / DESTRUCTOR =======================

template<class T>
MinHeap<T>::MinHeap() : Heap<T>() {
    // O(1)
}

template<class T>
MinHeap<T>::~MinHeap() {
    // O(1)
}

// ======================= COMPARISON =======================

template<class T>
bool MinHeap<T>::compare(const T& a, const T& b) const {
    // Time complexity: O(1)
    if (a < b) return true;
    return false;
}


// ======================= EXPLICIT INSTANTIATION =======================

template class MinHeap<int>;
template class MinHeap<double>;
template class MinHeap<string>;
