#include "array/ArrayList.h"
#include "lib.h"

// ======================= PRIVATE =======================

// Đảm bảo mảng có đủ dung lượng để chứa cap phần tử
template<class T>
void ArrayList<T>::ensureCapacity(int cap) {
    // TODO
    if (cap < capacity) return;
    int newCapacity;
    if (capacity == 0) newCapacity = 10;
    else newCapacity = capacity * 3/2;

    T *newArr = new T[capacity];
    for (int i = 0; i < count; i++){
        newArr[i] = arr[i];
    }
    delete[] arr;
    arr = newArr;
    capacity = newCapacity;
}

// ======================= CONSTRUCTOR / DESTRUCTOR =======================

// Khởi tạo danh sách với sức chứa ban đầu
template<class T>
ArrayList<T>::ArrayList(int initCapacity) {
    // TODO
    capacity = initCapacity;
    count = 0;
    arr = new T[capacity];
}

// Constructor sao chép
template<class T>
ArrayList<T>::ArrayList(const ArrayList& other) {
    // TODO
    capacity = other.capacity;
    count = other.count;
    arr = new T[capacity];

    for (int i = 0; i < count; i++){
        arr[i] = other.arr[i];
    }
}

// Destructor: giải phóng bộ nhớ
template<class T>
ArrayList<T>::~ArrayList() {
    // TODO
    delete[] arr;
}

// Toán tử gán
template<class T>
ArrayList<T>& ArrayList<T>::operator=(const ArrayList& other) {
    // TODO
    if (this != &other){
        delete arr;
        capacity = other.capacity;
        count = other.count;
        arr = new T[capacity];
        for (int i = 0; i < count; i++){
            arr[i] = other.arr[i];
        }
    }
    return *this;
}

// ======================= CÀI ĐẶT CÁC HÀM IList =======================

// Thêm phần tử vào cuối danh sách
template<class T>
void ArrayList<T>::add(const T& e) {
    // TODO
    ensureCapacity(count+1);
    arr[count] = e;
    count++;
}

// Thêm phần tử tại vị trí index
template<class T>
void ArrayList<T>::add(int index, const T& e) {
    // TODO
    if (index < 0 || index > count) throw out_of_range("Index is invalid!");
    ensureCapacity(count+1);
    for (int i = count; i > index; i--){
        arr[i] = arr[i-1];
    }
    arr[index] = e;
    count++;
}

// Xóa phần tử tại vị trí index, trả về phần tử đã xóa
template<class T>
T ArrayList<T>::removeAt(int index) {
    // TODO
    if (index < 0 || index >= count) throw out_of_range("Index is invalid");
    T removed = arr[index];
    
    for (int i = index; i < count-1; i++){
        arr[i] = arr[i+1];
    }
    count--;
    return removed;
}

// Xóa phần tử có giá trị item (nếu tồn tại)
template<class T>
bool ArrayList<T>::removeItem(const T& item) {
    // TODO
    for (int i = 0; i < count; i++){
        if (arr[i] == item){
            removeAt(i);
            return true;
        }
    }
    return false;
}

// Kiểm tra danh sách có rỗng hay không
template<class T>
bool ArrayList<T>::empty() const {
    // TODO
    if (count == 0) return true;
    return false;
}

// Trả về số lượng phần tử trong danh sách
template<class T>
int ArrayList<T>::size() const {
    // TODO
    return count;
}

// Xóa toàn bộ danh sách
template<class T>
void ArrayList<T>::clear() {
    // TODO
    delete [] arr;
    count = 0;
    capacity = 10;
    arr = new T[capacity];
}

// Lấy phần tử tại vị trí index
template<class T>
T& ArrayList<T>::get(int index) {
    // TODO
    if (index < 0 || index >= count) throw out_of_range("Index is invalid!");
    return arr[index];
}

template<class T>
const T& ArrayList<T>::get(int index) const {
    if (index < 0 || index >= count) throw out_of_range("Index is invalid!");
    return arr[index];
}


// Gán giá trị mới cho phần tử tại vị trí index
template<class T>
void ArrayList<T>::set(int index, const T& e) {
    // TODO
    if (index < 0 || index >= count) throw out_of_range("Index is invalid!");
    arr[index] = e;
}

// Trả về vị trí đầu tiên của phần tử item (hoặc -1 nếu không có)
template<class T>
int ArrayList<T>::indexOf(const T& item) const {
    // TODO
    for (int i = 0; i < count; i++){
        if (arr[i] == item) return i;
    }
    return -1;
}

