#include "queue/Queue.h"

// ======================= CONSTRUCTOR / DESTRUCTOR =======================

// Default constructor
template<class T>
ArrayQueue<T>::ArrayQueue() {
    // Time complexity: 
}

// Copy constructor
template<class T>
ArrayQueue<T>::ArrayQueue(const ArrayQueue<T>& other) {
    // Time complexity: 
    list = other.list;
}

// Destructor
template<class T>
ArrayQueue<T>::~ArrayQueue() {
    // Time complexity: 
}

// Copy assignment operator
template<class T>
ArrayQueue<T>& ArrayQueue<T>::operator=(const ArrayQueue<T>& other) {
    // Time complexity: 
    if (this != other){
        list = other.list;
    }
    return *this;
}

// ======================= IQUEUE IMPLEMENTATION =======================

// Add element to the back of the queue
template<class T>
void ArrayQueue<T>::enqueue(const T& element) {
    // Time complexity:
    list.add(element);
}

// Remove and return the front element
template<class T>
T ArrayQueue<T>::dequeue() {
    // Time complexity:
    if (list.empty()) throw out_of_range("Queue is empty!");
    return list.removeAt(0); 
}

// Return the front element without removing it
template<class T>
T& ArrayQueue<T>::front() {
    // Time complexity: 
    if (list.empty()) throw out_of_range("Queue is empty!");
    return list.get(0);
}

// Return the back element without removing it
template<class T>
T& ArrayQueue<T>::back() {
    // Time complexity: 
    if (list.empty()) throw out_of_range("Queue is empty!");
    return list.get(list.size()-1);
}

// Check if the queue is empty
template<class T>
bool ArrayQueue<T>::empty() const {
    // Time complexity: 
    return list.empty();
}

// Return the number of elements
template<class T>
int ArrayQueue<T>::size() const {
    // Time complexity: 
    return list.size();
}

// Remove all elements
template<class T>
void ArrayQueue<T>::clear() {
    // Time complexity:
    list.clear();
}

// ======================= UTILITY METHODS =======================

// Check if the queue contains a specific element
template<class T>
bool ArrayQueue<T>::contains(const T& item) const {
    // Time complexity: 
    return list.contains(item);
}

// Remove first occurrence of an element
template<class T>
bool ArrayQueue<T>::remove(const T& item) {
    // Time complexity: 
    return list.removeItem(item);
}

// Return string representation of the queue
template<class T>
string ArrayQueue<T>::toString() const {
    // Time complexity: 
    if (list.empty()) return "[front -> ]";

    ostringstream re;
    re << "[front -> ";

    bool first = true;
    for (auto it = list.begin(); it != list.end(); it++) {
        if (!first) re << ", ";
        re << *it;
        first = false;
    }

    re << "]";
    return re.str();
}

// ======================= ITERATOR =======================

// Initialize iterator with index
template<class T>
ArrayQueue<T>::Iterator::Iterator(const ArrayQueue<T>* queue, int index) {
    // Time complexity: 
    this->queue = queue;
    this->index = index;
}

// Move iterator to next element (front -> back)
template<class T>
typename ArrayQueue<T>::Iterator& ArrayQueue<T>::Iterator::operator++() {
    // Time complexity:
    ++index;
    return *this;
}

// Access current element
template<class T>
T& ArrayQueue<T>::Iterator::operator*() {
    // Time complexity: 
    return queue->list.get(index);
}

// Compare iterators for inequality
template<class T>
bool ArrayQueue<T>::Iterator::operator!=(const Iterator& other) const {
    // Time complexity: 
    if (index != other.index) return true;
    return false;
}

// Return iterator to the front element
template<class T>
typename ArrayQueue<T>::Iterator ArrayQueue<T>::begin() const {
    // Time complexity: 
    if (list.empty()) return end;
    return Iterator(this, 0);
}

// Return iterator past the last element
template<class T>
typename ArrayQueue<T>::Iterator ArrayQueue<T>::end() const {
    // Time complexity: 
    return Iterator(this, list.size());
}

// ======================= EXPLICIT INSTANTIATION =======================
template class ArrayQueue<int>;
template class ArrayQueue<double>;
template class ArrayQueue<string>;
template class ArrayQueue<char>;
template class ArrayQueue<float>;
