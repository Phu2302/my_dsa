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
    // Time complexity:
}

// Thêm phần tử tại vị trí index
template<class T>
void DLinkedList<T>::add(int index, const T& e) {
    // Time complexity:
}

// Xóa phần tử tại vị trí index, trả về phần tử đã xóa
template<class T>
T DLinkedList<T>::removeAt(int index) {
    // Time complexity:
    return T{};
}

// Xóa phần tử có giá trị item (nếu tồn tại)
template<class T>
bool DLinkedList<T>::removeItem(const T& item) {
    // Time complexity:
    return false;
}

// Kiểm tra danh sách có rỗng hay không
template<class T>
bool DLinkedList<T>::empty() const {
    // Time complexity:
    return true;
}

// Trả về số lượng phần tử trong danh sách
template<class T>
int DLinkedList<T>::size() const {
    // Time complexity:
    return 0;
}

// Xóa toàn bộ danh sách
template<class T>
void DLinkedList<T>::clear() {
    // Time complexity:
}

// Lấy phần tử tại vị trí index
template<class T>
T& DLinkedList<T>::get(int index) {
    // Time complexity:
    static T temp{};
    return temp;
}

// Gán giá trị mới cho phần tử tại vị trí index
template<class T>
void DLinkedList<T>::set(int index, const T& e) {
    // Time complexity:
}

// Trả về vị trí đầu tiên của phần tử item (hoặc -1 nếu không có)
template<class T>
int DLinkedList<T>::indexOf(const T& item) const {
    // Time complexity:
    return -1;
}

// Kiểm tra danh sách có chứa phần tử item không
template<class T>
bool DLinkedList<T>::contains(const T& item) const {
    // Time complexity:
    return false;
}

// Trả về phần tử đầu tiên của danh sách
template<class T>
T& DLinkedList<T>::front() {
    // Time complexity:
    static T temp{};
    return temp;
}

// Trả về phần tử cuối cùng của danh sách
template<class T>
T& DLinkedList<T>::back() {
    // Time complexity:
    static T temp{};
    return temp;
}

// Xóa và trả về phần tử đầu tiên của danh sách
template<class T>
T DLinkedList<T>::pop_front() {
    // Time complexity:
    return T{};
}

// Xóa và trả về phần tử cuối cùng của danh sách
template<class T>
T DLinkedList<T>::pop_back() {
    // Time complexity:
    return T{};
}

// Trả về chuỗi biểu diễn danh sách (ví dụ: [1, 2, 3])
template<class T>
string DLinkedList<T>::toString() const {
    // Time complexity:
    return "[]";
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