// Kiểm tra danh sách có chứa phần tử item không
template<class T>
bool ArrayList<T>::contains(const T& item) const {
    // TODO
    for (int i = 0; i < count; i++){
        if (arr[i] == item) return true;
    }
    return false;
}

// Trả về phần tử đầu tiên của danh sách
template<class T>
T& ArrayList<T>::front() {
    // TODO
    return arr[0];
}

// Trả về phần tử cuối cùng của danh sách
template<class T>
T& ArrayList<T>::back() {
    // TODO
    return arr[count];
}

// Xóa và trả về phần tử đầu tiên của danh sách
template<class T>
T ArrayList<T>::pop_front() {
    // TODO
    T temp = arr[0];
    for (int i = 0; i < count-1; i++){
        arr[i] = arr[i+1];
    }
    count--;
    return temp;
}

// Xóa và trả về phần tử cuối cùng của danh sách
template<class T>
T ArrayList<T>::pop_back() {
    // TODO
    if (count == 0) throw out_of_range("Empty");
    T temp = arr[count-1];
    arr[count-1] = T();
    return temp;
}

// Trả về chuỗi biểu diễn danh sách (ví dụ: [1, 2, 3])
template<class T>
string ArrayList<T>::toString() const {
    // TODO
    ostringstream oss;
    oss << "[";
    for (int i = 0; i < count; i++) {
        oss << arr[i];
        if (i < count - 1) oss << ", ";
    }
    oss << "]";
    return oss.str();
}

// ======================= ITERATOR =======================

// Khởi tạo iterator
template<class T>
ArrayList<T>::Iterator::Iterator(ArrayList<T>* list, int index) {
    // TODO
    if (list == nullptr){
        pList = nullptr;
        cursor = 0;
        return;
    }
    if (index < 0 || index > list->count) throw out_of_range("Index is invalid!");
    
    pList = list;
    cursor = index;
}

// Toán tử gán
template<class T>
typename ArrayList<T>::Iterator&
ArrayList<T>::Iterator::operator=(const Iterator& other) {
    // TODO
    if (this != &other){
        this->pList = other.pList;
        this->cursor = other.cursor;
    }
    return *this;
}

// Truy cập phần tử hiện tại
template<class T>
T& ArrayList<T>::Iterator::operator*() {
    // TODO
    if (pList == nullptr) throw out_of_range("Iterator is null");
    if (cursor < 0 || cursor >= pList->count) throw out_of_range("Iterator is out of range");
    return pList->arr[cursor];
}

// So sánh iterator khác nhau
template<class T>
bool ArrayList<T>::Iterator::operator!=(const Iterator& other) const {
    // TODO
    if (this->pList != other.pList || this->cursor != other.cursor) return true; 
    return false;
}

// Tiến tiền tố ++it
template<class T>
typename ArrayList<T>::Iterator&
ArrayList<T>::Iterator::operator++() {
    // TODO
    if (pList == nullptr) throw out_of_range("Iterator is null!");
    if (cursor >= pList->count) throw out_of_range("This is the end, cannot move");
    ++cursor;
    return *this;
}

// Tiến hậu tố it++
template<class T>
typename ArrayList<T>::Iterator
ArrayList<T>::Iterator::operator++(int) {
    // TODO
    if (pList == nullptr) throw out_of_range("Iterator is null!");
    if (cursor >= pList->count) throw out_of_range("This is the end, cannot move");
    Iterator old = *this;
    cursor++;
    return old;
}

// Lùi tiền tố --it
template<class T>
typename ArrayList<T>::Iterator&
ArrayList<T>::Iterator::operator--() {
    // TODO
    if (pList == nullptr) throw out_of_range("Iterator is null!");
    if (cursor <= 0) throw out_of_range("This is first element, cannot move to left");
    --cursor;
    return *this;
}

// Lùi hậu tố it--
template<class T>
typename ArrayList<T>::Iterator
ArrayList<T>::Iterator::operator--(int) {
    // TODO
    if (pList == nullptr) throw out_of_range("Iterator is null!");
    if (cursor <= 0) throw out_of_range("This is first element, cannot move to left");
    Iterator old = *this;
    cursor--;
    return old;
}

// Trả về iterator đầu danh sách
template<class T>
typename ArrayList<T>::Iterator ArrayList<T>::begin() {
    // TODO
    return Iterator(this, 0);
}

// Trả về iterator sau phần tử cuối cùng
template<class T>
typename ArrayList<T>::Iterator ArrayList<T>::end() {
    // TODO
    return Iterator(this, count);
}

// ======================= EXPLICIT INSTANTIATION =======================
template class ArrayList<int>;
template class ArrayList<double>;
template class ArrayList<string>;
template class ArrayList<char>;
template class ArrayList<float>;