#include "queue/Deque.h"

// ======================= CONSTRUCTOR / DESTRUCTOR =======================

// Default constructor
template<class T>
ArrayDeque<T>::ArrayDeque() {
    // Time complexity: 
    
}

// Copy constructor
template<class T>
ArrayDeque<T>::ArrayDeque(const ArrayDeque<T>& other) {
    // Time complexity: 
    list = other.list;
}

// Destructor
template<class T>
ArrayDeque<T>::~ArrayDeque() {
    // Time complexity: 
}

// Copy assignment operator
template<class T>
ArrayDeque<T>& ArrayDeque<T>::operator=(const ArrayDeque<T>& other) {
    // Time complexity: 
    if (this != &other) list = other.list;
    return *this;
}

// ======================= IQUEUE IMPLEMENTATION =======================

// Add element to the back of the deque
template<class T>
void ArrayDeque<T>::enqueue(const T& element) {
    // Time complexity: 
    list.add(element);
}

// Remove and return the front element
template<class T>
T ArrayDeque<T>::dequeue() {
    // Time complexity: 
    if (list.empty()) throw out_of_range("Empty List!");
    return list.removeAt(0);
}

// Return front element without removing it
template<class T>
T& ArrayDeque<T>::front() {
    // Time complexity:
    if (list.empty()) throw out_of_range("Queue is empty!"); 
    return list.get(0);
}

// Return back element without removing it
template<class T>
T& ArrayDeque<T>::back() {
    // Time complexity: 
    if (list.empty()) throw out_of_range("Queue is empty!");
    return list.get(list.size()-1);
}

// Check if deque is empty
template<class T>
bool ArrayDeque<T>::empty() const {
    // Time complexity: 
    return list.size();
}

// Return number of elements
template<class T>
int ArrayDeque<T>::size() const {
    // Time complexity: 
    return list.size();
}

// Remove all elements
template<class T>
void ArrayDeque<T>::clear() {
    // Time complexity:
    return list.clear(); 
}

// ======================= EXTENDED METHODS (Deque) =======================

// Add element to the front of the deque
template<class T>
void ArrayDeque<T>::enqueueFront(const T& element) {
    // Time complexity: 
    list.add(0, element);
}

// Remove and return the back element
template<class T>
T ArrayDeque<T>::dequeueBack() {
    // Time complexity: 
    return list.removeAt(list.size()-1);
}

// ======================= UTILITY METHODS =======================

// Check if deque contains a specific item
template<class T>
bool ArrayDeque<T>::contains(const T& item) const {
    // Time complexity: 
    return list.contains();
}

// Remove first occurrence of a specific item
template<class T>
bool ArrayDeque<T>::remove(const T& item) {
    // Time complexity: 
    return list.removeItem(item);
}

// Return string representation of the deque
template<class T>
string ArrayDeque<T>::toString() const {
    // Time complexity: 
    if (list.empty()) return "[front -> ]";

    ostringstream re;
    re << "[front -> ";
    bool first = true;
    for (auto it = list.begin(); it != list.end(); it++){
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
ArrayDeque<T>::Iterator::Iterator(const ArrayDeque<T>* deque, int index) {
    // Time complexity: 
    this->deque = deque;
    this->index = index;
}

// Move iterator to next element (front -> back)
template<class T>
typename ArrayDeque<T>::Iterator& ArrayDeque<T>::Iterator::operator++() {
    // Time complexity: 
    index++;
    return *this;
}

// Access current element
template<class T>
T& ArrayDeque<T>::Iterator::operator*() {
    // Time complexity: 
    if (index < 0 || index >= deque->list.size()) throw out_of_range("Iterator out of range");
    return deque->list.get(index);
}

// Compare iterators for inequality
template<class T>
bool ArrayDeque<T>::Iterator::operator!=(const Iterator& other) const {
    // Time complexity: 
    if (index != other.index) return true;
    return false;
}

// Return iterator to the front element
template<class T>
typename ArrayDeque<T>::Iterator ArrayDeque<T>::begin() const {
    // Time complexity:
    return Iterator(this, 0);
}

// Return iterator past the last element
template<class T>
typename ArrayDeque<T>::Iterator ArrayDeque<T>::end() const {
    // Time complexity: 
    return Iterator(this, list.size());
}

// ======================= EXPLICIT INSTANTIATION =======================
template class ArrayDeque<int>;
template class ArrayDeque<double>;
template class ArrayDeque<string>;
template class ArrayDeque<char>;
template class ArrayDeque<float>;
