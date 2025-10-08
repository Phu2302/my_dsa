#include "linked_list/SLinkedList.h"
#include "lib.h"

// ======================= CONSTRUCTOR / DESTRUCTOR =======================

// Khởi tạo danh sách rỗng
template<class T>
SLinkedList<T>::SLinkedList() {
    head = nullptr;
    tail = nullptr;
    count = 0;
}

// Constructor sao chép
template<class T>
SLinkedList<T>::SLinkedList(const SLinkedList<T>& other) {

}

// Destructor: giải phóng toàn bộ bộ nhớ
template<class T>
SLinkedList<T>::~SLinkedList() {
    Node *cur = head;
    while (cur != nullptr){
        Node *temp = head;
        cur = cur->next;
        delete temp;
    }
    tail = nullptr;
    head = nullptr;
    count = 0;
}

// Toán tử gán
template<class T>
SLinkedList<T>& SLinkedList<T>::operator=(const SLinkedList<T>& other) {
    
    return *this;
}

// ======================= CÀI ĐẶT CÁC HÀM IList =======================

// Thêm phần tử vào cuối danh sách
template<class T>
void SLinkedList<T>::add(const T& e) {
    Node *newNode = new Node(e, nullptr);
    if (count == 0){
        head = newNode;
        tail = newNode;
        count++;
        return;
    }
    tail->next = newNode;
    tail = newNode;
    count++;
}

// Thêm phần tử tại vị trí index
template<class T>
void SLinkedList<T>::add(int index, const T& e) {
    if (index < 0 || index > count) throw out_of_range("Index is invalid!");
    Node *newNode = new Node(e, nullptr);
    if (count == 0){
        head = newNode;
        tail = newNode;
        count++;
        return;
    }

    if (index = 0){
        newNode->next = head;
        head = newNode;
        count++;
        return;
    }

    if (index = count){
        tail->next = newNode;
        tail = newNode;
        count++;
        return;
    }

    Node *temp = head;
    for (int i = 0; i < index-1; i++){
        temp = temp->next; // move to before index
    }
    newNode->next = temp->next;
    temp->next = newNode;
    count++;
}

// Xóa phần tử tại vị trí index, trả về phần tử đã xóa
template<class T>
T SLinkedList<T>::removeAt(int index) {
    if (index < 0 || index >= count) throw out_of_range("Index is invalid!");
    if (count == 0) throw out_of_range("Emty List");

    if (count == 1){
        Node *del = head;
        T val = del->data;
        delete del;
        head = nullptr;
        tail = nullptr;
        count--;
        return val;
    }

    if (index == 0){
        Node *del = head;
        T val = del->data;
        head = head->next;
        delete del;
        count--;
        return val;
    }

    if (index == count-1){
        Node *cur = head;
        while (cur->next->next != nullptr){
            cur = cur->next;
        }
        Node *del = cur->next;
        T val = cur->next->data;
        tail = cur;
        delete del;
        cur->next = nullptr;
        count--;
        return val;
    }

    Node *cur = head;
    for (int i = 0; i < index-1; i++){
        cur = cur->next;
    }
    Node *del = cur->next;
    T val = cur->next->data;
    cur->next = cur->next->next;
    delete del;
    count--;
    return val;
}

// Xóa phần tử có giá trị item (nếu tồn tại)
template<class T>
bool SLinkedList<T>::removeItem(const T& item) {
    if (count == 0) throw out_of_range("Emty List");
    Node *cur = head;
    while (cur != nullptr){
        if (cur->data == item) return true;
        cur = cur->next;
    }
    return false;
}

// Kiểm tra danh sách có rỗng hay không
template<class T>
bool SLinkedList<T>::empty() const {
    if (count == 0) return true;
    return false;
}

// Trả về số lượng phần tử trong danh sách
template<class T>
int SLinkedList<T>::size() const {
    return count;
}

