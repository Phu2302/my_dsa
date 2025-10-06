#include "linked_list/DLinkedList.h"
#include "include/lib"

// ======================= CONSTRUCTOR / DESTRUCTOR =======================

// Khởi tạo danh sách rỗng
template<class T>
DLinkedList<T>::DLinkedList() {
    // TODO
}

// Constructor sao chép
template<class T>
DLinkedList<T>::DLinkedList(const DLinkedList<T>& other) {
    // TODO
}

// Destructor: giải phóng toàn bộ bộ nhớ
template<class T>
DLinkedList<T>::~DLinkedList() {
    // TODO
}

// Toán tử gán
template<class T>
DLinkedList<T>& DLinkedList<T>::operator=(const DLinkedList<T>& other) {
    // TODO
    return *this;
}

// ======================= CÀI ĐẶT CÁC HÀM IList =======================

// Thêm phần tử vào cuối danh sách
template<class T>
void DLinkedList<T>::add(const T& e) {
    // TODO
}

// Thêm phần tử tại vị trí index
template<class T>
void DLinkedList<T>::add(int index, const T& e) {
    // TODO
}

// Xóa phần tử tại vị trí index, trả về phần tử đã xóa
template<class T>
T DLinkedList<T>::removeAt(int index) {
    // TODO
    return T{};
}

// Xóa phần tử có giá trị item (nếu tồn tại)
template<class T>
bool DLinkedList<T>::removeItem(const T& item) {
    // TODO
    return false;
}

// Kiểm tra danh sách có rỗng hay không
template<class T>
bool DLinkedList<T>::empty() const {
    // TODO
    return true;
}

// Trả về số lượng phần tử trong danh sách
template<class T>
int DLinkedList<T>::size() const {
    // TODO
    return 0;
}

// Xóa toàn bộ danh sách
template<class T>
void DLinkedList<T>::clear() {
    // TODO
}

// Lấy phần tử tại vị trí index
template<class T>
T& DLinkedList<T>::get(int index) {
    // TODO
    static T temp{};
    return temp;
}

// Gán giá trị mới cho phần tử tại vị trí index
template<class T>
void DLinkedList<T>::set(int index, const T& e) {
    // TODO
}

// Trả về vị trí đầu tiên của phần tử item (hoặc -1 nếu không có)
template<class T>
int DLinkedList<T>::indexOf(const T& item) const {
    // TODO
    return -1;
}

// Kiểm tra danh sách có chứa phần tử item không
template<class T>
bool DLinkedList<T>::contains(const T& item) const {
    // TODO
    return false;
}

// Trả về phần tử đầu tiên của danh sách
template<class T>
T& DLinkedList<T>::front() {
    // TODO
    static T temp{};
    return temp;
}

// Trả về phần tử cuối cùng của danh sách
template<class T>
T& DLinkedList<T>::back() {
    // TODO
    static T temp{};
    return temp;
}

// Xóa và trả về phần tử đầu tiên của danh sách
template<class T>
T DLinkedList<T>::pop_front() {
    // TODO
    return T{};
}

// Xóa và trả về phần tử cuối cùng của danh sách
template<class T>
T DLinkedList<T>::pop_back() {
    // TODO
    return T{};
}

// Trả về chuỗi biểu diễn danh sách (ví dụ: [1, 2, 3])
template<class T>
string DLinkedList<T>::toString() const {
    // TODO
    return "[]";
}

// ======================= ITERATOR =======================

// Khởi tạo iterator tại node cho trước
template<class T>
DLinkedList<T>::Iterator::Iterator(Node* node)
    : current(node) {
    // TODO
}

// Toán tử gán
template<class T>
typename DLinkedList<T>::Iterator&
DLinkedList<T>::Iterator::operator=(const Iterator& other) {
    // TODO
    return *this;
}

// Truy cập phần tử hiện tại
template<class T>
T& DLinkedList<T>::Iterator::operator*() {
    // TODO
    static T temp{};
    return temp;
}

// So sánh iterator khác nhau
template<class T>
bool DLinkedList<T>::Iterator::operator!=(const Iterator& other) const {
    // TODO
    return true;
}

// So sánh iterator bằng nhau
template<class T>
bool DLinkedList<T>::Iterator::operator==(const Iterator& other) const {
    // TODO
    return false;
}

// Tiến tiền tố ++it
template<class T>
typename DLinkedList<T>::Iterator&
DLinkedList<T>::Iterator::operator++() {
    // TODO
    return *this;
}

// Tiến hậu tố it++
template<class T>
typename DLinkedList<T>::Iterator
DLinkedList<T>::Iterator::operator++(int) {
    // TODO
    return *this;
}

// Lùi tiền tố --it
template<class T>
typename DLinkedList<T>::Iterator&
DLinkedList<T>::Iterator::operator--() {
    // TODO
    return *this;
}

// Lùi hậu tố it--
template<class T>
typename DLinkedList<T>::Iterator
DLinkedList<T>::Iterator::operator--(int) {
    // TODO
    return *this;
}

// Trả về iterator đầu danh sách
template<class T>
typename DLinkedList<T>::Iterator DLinkedList<T>::begin() {
    // TODO
    return Iterator(head);
}

// Trả về iterator sau phần tử cuối cùng
template<class T>
typename DLinkedList<T>::Iterator DLinkedList<T>::end() {
    // TODO
    return Iterator(nullptr);
}

// Trả về iterator trỏ tới tail (duyệt ngược)
template<class T>
typename DLinkedList<T>::Iterator DLinkedList<T>::rbegin() {
    // TODO
    return Iterator(tail);
}

// Trả về iterator "trước head" (duyệt ngược)
template<class T>
typename DLinkedList<T>::Iterator DLinkedList<T>::rend() {
    // TODO
    return Iterator(nullptr);
}

// ======================= EXPLICIT INSTANTIATION =======================
template class DLinkedList<int>;
template class DLinkedList<double>;
template class DLinkedList<string>;
template class DLinkedList<char>;
template class DLinkedList<float>;
