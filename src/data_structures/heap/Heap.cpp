#include "heap/Heap.h"

// ======================= CONSTRUCTOR / DESTRUCTOR =======================

template<class T>
Heap<T>::Heap() {
    // Time complexity: O(1)
    capacity = 10;
    count = 0;
    arr = new T[capacity];
}

template<class T>
Heap<T>::~Heap() {
    // Time complexity: O(n)
    delete[] arr;
}


// ======================= INTERNAL UTILITIES =======================

template<class T>
void Heap<T>::ensureCapacity(int cap) {
    // Time complexity:
    if (cap <= capacity) return;
    int newCapacity;
    if (capacity == 0) newCapacity = 10;
    else newCapacity = capacity * 3/2;

    if(cap > newCapacity) newCapacity = cap;

    T *newArr = new T[newCapacity];
    for (int i = 0; i < count; i++){
        newArr[i] = arr[i];
    }
    delete []arr;
    arr = newArr;
    capacity = newCapacity;
}

template<class T>
void Heap<T>::reheapUp(int index) {
    // Time complexity:
    while (index > 0){
        int parent = (index-1)/2;
        if (compare(arr[index], arr[parent])){
            T temp = arr[index];
            arr[index] = arr[parent];
            arr[parent] = temp;
            index = parent;
        }
        else break;
    }
}

template<class T>
void Heap<T>::reheapDown(int index) {
    // Time complexity:
    while (true){
        int left = 2 * index + 1;
        int right = 2 * index + 2;
        int best = index;

        if (left < count && compare(arr[left], arr[best])) best = left;
        if (right < count && compare(arr[right], arr[best])) best = right;

        if (best != index){
            T temp = arr[index];
            arr[index] = arr[best];
            arr[best] = temp;
            index = best;
        }
        else break;
    }
}


// ======================= CORE HEAP OPERATIONS =======================

template<class T>
void Heap<T>::push(const T& value) {
    // Time complexity:
    ensureCapacity(count + 1);
    arr[count] = value;
    reheapUp(count);
    count++;
}

template<class T>
void Heap<T>::pop() {
    // Time complexity:
    if (count == 0) return;
    arr[0] = arr[count-1];
    count--;
    reheapDown(0);
}

template<class T>
const T& Heap<T>::top() const {
    // Time complexity:
    if (count == 0) throw out_of_range("Heap is empty");
    return arr[0];
}


// ======================= EXTENDED OPERATIONS =======================

template<class T>
bool Heap<T>::remove(const T& value) {
    // Time complexity:
    for (int i = 0; i < count; i++){
        if (arr[i] == value){
            arr[i] = arr[count-1];
            count--;
            reheapUp(i);
            reheapDown(i);
            return true;
        }
    }
    return false;
}

template<class T>
bool Heap<T>::contains(const T& value) const {
    // Time complexity:
    for (int i = 0; i < count; i++){
        if (arr[i] == value) return true;
    }
    return false;
}

template<class T>
const T& Heap<T>::getItem(int index) const {
    // Time complexity:
    if (index < 0 || index >= count) throw out_of_range("Heap is empty");
    return arr[index];
}


// ======================= STATE =======================

template<class T>
bool Heap<T>::empty() const {
    // Time complexity:
    if (count == 0) return true;
    return false;
}

template<class T>
int Heap<T>::size() const {
    // Time complexity:
    return count;
}


// ======================= UTILITY =======================

template<class T>
void Heap<T>::clear() {
    // Time complexity:
    count = 0;
}

template<class T>
string Heap<T>::levelorder() const {
    // Time complexity:
    stringstream ss;
    for (int i = 0; i < count; i++)
        ss << arr[i] << " ";
    return ss.str();
}

template<class T>
string Heap<T>::toString() const {
    return levelorder();
}


// ======================= EXPLICIT INSTANTIATION =======================

template class Heap<int>;
template class Heap<double>;
template class Heap<string>;