// Xóa toàn bộ danh sách
template<class T>
void SLinkedList<T>::clear() {
    if (count == 0) throw out_of_range("Emty List");
    Node *cur = head;
    while (cur != head){
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
T& SLinkedList<T>::get(int index) {
    if (count == 0) throw out_of_range("Emty List");
    if (index < 0 || index >= count) throw out_of_range("Index is invalid");
    Node *cur = head;
    for (int i = 0; i < index; i++){
        cur = cur->next;
    }
    return cur->data;
}

// Gán giá trị mới cho phần tử tại vị trí index
template<class T>
void SLinkedList<T>::set(int index, const T& e) {
    if (count == 0) throw out_of_range("Emty List");
    if (index < 0 || index >= count) throw out_of_range("Index is invalid");
    Node *cur = head;
    for (int i = 0; i < index; i++){
        cur = cur->next;
    }
    cur->data = e;
}

// Trả về vị trí đầu tiên của phần tử item (hoặc -1 nếu không có)
template<class T>
int SLinkedList<T>::indexOf(const T& item) const {
    if (count == 0) throw out_of_range("Emty List");
    Node *cur = head;
    int idx = 0;
    while (cur != head){
        if (cur->data == item) return idx;
        idx++;
        cur = cur->next;
    }
    return -1;
}

// Kiểm tra danh sách có chứa phần tử item không
template<class T>
bool SLinkedList<T>::contains(const T& item) const {
    if (count == 0) throw out_of_range("Emty List");
    Node *cur = head;
    while (cur != head){
        if (cur->data == item) return true;
        cur = cur->next;
    }
    return false;
}

// Trả về phần tử đầu tiên của danh sách
template<class T>
T& SLinkedList<T>::front() {
    if (count == 0) throw out_of_range("Emty List");
    T val = head->data;
    return val;
}

// Trả về phần tử cuối cùng của danh sách
template<class T>
T& SLinkedList<T>::back() {
    if (count == 0) throw out_of_range("Emty List");
    T val = tail->data;
    return val;
}

// Xóa và trả về phần tử đầu tiên của danh sách
template<class T>
T SLinkedList<T>::pop_front() {
    if (count == 0) throw out_of_range("Emty List");
    Node *del = head;
    T val = del->data;
    head = head->next;
    delete del;
    count--;
    return val;
}

// Xóa và trả về phần tử cuối cùng của danh sách
template<class T>
T SLinkedList<T>::pop_back() {
    Node *cur = head;
    while (cur->next->next != nullptr){
        cur = cur->next;
    }
    Node *del = cur->next;
    T val = del->data;
    tail = cur;
    cur->next = nullptr;
    count--;
    delete del;
    return val;
}

// Trả về chuỗi biểu diễn danh sách (ví dụ: [1, 2, 3])
template<class T>
string SLinkedList<T>::toString() const {
    if (count == 0) return "[]";

    ostringstream re;
    re << "[";
    Node* cur = head;
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
SLinkedList<T>::Iterator::Iterator(Node<T>* node)
    : current(node) {
    
}

// Toán tử gán
template<class T>
typename SLinkedList<T>::Iterator&
SLinkedList<T>::Iterator::operator=(const Iterator& other) {
    
    return *this;
}

// Truy cập phần tử hiện tại
template<class T>
T& SLinkedList<T>::Iterator::operator*() {
    
    static T temp{};
    return temp;
}

// So sánh iterator khác nhau
template<class T>
bool SLinkedList<T>::Iterator::operator!=(const Iterator& other) const {
    
    return true;
}

// So sánh iterator bằng nhau
template<class T>
bool SLinkedList<T>::Iterator::operator==(const Iterator& other) const {
    
    return false;
}

// Tiến tiền tố ++it
template<class T>
typename SLinkedList<T>::Iterator&
SLinkedList<T>::Iterator::operator++() {
    
    return *this;
}

// Tiến hậu tố it++
template<class T>
typename SLinkedList<T>::Iterator
SLinkedList<T>::Iterator::operator++(int) {
    
    return *this;
}

// Trả về iterator đầu danh sách
template<class T>
typename SLinkedList<T>::Iterator SLinkedList<T>::begin() {
    
    return Iterator(head);
}

// Trả về iterator sau phần tử cuối cùng
template<class T>
typename SLinkedList<T>::Iterator SLinkedList<T>::end() {
    
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
    : Khởi tạo head, tail = nullptr, count = 0
    head = nullptr;
    tail = nullptr;
    count = 0;
}

// Destructor
SLinkedList::~SLinkedList() {
    : Giải phóng toàn bộ node để tránh rò rỉ bộ nhớ
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
    : nếu index không hợp lệ -> throw out_of_range("Index is invalid!")
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
    : duyệt list, tìm node có data == item, xóa node đầu tiên tìm thấy
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
    
    if (count == 0) return true;
    return false;
}

// Trả về số phần tử
int SLinkedList::size() const {
    
    return count;
}

// Xóa toàn bộ danh sách
void SLinkedList::clear() {
    
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
    : nếu index không hợp lệ -> throw out_of_range("Index is invalid!")
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
    
    Node *cur = head;
    for (int i = 0; i < count; i++){
        if (cur->data == item) return true;
        cur = cur->next;
    }
    return false;
}

// Trả về chuỗi biểu diễn
string SLinkedList::toString() const {
    : dạng [1]->[2]->[3]...
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
    
    if (count == 0) throw out_of_range("Empty List!");
    return head->data;
}

// Trả về phần tử cuối
int& SLinkedList::back() {
    
    if (count == 0) throw out_of_range("Empty List!");
    return head->data;
}

// Thay đổi giá trị tại vị trí index
void SLinkedList::set(int index, int e) {
    
    Node *cur = head;
    for (int i = 0; i < index; i++){
        cur = cur->next;
    }
    cur->data = e;
}

// Xoá và trả về phần tử đầu
int SLinkedList::pop_front() {
    
    
}

// Xoá và trả về phần tử cuối
int SLinkedList::pop_back() {
    
}

// Đảo ngược danh sách
void SLinkedList::reverse() {
    
}

// Xoay danh sách sang trái k bước
void SLinkedList::rotate(int k) {
    
}

// Trả về phần tử giữa danh sách
int SLinkedList::findMiddle() const {
    
    return -1;
}

// Trả về phần tử cách cuối n bước
int SLinkedList::nthFromEnd(int n) const {
    
    return -1;
}

// Nối một danh sách khác vào cuối
void SLinkedList::merge(SLinkedList& other) {
    
}

// Tách danh sách thành 2 phần tại vị trí index
SLinkedList SLinkedList::split(int index) {
    
}

// Kiểm tra danh sách có vòng lặp hay không
bool SLinkedList::hasCycle() const {
    
}

// ===== Thuật toán sắp xếp cho DSLK đơn =====

// Sắp xếp bằng Bubble Sort
void SLinkedList::bubbleSort() {
    
}

// Sắp xếp bằng Insertion Sort
void SLinkedList::insertionSort() {
    
}

// Sắp xếp bằng Selection Sort
void SLinkedList::selectionSort() {
    
}

// Sắp xếp bằng Merge Sort (tốt nhất)
void SLinkedList::mergeSort() {
    
}


// ================= Iterator ================= //

// Constructor
SLinkedList::Iterator::Iterator(Node* node) {
    //! ➡ Khi bạn tạo iterator, bạn truyền vào một con trỏ Node*. Iterator sẽ giữ nó để biết đang "trỏ" vào đâu.
    current = node;
}

// Toán tử gán
SLinkedList::Iterator& SLinkedList::Iterator::operator=(const Iterator& other) {
     
    //! ➡ Cho phép gán một iterator sang iterator khác (ví dụ: it1 = it2;).
    if (this != &other) current = other.current;
    return *this;
}

// Dereference
int& SLinkedList::Iterator::operator*() {
    : nếu current == nullptr -> throw out_of_range("Iterator is out of range!")
    //! ➡ Dùng để lấy giá trị node hiện tại. Iterator giống như con trỏ nên *it chính là data.
    if (current == nullptr) throw out_of_range("Iterator is out of range!");
    return current->data;
}

// So sánh khác nhau
bool SLinkedList::Iterator::operator!=(const Iterator& other) const {
    
    //! so sánh current != other.current
    return current != other.current;
}

// Tiến (tiền tố ++it)
SLinkedList::Iterator& SLinkedList::Iterator::operator++() {
    : nếu current == nullptr -> throw out_of_range("Iterator cannot advance past end!")
    //! ➡ Cho iterator nhảy tới node tiếp theo trong danh sách.
    if (current == nullptr) {
        throw out_of_range("Iterator cannot advance past end!");
    }
    current = current->next;
    return *this;
}

// Tiến (hậu tố it++)
SLinkedList::Iterator SLinkedList::Iterator::operator++(int) {
    : lưu bản sao, tăng current, trả về bản sao
    if (current == nullptr) {
        throw out_of_range("Iterator cannot advance past end!");
    }
    Iterator old = *this;
    current = current->next;
    return old;
}

// ================= begin() / end() ================= //

SLinkedList::Iterator SLinkedList::begin() {
    : trả về iterator trỏ vào head
    return Iterator(head);
}

SLinkedList::Iterator SLinkedList::end() {
    : trả về iterator trỏ nullptr
    return Iterator(nullptr);
}
*/