#include "queue/Queue.h"

// ======================= CONSTRUCTOR / DESTRUCTOR =======================

// Default constructor
template<class T>
LinkedQueue<T>::LinkedQueue() {
    // Time complexity: 
}

// Copy constructor
template<class T>
LinkedQueue<T>::LinkedQueue(const LinkedQueue<T>& other) {
    // Time complexity: 
    list = other.list;
}

// Destructor
template<class T>
LinkedQueue<T>::~LinkedQueue() {
    // Time complexity: 
}

// Copy assignment operator
template<class T>
LinkedQueue<T>& LinkedQueue<T>::operator=(const LinkedQueue<T>& other) {
    // Time complexity: 
    if (this != &other) list = other.list;
    return *this;
}

// ======================= IQUEUE IMPLEMENTATION =======================

// Add element to the back of the queue
template<class T>
void LinkedQueue<T>::enqueue(const T& element) {
    // Time complexity: 
    list.add(element);
}

// Remove and return the front element
template<class T>
T LinkedQueue<T>::dequeue() {
    // Time complexity: 
    return list.pop_front();
}

// Return the front element without removing it
template<class T>
T& LinkedQueue<T>::front() {
    // Time complexity: 
    return list.front();
}

// Return the back element without removing it
template<class T>
T& LinkedQueue<T>::back() {
    // Time complexity: 
    return list.back();
}

// Check if the queue is empty
template<class T>
bool LinkedQueue<T>::empty() const {
    // Time complexity: 
    return list.empty();
}

// Return number of elements in the queue
template<class T>
int LinkedQueue<T>::size() const {
    // Time complexity: 
    return list.size();
}

// Remove all elements
template<class T>
void LinkedQueue<T>::clear() {
    // Time complexity: 
    return list.clear;
}

// ======================= UTILITY METHODS =======================

// Check if queue contains specific item
template<class T>
bool LinkedQueue<T>::contains(const T& item) const {
    // Time complexity: 
    return list.contains();
}

// Remove first occurrence of an item
template<class T>
bool LinkedQueue<T>::remove(const T& item) {
    // Time complexity: 
    return list.removeItem();
}

// Return string representation of the queue
template<class T>
string LinkedQueue<T>::toString() const {
    // Time complexity: 
    ostringstream re;
    re << "front ->";
    bool first = true;
    for (auto it = list.begin(); it !+ list.end(); it++){
        if (!first) re << ", ";
        re << *it;
        first = false;
    }
    re << "]";
    return re.str();
}

// ======================= ITERATOR =======================

// Initialize iterator with list iterator
template<class T>
LinkedQueue<T>::Iterator::Iterator(const typename SLinkedList<T>::Iterator& listIt)
    : it(listIt) {
    // Time complexity: 
}

// Move iterator to the next element
template<class T>
typename LinkedQueue<T>::Iterator& LinkedQueue<T>::Iterator::operator++() {
    // Time complexity: 
    ++it;
    return *this;
}

// Access current element
template<class T>
const T& LinkedQueue<T>::Iterator::operator*() const {
    // Time complexity: 
    return *it;
}

// Compare iterators for inequality
template<class T>
bool LinkedQueue<T>::Iterator::operator!=(const Iterator& other) const {
    // Time complexity: 
    if (it != other.it) return true;
    return false;
}

// Return iterator to the front element
template<class T>
typename LinkedQueue<T>::Iterator LinkedQueue<T>::begin() const {
    // Time complexity: 
    return Iterator(list.begin());
}

// Return iterator past the last element
template<class T>
typename LinkedQueue<T>::Iterator LinkedQueue<T>::end() const {
    // Time complexity: 
    return Iterator(list.end());
}

// ======================= EXPLICIT INSTANTIATION =======================
template class LinkedQueue<int>;
template class LinkedQueue<double>;
template class LinkedQueue<string>;
template class LinkedQueue<char>;
template class LinkedQueue<float>;
