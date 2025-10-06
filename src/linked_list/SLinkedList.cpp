#include "linked_list/SLinkedList.h"
#include "lib.h"

// ======================= CONSTRUCTOR / DESTRUCTOR =======================

// Khởi tạo danh sách rỗng
template<class T>
SLinkedList<T>::SLinkedList() {
    // TODO
}

// Constructor sao chép
template<class T>
SLinkedList<T>::SLinkedList(const SLinkedList<T>& other) {
    // TODO
}

// Destructor: giải phóng toàn bộ bộ nhớ
template<class T>
SLinkedList<T>::~SLinkedList() {
    // TODO
}

// Toán tử gán
template<class T>
SLinkedList<T>& SLinkedList<T>::operator=(const SLinkedList<T>& other) {
    // TODO
    return *this;
}

// ======================= CÀI ĐẶT CÁC HÀM IList =======================

// Thêm phần tử vào cuối danh sách
template<class T>
void SLinkedList<T>::add(const T& e) {
    // TODO
}

// Thêm phần tử tại vị trí index
template<class T>
void SLinkedList<T>::add(int index, const T& e) {
    // TODO
}

// Xóa phần tử tại vị trí index, trả về phần tử đã xóa
template<class T>
T SLinkedList<T>::removeAt(int index) {
    // TODO
    return T{};
}

// Xóa phần tử có giá trị item (nếu tồn tại)
template<class T>
bool SLinkedList<T>::removeItem(const T& item) {
    // TODO
    return false;
}

// Kiểm tra danh sách có rỗng hay không
template<class T>
bool SLinkedList<T>::empty() const {
    // TODO
    return true;
}

// Trả về số lượng phần tử trong danh sách
template<class T>
int SLinkedList<T>::size() const {
    // TODO
    return 0;
}

// Xóa toàn bộ danh sách
template<class T>
void SLinkedList<T>::clear() {
    // TODO
}

// Lấy phần tử tại vị trí index
template<class T>
T& SLinkedList<T>::get(int index) {
    // TODO
    static T temp{};
    return temp;
}

// Gán giá trị mới cho phần tử tại vị trí index
template<class T>
void SLinkedList<T>::set(int index, const T& e) {
    // TODO
}

// Trả về vị trí đầu tiên của phần tử item (hoặc -1 nếu không có)
template<class T>
int SLinkedList<T>::indexOf(const T& item) const {
    // TODO
    return -1;
}

// Kiểm tra danh sách có chứa phần tử item không
template<class T>
bool SLinkedList<T>::contains(const T& item) const {
    // TODO
    return false;
}

// Trả về phần tử đầu tiên của danh sách
template<class T>
T& SLinkedList<T>::front() {
    // TODO
    static T temp{};
    return temp;
}

// Trả về phần tử cuối cùng của danh sách
template<class T>
T& SLinkedList<T>::back() {
    // TODO
    static T temp{};
    return temp;
}

// Xóa và trả về phần tử đầu tiên của danh sách
template<class T>
T SLinkedList<T>::pop_front() {
    // TODO
    return T{};
}

// Xóa và trả về phần tử cuối cùng của danh sách
template<class T>
T SLinkedList<T>::pop_back() {
    // TODO
    return T{};
}

// Trả về chuỗi biểu diễn danh sách (ví dụ: [1, 2, 3])
template<class T>
string SLinkedList<T>::toString() const {
    // TODO
    return "[]";
}

// ======================= ITERATOR =======================

// Khởi tạo iterator tại node cho trước
template<class T>
SLinkedList<T>::Iterator::Iterator(Node<T>* node)
    : current(node) {
    // TODO
}

// Toán tử gán
template<class T>
typename SLinkedList<T>::Iterator&
SLinkedList<T>::Iterator::operator=(const Iterator& other) {
    // TODO
    return *this;
}

// Truy cập phần tử hiện tại
template<class T>
T& SLinkedList<T>::Iterator::operator*() {
    // TODO
    static T temp{};
    return temp;
}

// So sánh iterator khác nhau
template<class T>
bool SLinkedList<T>::Iterator::operator!=(const Iterator& other) const {
    // TODO
    return true;
}

// So sánh iterator bằng nhau
template<class T>
bool SLinkedList<T>::Iterator::operator==(const Iterator& other) const {
    // TODO
    return false;
}

// Tiến tiền tố ++it
template<class T>
typename SLinkedList<T>::Iterator&
SLinkedList<T>::Iterator::operator++() {
    // TODO
    return *this;
}

// Tiến hậu tố it++
template<class T>
typename SLinkedList<T>::Iterator
SLinkedList<T>::Iterator::operator++(int) {
    // TODO
    return *this;
}

// Trả về iterator đầu danh sách
template<class T>
typename SLinkedList<T>::Iterator SLinkedList<T>::begin() {
    // TODO
    return Iterator(head);
}

