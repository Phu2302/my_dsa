#include "linked_list/DLinkedList.h"
#include "lib.h"

// ======================= CONSTRUCTOR / DESTRUCTOR =======================

// Khởi tạo danh sách rỗng
template<class T>
DLinkedList<T>::DLinkedList() {
    // Time complexity: O(1)
    head = nullptr;
    tail = nullptr;
    count = 0;
}

// Constructor sao chép
template<class T>
DLinkedList<T>::DLinkedList(const DLinkedList<T>& other) {
    // Time complexity: O(n)
    Node *curOther = other.head;
    while (curOther != nullptr){
        Node *newNode = new Node(curOther->data, nullptr, nullptr);
        if (head == nullptr){
            head = newNode;
            tail = newNode;
        }
        else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        count++;
        curOther = curOther->next;
    }
}

// Destructor: giải phóng toàn bộ bộ nhớ
template<class T>
DLinkedList<T>::~DLinkedList() {
    // Time complexity: O(n)
    Node *cur = head;
    while (cur != nullptr){
        Node *del = cur;
        cur = cur->next;
        delete del;
    }
}

// Toán tử gán
template<class T>
DLinkedList<T>& DLinkedList<T>::operator=(const DLinkedList<T>& other) {
    // Time complexity:
    
    return *this;
}

// ======================= CÀI ĐẶT CÁC HÀM IList =======================

// Thêm phần tử vào cuối danh sách
template<class T>
void DLinkedList<T>::add(const T& e) {
    // Time complexity: O(1)
    Node *newNode = new Node(e, nullptr, nullptr);
    if (count == 0){
        head = newNode;
        tail = newNode;
        count++;
        return;
    }
    tail->next = newNode;
    newNode->prev = tail;
    tail = newNode;
    count++;
}

// Thêm phần tử tại vị trí index
template<class T>
void DLinkedList<T>::add(int index, const T& e) {
    // Time complexity: O(n)
    if (index < 0 || index > count) throw out_of_range("Index is invalid!");
    Node *newNode = new Node(e, nullptr, nullptr);
    if (count == 0){
        head = newNode;
        tail = newNode;
        count++;
        return;
    }

    if (index == 0){
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
        count++;
        return;
    }

    if (index == count){
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
        count++;
        return;
    }
    Node *cur = head;
    for (int i = 0; i < index - 1; i++){
        cur = cur->next;
    }
    newNode->next = cur->next;
    cur->next->prev = newNode;
    newNode->prev = cur;
    cur->next = newNode;
}

// Xóa phần tử tại vị trí index, trả về phần tử đã xóa
template<class T>
T DLinkedList<T>::removeAt(int index) {
    // Time complexity: O(n)
    if (index < 0 || index >= count) throw out_of_range("Index is invalid!");
    if (count == 0) throw out_of_range("Empty List!");
    
    if (count == 1){
        Node *del = head;
        T val = del->data;
        head = nullptr;
        tail = nullptr;
        delete del;
        count--;
        return val;
    }

    if (index == count-1){
        Node *del = tail;
        T val = del->data;
        tail->prev->next = nullptr;
        tail = tail->prev;
        delete del;
        count--;
        return val;
    }
    Node *cur = head;
    for (int i = 0; i < index-1; i++){
        cur = cur->next;
    }
    Node *del = cur->next;
    T val = del->data;
    cur->next = del->next;
    del->next->prev = del->prev;
    delete del;
    count--;
    return val;
}

// Xóa phần tử có giá trị item (nếu tồn tại)
template<class T>
bool DLinkedList<T>::removeItem(const T& item) {
    // Time complexity: O(n)
    if (count == 0) throw out_of_range("Empty List!");
    Node *cur = head;
    int idx = 0;
    while (cur != nullptr){
        if (cur->data == item){
            DLinkedList::removeAt(idx); 
            return true;
        }
        idx++;
        cur = cur->next;
    }
    return false;
}

// Kiểm tra danh sách có rỗng hay không
template<class T>
bool DLinkedList<T>::empty() const {
    // Time complexity: O(1)
    if (count == 0) return true;
    return false;
}

// Trả về số lượng phần tử trong danh sách
template<class T>
int DLinkedList<T>::size() const {
    // Time complexity: O(1)
    return count;
}

// Xóa toàn bộ danh sách
template<class T>
void DLinkedList<T>::clear() {
    // Time complexity: O(n)
    Node *cur = head;
    while (cur != nullptr){
        Node *del = cur;
        cur = cur->next;
        delete del;
    }
    head = nullptr;
    tail = nullptr;
    count = 0;
}

// Lấy phần tử tại vị trí index
template<class T>
T& DLinkedList<T>::get(int index) {
    // Time complexity: O(n)
    if (index < 0 || index >= count) throw out_of_range("Index is invalid!");
    if (count == 0) throw out_of_range("Empty List!");
    Node *cur = head;
    for (int i = 0; i < index; i++){
        cur = cur->next;
    }
    return cur->data;
}

// Gán giá trị mới cho phần tử tại vị trí index
template<class T>
void DLinkedList<T>::set(int index, const T& e) {
    // Time complexity: O(n)
    if (index < 0 || index >= count) throw out_of_range("Index is invalid!");
    if (count == 0) throw out_of_range("Empty List!");
    Node *cur = head;
    for (int i = 0; i < index; i++){
        cur = cur->next;
    }
    cur->data = e;
}

