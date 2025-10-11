#include "stack/Stack.h"

// ======================= CONSTRUCTOR / DESTRUCTOR =======================

// Default constructor
template<class T>
ArrayStack<T>::ArrayStack() {
    // Time complexity: O(1)
}

// Copy constructor
template<class T>
ArrayStack<T>::ArrayStack(const ArrayStack<T>& other) {
    // Time complexity: O(n)
    list = other.list;
}

// Destructor
template<class T>
ArrayStack<T>::~ArrayStack() {
    // Time complexity: 
}

// Copy assignment operator
template<class T>
ArrayStack<T>& ArrayStack<T>::operator=(const ArrayStack<T>& other) {
    // Time complexity: 
    if (this != &other) list = other.list;
    return *this;
}

// ======================= IStack IMPLEMENTATION =======================

// Push an element onto the top of the stack
template<class T>
void ArrayStack<T>::push(const T& element) {
    // Time complexity: 
    list.add(element);
}

// Remove and return the top element
template<class T>
T ArrayStack<T>::pop() {
    // Time complexity:
    if (list.empty()) throw out_of_range("Stack is empty!");
    return list.removeAt(list.size()-1);
}

// Return the top element without removing it
template<class T>
T& ArrayStack<T>::top() {
    // Time complexity:
    if (list.empty()) throw out_of_range("Stack is empty!"); 
    return list.get(list.size()-1);
}

// Check if the stack is empty
template<class T>
bool ArrayStack<T>::empty() const {
    // Time complexity: 
    if (list.size() == 0) return true;
    return false;
}

// Return the number of elements in the stack
template<class T>
int ArrayStack<T>::size() const {
    // Time complexity: 
    return list.size();
}

// Remove all elements from the stack
template<class T>
void ArrayStack<T>::clear() {
    // Time complexity: 
    list.clear();
}

// Check if the stack contains a specific item
template<class T>
bool ArrayStack<T>::contains(const T& item) const {
    // Time complexity: 
    return list.contains(item);
}

// Remove the first occurrence of an item (from top to bottom)
template<class T>
bool ArrayStack<T>::remove(const T& item) {
    // Time complexity: 
    return list.removeItem(item);
}

// Return a string representation of the stack
template<class T>
string ArrayStack<T>::toString() const {
    // Time complexity: 
    ostringstream re;
    re << "[top -> ";
    for (int i = list.size()-1; i >= 0; i--){
        re << list.get(i);
        if (i > 0) re << ", ";
    }
    re << "]";
    return re.str();
}

// ======================= ITERATOR =======================

// Initialize iterator at the given position
template<class T>
ArrayStack<T>::Iterator::Iterator(const ArrayStack<T>* stack, int index) {
    // Time complexity: 
    this->stack = stack;
    this->index = index;
}

// Move iterator to the next element (top -> bottom)
template<class T>
typename ArrayStack<T>::Iterator& ArrayStack<T>::Iterator::operator++() {
    // Time complexity: 
    --index;
    return *this;
}

// Access the current element
template<class T>
const T& ArrayStack<T>::Iterator::operator*() const {
    return stack->list.get(index);
}


// Compare iterators for inequality
template<class T>
bool ArrayStack<T>::Iterator::operator!=(const Iterator& other) const {
    // Time complexity: 
    if (index != other.index) return true;
    return false;
}

// Return iterator pointing to the top element
template<class T>
typename ArrayStack<T>::Iterator ArrayStack<T>::begin() const {
    // Time complexity: 
    return Iterator(this, list.size() - 1);
}

// Return iterator pointing past the last element (bottom)
template<class T>
typename ArrayStack<T>::Iterator ArrayStack<T>::end() const {
    // Time complexity: 
    return Iterator(this, -1);
}

// ======================= EXPLICIT INSTANTIATION =======================
template class ArrayStack<int>;
template class ArrayStack<double>;
template class ArrayStack<string>;
template class ArrayStack<char>;
template class ArrayStack<float>;