// Trả về iterator sau phần tử cuối cùng
template<class T>
typename SLinkedList<T>::Iterator SLinkedList<T>::end() {
    // TODO
    return Iterator(nullptr);
}

// ======================= EXPLICIT INSTANTIATION =======================
template class SLinkedList<int>;
template class SLinkedList<double>;
template class SLinkedList<string>;
template class SLinkedList<char>;
template class SLinkedList<float>;



/*
// ================= Constructor & Destructor ================= //

// Constructor
SLinkedList::SLinkedList() {
    // TODO: Khởi tạo head, tail = nullptr, count = 0
    head = nullptr;
    tail = nullptr;
    count = 0;
}

// Destructor
SLinkedList::~SLinkedList() {
    // TODO: Giải phóng toàn bộ node để tránh rò rỉ bộ nhớ
    Node *cur = head;
    while (cur != nullptr){
        Node *temp = cur;
        cur = cur->next;
        delete temp;
    }
    head = nullptr;
    tail = nullptr;
    count = 0;
}

// ================= Các hàm thao tác ================= //

// Thêm cuối
void SLinkedList::add(int e) {
    // TODO
    Node *newNode = new Node(e);
    if (head == nullptr && tail == nullptr){
        head = newNode;
        tail = newNode;
        count++;
    }
    else {
        tail->next = newNode;
        tail = newNode;
        count++;
    }
}

// Thêm tại index

void SLinkedList::add(int index, int e) {
    Node *newNode = new Node(e);
    Node *current = head;
    
    if (count == 0){
        head = newNode;
        tail = newNode;
        count++;
        return;
    }
    
    if (index == 0){
        newNode->next = head;
        head = newNode;
        count++;
        return;
    }
    
    if (index == count){
        tail->next = newNode;
        tail = newNode;
        count++;
        return;
    }
    
    for (int i = 0; i < index-1; i++){
        current = current->next;
    }
    newNode->next = current->next;
    current->next = newNode;
    count++;
}

// Xóa tại index
int SLinkedList::removeAt(int index) {
    // TODO: nếu index không hợp lệ -> throw out_of_range("Index is invalid!")
    if (head == nullptr && tail == nullptr) throw out_of_range("Empty list!");
    if (index < 0 || index > count - 1) throw out_of_range("Index is invalid!");
    if (count == 1){
        Node *temp = head;
        int val = temp->data;
        delete temp;
        head = nullptr;
        tail = nullptr;
        count--;
        return val;
    }

    if (index == 0){
        Node *temp = head;
        int val = temp->data;
        head = head->next;
        delete temp;
        count--;
        return val;
    }

    if (index == count-1){
        Node *cur = head;
        while (cur->next->next != nullptr){
            cur = cur->next;
        }
        Node *temp = tail;
        int val = temp->data;
        cur->next = nullptr;
        tail = cur;
        delete temp;
        count--;
        return val;
    }

    Node *cur = head;
    for (int i = 0; i < index-1; i++){
        cur = cur->next;
    }
    Node *temp = cur->next;
    int val = temp->data;
    cur->next = cur->next->next;
    delete temp;
    count--;
    return val;
}

// Xóa phần tử có giá trị item
bool SLinkedList::removeItem(int item) {
    // TODO: duyệt list, tìm node có data == item, xóa node đầu tiên tìm thấy
    Node *cur = head;
    int index = 0;
    while (cur != nullptr) {
        if (cur->data == item) {
            SLinkedList::removeAt(index);
            return true;
        }
        cur = cur->next;
        index++;    
    }
    return false;
}

// Kiểm tra rỗng
bool SLinkedList::empty() const {
    // TODO
    if (count == 0) return true;
    return false;
}

// Trả về số phần tử
int SLinkedList::size() const {
    // TODO
    return count;
}

// Xóa toàn bộ danh sách
void SLinkedList::clear() {
    // TODO
    Node *cur = head;
    while (cur != nullptr){
        Node *temp = cur;
        cur = cur->next;
        delete temp;
    }
    head = nullptr;
    tail = nullptr;
    count = 0;
}

// Lấy phần tử tại index
int& SLinkedList::get(int index) {
    // TODO: nếu index không hợp lệ -> throw out_of_range("Index is invalid!")
    if (index < 0 || index > count - 1){
        throw out_of_range("Index is invalid!");
    }
    Node *cur = head;
    for (int i = 0; i < index; i++){
        cur = cur->next;
    }
    return cur->data;
}

// Trả về chỉ số đầu tiên của item
int SLinkedList::indexOf(int item) const {
    // TODO
    int indexof = 0;
    Node *cur = head;
    for (int i = 0; i < count; i++){
        if (cur->data == item) return indexof;
        cur = cur->next;
        indexof++;
    }
    return -1;
}

// Kiểm tra chứa item
bool SLinkedList::contains(int item) const {
    // TODO
    Node *cur = head;
    for (int i = 0; i < count; i++){
        if (cur->data == item) return true;
        cur = cur->next;
    }
    return false;
}

// Trả về chuỗi biểu diễn
string SLinkedList::toString() const {
    // TODO: dạng [1]->[2]->[3]...
    Node *cur = head;
    string result;
    for (int i = 0; i < count; i++){
        result += "[" + to_string(cur->data) + "]";
        if (cur->next != nullptr){
            result += "->";
        }
        // (cur->next == nullptr) break;
        cur = cur->next;
    }
    return result;
}

// ====== Các hàm thao tác bổ sung ======

// Trả về phần tử đầu
int& SLinkedList::front() {
    // TODO
    if (count == 0) throw out_of_range("Empty List!");
    return head->data;
}

// Trả về phần tử cuối
int& SLinkedList::back() {
    // TODO
    if (count == 0) throw out_of_range("Empty List!");
    return head->data;
}

// Thay đổi giá trị tại vị trí index
void SLinkedList::set(int index, int e) {
    // TODO
    Node *cur = head;
    for (int i = 0; i < index; i++){
        cur = cur->next;
    }
    cur->data = e;
}

// Xoá và trả về phần tử đầu
int SLinkedList::pop_front() {
    // TODO
    
}

// Xoá và trả về phần tử cuối
int SLinkedList::pop_back() {
    // TODO
}

// Đảo ngược danh sách
void SLinkedList::reverse() {
    // TODO
}

// Xoay danh sách sang trái k bước
void SLinkedList::rotate(int k) {
    // TODO
}

// Trả về phần tử giữa danh sách
int SLinkedList::findMiddle() const {
    // TODO
    return -1;
}

// Trả về phần tử cách cuối n bước
int SLinkedList::nthFromEnd(int n) const {
    // TODO
    return -1;
}

// Nối một danh sách khác vào cuối
void SLinkedList::merge(SLinkedList& other) {
    // TODO
}

// Tách danh sách thành 2 phần tại vị trí index
SLinkedList SLinkedList::split(int index) {
    // TODO
}

// Kiểm tra danh sách có vòng lặp hay không
bool SLinkedList::hasCycle() const {
    // TODO
}

// ===== Thuật toán sắp xếp cho DSLK đơn =====

// Sắp xếp bằng Bubble Sort
void SLinkedList::bubbleSort() {
    // TODO
}

// Sắp xếp bằng Insertion Sort
void SLinkedList::insertionSort() {
    // TODO
}

// Sắp xếp bằng Selection Sort
void SLinkedList::selectionSort() {
    // TODO
}

// Sắp xếp bằng Merge Sort (tốt nhất)
void SLinkedList::mergeSort() {
    // TODO
}


// ================= Iterator ================= //

// Constructor
SLinkedList::Iterator::Iterator(Node* node) {
    //! ➡ Khi bạn tạo iterator, bạn truyền vào một con trỏ Node*. Iterator sẽ giữ nó để biết đang "trỏ" vào đâu.
    current = node;
}

// Toán tử gán
SLinkedList::Iterator& SLinkedList::Iterator::operator=(const Iterator& other) {
    // TODO 
    //! ➡ Cho phép gán một iterator sang iterator khác (ví dụ: it1 = it2;).
    if (this != &other) current = other.current;
    return *this;
}

// Dereference
int& SLinkedList::Iterator::operator*() {
    // TODO: nếu current == nullptr -> throw out_of_range("Iterator is out of range!")
    //! ➡ Dùng để lấy giá trị node hiện tại. Iterator giống như con trỏ nên *it chính là data.
    if (current == nullptr) throw out_of_range("Iterator is out of range!");
    return current->data;
}

// So sánh khác nhau
bool SLinkedList::Iterator::operator!=(const Iterator& other) const {
    // TODO
    //! so sánh current != other.current
    return current != other.current;
}

// Tiến (tiền tố ++it)
SLinkedList::Iterator& SLinkedList::Iterator::operator++() {
    // TODO: nếu current == nullptr -> throw out_of_range("Iterator cannot advance past end!")
    //! ➡ Cho iterator nhảy tới node tiếp theo trong danh sách.
    if (current == nullptr) {
        throw out_of_range("Iterator cannot advance past end!");
    }
    current = current->next;
    return *this;
}

// Tiến (hậu tố it++)
SLinkedList::Iterator SLinkedList::Iterator::operator++(int) {
    // TODO: lưu bản sao, tăng current, trả về bản sao
    if (current == nullptr) {
        throw out_of_range("Iterator cannot advance past end!");
    }
    Iterator old = *this;
    current = current->next;
    return old;
}

// ================= begin() / end() ================= //

SLinkedList::Iterator SLinkedList::begin() {
    // TODO: trả về iterator trỏ vào head
    return Iterator(head);
}

SLinkedList::Iterator SLinkedList::end() {
    // TODO: trả về iterator trỏ nullptr
    return Iterator(nullptr);
}
*/