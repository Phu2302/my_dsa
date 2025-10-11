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
    return *this;
}

// ======================= IQUEUE IMPLEMENTATION =======================

// Add element to the back of the queue
template<class T>
void LinkedQueue<T>::enqueue(const T& element) {
    // Time complexity: 
}

// Remove and return the front element
template<class T>
T LinkedQueue<T>::dequeue() {
    // Time complexity: 
    return T();
}

// Return the front element without removing it
template<class T>
T& LinkedQueue<T>::front() {
    // Time complexity: 
    static T dummy{};
    return dummy;
}

// Return the back element without removing it
template<class T>
T& LinkedQueue<T>::back() {
    // Time complexity: 
    static T dummy{};
    return dummy;
}

// Check if the queue is empty
template<class T>
bool LinkedQueue<T>::empty() const {
    // Time complexity: 
    return true;
}

// Return number of elements in the queue
template<class T>
int LinkedQueue<T>::size() const {
    // Time complexity: 
    return 0;
}

// Remove all elements
template<class T>
void LinkedQueue<T>::clear() {
    // Time complexity: 
}

// ======================= UTILITY METHODS =======================

// Check if queue contains specific item
template<class T>
bool LinkedQueue<T>::contains(const T& item) const {
    // Time complexity: 
    return false;
}

// Remove first occurrence of an item
template<class T>
bool LinkedQueue<T>::remove(const T& item) {
    // Time complexity: 
    return false;
}

// Return string representation of the queue
template<class T>
string LinkedQueue<T>::toString() const {
    // Time complexity: 
    return "[front -> back]";
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
    return *this;
}

// Access current element
template<class T>
const T& LinkedQueue<T>::Iterator::operator*() const {
    // Time complexity: 
    static T dummy{};
    return dummy;
}

// Compare iterators for inequality
template<class T>
bool LinkedQueue<T>::Iterator::operator!=(const Iterator& other) const {
    // Time complexity: 
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
