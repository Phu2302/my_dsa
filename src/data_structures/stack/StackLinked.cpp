#include "stack/Stack.h"

// ======================= CONSTRUCTOR / DESTRUCTOR =======================

// Default constructor
template<class T>
LinkedStack<T>::LinkedStack() {
    // Time complexity: 
}

// Copy constructor
template<class T>
LinkedStack<T>::LinkedStack(const LinkedStack<T>& other) {
    // Time complexity: 
    list = other.list;
}

// Destructor
template<class T>
LinkedStack<T>::~LinkedStack() {
    // Time complexity: 
}

// Copy assignment operator
template<class T>
LinkedStack<T>& LinkedStack<T>::operator=(const LinkedStack<T>& other) {
    // Time complexity: 
    if (this != &other) list = other.list;
    return *this;
}

// ======================= IStack IMPLEMENTATION =======================

// Push an element onto the top of the stack
template<class T>
void LinkedStack<T>::push(const T& element) {
    // Time complexity: O(1)
    list.add(0, element); // Insert at head (top of stack)
}

// Remove and return the top element
template<class T>
T LinkedStack<T>::pop() {
    // Time complexity: O(1)
    if (list.empty()) throw out_of_range("Stack is empty!");
    return list.pop_front();
}

// Return the top element without removing it
template<class T>
T& LinkedStack<T>::top() {
    // Time complexity: O(1)
    if (list.empty()) throw out_of_range("Stack is empty!");
    return list.front();
}

// Check if the stack is empty
template<class T>
bool LinkedStack<T>::empty() const {
    // Time complexity: O(1)
    return list.empty();
}

// Return the number of elements in the stack
template<class T>
int LinkedStack<T>::size() const {
    // Time complexity: O(1)
    return list.size();
}

// Remove all elements from the stack
template<class T>
void LinkedStack<T>::clear() {
    // Time complexity: O(n)
    list.clear();
}

// ======================= UTILITY METHODS =======================

// Check if the stack contains a specific item
template<class T>
bool LinkedStack<T>::contains(const T& item) const {
    // Time complexity: 
    return list.contains(item);
}

// Remove the first occurrence of an item (from top to bottom)
template<class T>
bool LinkedStack<T>::remove(const T& item) {
    // Time complexity: 
    return list.removeItem(item);
}

// Return a string representation of the stack
template<class T>
string LinkedStack<T>::toString() const {
    // Time complexity: O(n)
    ostringstream re;
    re << "[top -> ";

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

// Initialize iterator with SLinkedList iterator
template<class T>
LinkedStack<T>::Iterator::Iterator(const typename SLinkedList<T>::Iterator& listIt)
{
    // Time complexity:
    this->it = listIt; 
}

// Move iterator to the next element (top -> bottom)
template<class T>
typename LinkedStack<T>::Iterator& LinkedStack<T>::Iterator::operator++() {
    // Time complexity:
    ++it; 
    return *this;
}

// Access the current element
template<class T>
const T& LinkedStack<T>::Iterator::operator*() const {
    // Time complexity: 
    return *it;
}

// Compare iterators for inequality
template<class T>
bool LinkedStack<T>::Iterator::operator!=(const Iterator& other) const {
    // Time complexity: 
    if (it != other.it) return true;
    return false;
}

// Return iterator pointing to the top element
template<class T>
typename LinkedStack<T>::Iterator LinkedStack<T>::begin() const {
    // Time complexity: 
    return Iterator(list.begin());
}

// Return iterator pointing past the last element (bottom)
template<class T>
typename LinkedStack<T>::Iterator LinkedStack<T>::end() const {
    // Time complexity: 
    return Iterator(list.end());
}

// ======================= EXPLICIT INSTANTIATION =======================
template class LinkedStack<int>;
template class LinkedStack<double>;
template class LinkedStack<string>;
template class LinkedStack<char>;
template class LinkedStack<float>;
