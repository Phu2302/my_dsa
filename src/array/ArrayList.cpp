#include "array/ArrayList.h"
#include "lib.h"

// ======================= PRIVATE =======================

// Đảm bảo mảng có đủ dung lượng để chứa cap phần tử
template<class T>
void ArrayList<T>::ensureCapacity(int cap) {
    // TODO
    if (cap < capacity) return;
    int newCapacity;
    if (capcity == 0) newCapacity = 10;
    else newCapacity = capacity * 3/2;

    T newArr = new T[capacity];
    for (int i = 0; i < count; i++){
        newCapacity[i] = capacity[i];
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
    return T{};
}

// Xóa phần tử có giá trị item (nếu tồn tại)
template<class T>
bool ArrayList<T>::removeItem(const T& item) {
    // TODO
    return false;
}

// Kiểm tra danh sách có rỗng hay không
template<class T>
bool ArrayList<T>::empty() const {
    // TODO
    return true;
}

// Trả về số lượng phần tử trong danh sách
template<class T>
int ArrayList<T>::size() const {
    // TODO
    return 0;
}

// Xóa toàn bộ danh sách
template<class T>
void ArrayList<T>::clear() {
    // TODO
}

// Lấy phần tử tại vị trí index
template<class T>
T& ArrayList<T>::get(int index) {
    // TODO
    static T temp{};
    return temp;
}

// Gán giá trị mới cho phần tử tại vị trí index
template<class T>
void ArrayList<T>::set(int index, const T& e) {
    // TODO
}

// Trả về vị trí đầu tiên của phần tử item (hoặc -1 nếu không có)
template<class T>
int ArrayList<T>::indexOf(const T& item) const {
    // TODO
    return -1;
}

// Kiểm tra danh sách có chứa phần tử item không
template<class T>
bool ArrayList<T>::contains(const T& item) const {
    // TODO
    return false;
}

// Trả về phần tử đầu tiên của danh sách
template<class T>
T& ArrayList<T>::front() {
    // TODO
    static T temp{};
    return temp;
}

// Trả về phần tử cuối cùng của danh sách
template<class T>
T& ArrayList<T>::back() {
    // TODO
    static T temp{};
    return temp;
}

// Xóa và trả về phần tử đầu tiên của danh sách
template<class T>
T ArrayList<T>::pop_front() {
    // TODO
    return T{};
}

// Xóa và trả về phần tử cuối cùng của danh sách
template<class T>
T ArrayList<T>::pop_back() {
    // TODO
    return T{};
}

// Trả về chuỗi biểu diễn danh sách (ví dụ: [1, 2, 3])
template<class T>
string ArrayList<T>::toString() const {
    // TODO
    return "[]";
}

// ======================= ITERATOR =======================

// Khởi tạo iterator
template<class T>
ArrayList<T>::Iterator::Iterator(ArrayList<T>* list, int index)
    : pList(list), cursor(index) {
    // TODO
}

// Toán tử gán
template<class T>
typename ArrayList<T>::Iterator&
ArrayList<T>::Iterator::operator=(const Iterator& other) {
    // TODO
    return *this;
}

// Truy cập phần tử hiện tại
template<class T>
T& ArrayList<T>::Iterator::operator*() {
    // TODO
    static T temp{};
    return temp;
}

// So sánh iterator khác nhau
template<class T>
bool ArrayList<T>::Iterator::operator!=(const Iterator& other) const {
    // TODO
    return true;
}

// Tiến tiền tố ++it
template<class T>
typename ArrayList<T>::Iterator&
ArrayList<T>::Iterator::operator++() {
    // TODO
    return *this;
}

// Tiến hậu tố it++
template<class T>
typename ArrayList<T>::Iterator
ArrayList<T>::Iterator::operator++(int) {
    // TODO
    return *this;
}

// Lùi tiền tố --it
template<class T>
typename ArrayList<T>::Iterator&
ArrayList<T>::Iterator::operator--() {
    // TODO
    return *this;
}

// Lùi hậu tố it--
template<class T>
typename ArrayList<T>::Iterator
ArrayList<T>::Iterator::operator--(int) {
    // TODO
    return *this;
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








/*
//! Đảm bảo capacity đủ chỗ chứa cap phần tử
void ArrayList::ensureCapacity(int cap) {
    // TODO
    if (cap > capacity) {
        capacity = capacity * 3 / 2;
        if (cap > capacity){
            capacity = cap;
        }
    }
    int* newArray = new int[capacity];
    for (int i = 0; i < count; i++){
        newArray[i] = arr[i];
    }
    delete[] arr;
    arr = newArray;
}

// Constructor
ArrayList::ArrayList(int initCapacity) {
    // TODO
    capacity = initCapacity;
    count = 0;
    arr = new int[capacity];
}

// Copy constructor
ArrayList::ArrayList(const ArrayList& other) {
    // TODO
    capacity = other.capacity;
    count = other.count;
    arr = new int[capacity];
    for (int i = 0; i < count; i++){
        arr[i] = other.arr[i];
    }
}

// Destructor
ArrayList::~ArrayList() {
    // TODO
    delete[] arr;
}

// Operator=
ArrayList& ArrayList::operator=(const ArrayList& other) {
    // TODO
    if (this != &other){
        delete[] arr; 
        capacity = other.capacity;
        count = other.count;
        arr = new int[capacity];
        for (int i = 0; i < count; i++){
            arr[i] = other.arr[i];
        }
    }
    return *this;
}

// Thêm cuối
void ArrayList::add(int e) {
    // TODO
    ensureCapacity(count +1);
    arr[count++] = e;
}

// Thêm tại index
void ArrayList::add(int index, int e) {
    // TODO
    if (index < 0 || index > count){
        throw out_of_range("Index is invalid!");
    }
    ensureCapacity(count + 1);
    for (int i = count; i > index; i--){
        arr[i] = arr[i-1]; // 1 2 3 4 5 //      4 5
    }
    arr[index] = e;
    count++;
}

// Xoá tại index
int ArrayList::removeAt(int index) {
    // TODO
    if (index < 0 || index > count -1){
        throw out_of_range("Index is invalid!");
    }
    int removed = arr[index];
    for (int i = index; i < count-1; i++){
        arr[i] = arr[i+1]; // 1 2 3 4 5// 1 3 4 5
    }
    count--;
    return removed;
}

// Kiểm tra rỗng
bool ArrayList::empty() const {
    // TODO
    if (count == 0) return true;
    else return false;
}

// Trả về size
int ArrayList::size() const {
    // TODO
    return count;
}

// Clear list
void ArrayList::clear() {
    // TODO
    delete[] arr;
    capacity = 10;
    count = 0;
    arr = new int[capacity];
}

// Lấy phần tử
int& ArrayList::get(int index) {
    // TODO
    if (index < 0 || index > count - 1) throw out_of_range("Index is invalid!");
    return arr[index];
}

// Gán phần tử
void ArrayList::set(int index, int e) {
    // TODO
    if (index < 0 || index > count - 1) throw out_of_range("Index is invalid");

    arr[index] = e;
}

// Tìm index của item
int ArrayList::indexOf(int item) const {
    // TODO
    for (int i = 0; i < count; i++){
        if (arr[i] == item) {
            return i;
        }
    }
    return -1;
}

// Kiểm tra contains
bool ArrayList::contains(int item) const {
    // TODO
    for (int i = 0; i < count; i++){
        if (arr[i] == item) return true;
    }
    return false;
}

// toString
string ArrayList::toString() const {
    // TODO
    string re = "[";
    for (int i = 0; i < count; i++){
        re += to_string(arr[i]);
        if (i < count - 1){
            re += ", ";
        }
    }
    re += "]";
    return re;
}

// ================= Iterator ================= //

// Constructor
ArrayList::Iterator::Iterator(ArrayList* list, int index) {
    // TODO: Khởi tạo pList và cursor
    // Nếu index ngoài [0, list->count] thì throw out_of_range("Index is invalid!")
    
    //1: dont have list 
    if (list == nullptr){
        pList = nullptr;
        cursor = 0;
        return;
    }

    if (index < 0 || index > list->count){
        throw out_of_range("Index is invalid!");
    }
    pList = list;
    cursor = index;
}

// Toán tử gán
ArrayList::Iterator& ArrayList::Iterator::operator=(const Iterator& other) {
    // TODO: Copy pList và cursor từ other
    pList = other.pList;
    cursor = other.cursor;
    return *this;
}

// Dereference
int& ArrayList::Iterator::operator*() {
    // TODO: Trả về tham chiếu đến phần tử arr[cursor] trong pList
    // Nếu cursor == count (end) thì throw out_of_range("Iterator is out of range!")
    if (pList == nullptr || pList->count == cursor){
        throw out_of_range("Iterator is out of range!");
    }
    return pList->arr[cursor];
}

// So sánh khác nhau
bool ArrayList::Iterator::operator!=(const Iterator& other) const {
    // TODO: Trả về true nếu pList khác hoặc cursor khác
    if (pList != other.pList) return true;
    if (cursor != other.cursor) return true;
    return false;
}

// Tiến (tiền tố ++it)
ArrayList::Iterator& ArrayList::Iterator::operator++() {
    // TODO: Tăng cursor
    // Nếu cursor > count thì throw out_of_range("Iterator cannot advance past end!")
    if (pList == nullptr) throw out_of_range("Iterator is null!");
    if (cursor >= pList->count) throw out_of_range("Iterator cannot advance past end!");
    ++cursor;
    return *this;
}

// Tiến (hậu tố it++)
ArrayList::Iterator ArrayList::Iterator::operator++(int) {
    // TODO: Lưu iterator hiện tại, tăng cursor, trả về bản sao cũ
    if (pList == nullptr) throw out_of_range("Iterator is null!");
    if (cursor >= pList->count) throw out_of_range("Iterator cannot advance past end!");
    Iterator old = *this;
    cursor++;
    return old;
}

// Lùi (tiền tố --it)
ArrayList::Iterator& ArrayList::Iterator::operator--() {
    // TODO: Giảm cursor
    // Nếu cursor < 0 thì throw out_of_range("Iterator cannot move before begin!")
    if (pList == nullptr) throw out_of_range("Iterator is null!");
    else if (cursor <= 0) throw out_of_range("Iterator cannot move before begin!");
    --cursor;
    return *this;
}

// Lùi (hậu tố it--)
ArrayList::Iterator ArrayList::Iterator::operator--(int) {
    // TODO: Lưu iterator hiện tại, giảm cursor, trả về bản sao cũ
    if (pList == nullptr) throw out_of_range("Iterator is null!");
    if (cursor == 0) throw out_of_range("Iterator cannot move before begin!");
    Iterator old = *this;
    cursor--;
    return old;
}

// begin()
ArrayList::Iterator ArrayList::begin() {
    // TODO: Trả về Iterator(this, 0)
    return Iterator(this, 0);
}

// end()
ArrayList::Iterator ArrayList::end() {
    // TODO: Trả về Iterator(this, count)
    return Iterator(this, count);
}
*/