// Trả về vị trí đầu tiên của phần tử item (hoặc -1 nếu không có)
template<class T>
int DLinkedList<T>::indexOf(const T& item) const {
    // Time complexity: O(n)
    if (count == 0) throw out_of_range("Empty List!");
    Node *cur = head;
    int idx = 0;
    while (cur != nullptr){
        if (cur->data == item) return idx;
        idx++;
        cur = cur->next;
    }
    return -1;
}

// Kiểm tra danh sách có chứa phần tử item không
template<class T>
bool DLinkedList<T>::contains(const T& item) const {
    // Time complexity: O(n)
    if (count == 0) throw out_of_range("Empty List!");
    Node *cur = head;
    while (cur != nullptr){
        if (cur->data == item) return true;
        cur = cur->next;
    }
    return false;
}

// Trả về phần tử đầu tiên của danh sách
template<class T>
T& DLinkedList<T>::front() {
    // Time complexity: 0(1)
    if (count == 0) throw out_of_range("Empty List!");
    return head->data;
}

// Trả về phần tử cuối cùng của danh sách
template<class T>
T& DLinkedList<T>::back() {
    // Time complexity: O(1)
    if (count == 0) throw out_of_range("Empty List!");
    return tail->data;
}

// Xóa và trả về phần tử đầu tiên của danh sách
template<class T>
T DLinkedList<T>::pop_front() {
    // Time complexity: O(1)
    if (count == 0) throw out_of_range("Empty List!");
    if (count == 1){
        Node *del = head;
        T val = del->data;
        head = nullptr;
        tail = nullptr;
        delete del;
        count--;
        return val;
    }
    Node *del = head;
    T val = del->data;
    head = head->next;
    head->prev = nullptr;
    delete del;
    count--;
    return val;
}

// Xóa và trả về phần tử cuối cùng của danh sách
template<class T>
T DLinkedList<T>::pop_back() {
    // Time complexity: O(1)
    if (count == 0) throw out_of_range("Empty List!");
    if (count == 1){
        Node *del = tail;
        T val = del->data;
        head = nullptr;
        tail = nullptr;
        delete del;
        count--;
        return val;
    }
    Node *del = tail;
    T val = del->data;
    tail->prev->next = nullptr;
    tail = tail->prev;
    delete del;
    count--;
    return val;
}

// Trả về chuỗi biểu diễn danh sách (ví dụ: [1, 2, 3])
template<class T>
string DLinkedList<T>::toString() const {
    // Time complexity: O(n)
    if (count == 0) return "[]";

    ostringstream re;
    re << "[";
    Node *cur = head;
    while (cur != nullptr){
        re << cur->data;
        if (cur->next != nullptr) re << ", ";
        cur = cur->next;
    }
    re << "]";
    return re.str();
}

// ======================= ITERATOR =======================

// Khởi tạo iterator tại node cho trước
template<class T>
DLinkedList<T>::Iterator::Iterator(Node* node)
    : current(node) {
    // Time complexity:
}

// Toán tử gán
template<class T>
typename DLinkedList<T>::Iterator&
DLinkedList<T>::Iterator::operator=(const Iterator& other) {
    // Time complexity:
    return *this;
}

// Truy cập phần tử hiện tại
template<class T>
T& DLinkedList<T>::Iterator::operator*() {
    // Time complexity:
    static T temp{};
    return temp;
}

// So sánh iterator khác nhau
template<class T>
bool DLinkedList<T>::Iterator::operator!=(const Iterator& other) const {
    // Time complexity:
    return true;
}

// So sánh iterator bằng nhau
template<class T>
bool DLinkedList<T>::Iterator::operator==(const Iterator& other) const {
    // Time complexity:
    return false;
}

// Tiến tiền tố ++it
template<class T>
typename DLinkedList<T>::Iterator&
DLinkedList<T>::Iterator::operator++() {
    // Time complexity:
    return *this;
}

// Tiến hậu tố it++
template<class T>
typename DLinkedList<T>::Iterator
DLinkedList<T>::Iterator::operator++(int) {
    // Time complexity:
    return *this;
}

// Lùi tiền tố --it
template<class T>
typename DLinkedList<T>::Iterator&
DLinkedList<T>::Iterator::operator--() {
    // Time complexity:
    return *this;
}

// Lùi hậu tố it--
template<class T>
typename DLinkedList<T>::Iterator
DLinkedList<T>::Iterator::operator--(int) {
    // Time complexity:
    return *this;
}

// Trả về iterator đầu danh sách
template<class T>
typename DLinkedList<T>::Iterator DLinkedList<T>::begin() {
    // Time complexity:
    return Iterator(head);
}

// Trả về iterator sau phần tử cuối cùng
template<class T>
typename DLinkedList<T>::Iterator DLinkedList<T>::end() {
    // Time complexity:
    return Iterator(nullptr);
}

// Trả về iterator trỏ tới tail (duyệt ngược)
template<class T>
typename DLinkedList<T>::Iterator DLinkedList<T>::rbegin() {
    // Time complexity:
    return Iterator(tail);
}

// Trả về iterator "trước head" (duyệt ngược)
template<class T>
typename DLinkedList<T>::Iterator DLinkedList<T>::rend() {
    // Time complexity:
    return Iterator(nullptr);
}

// ======================= EXPLICIT INSTANTIATION =======================
template class DLinkedList<int>;
template class DLinkedList<double>;
template class DLinkedList<string>;
template class DLinkedList<char>;
template class DLinkedList<float>;
