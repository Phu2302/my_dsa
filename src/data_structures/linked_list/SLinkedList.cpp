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
    // tạo list rỗng -> gán từng cái other vào list rỗng
    head = nullptr;
    tail = nullptr;
    count = 0;

    Node *cur = other.head;
    while (cur != nullptr){
        Node *newNode = new Node(cur->data, nullptr);
        if (head == nullptr){
            head = newNode;
            tail = newNode;
        }
        else {
            tail->next = newNode;
            tail = newNode;
        }
        count++;
        cur = cur->next;
    }
}

// Destructor: giải phóng toàn bộ bộ nhớ
template<class T>
SLinkedList<T>::~SLinkedList() {
    Node *cur = head;
    while (cur != nullptr){
        Node *temp = cur;
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
    // xóa list hiện tại -> tạo list rỗng -> gán other vào list rỗng
    if (this != &other){
        Node *cur = head;
        while (cur != nullptr){
            Node *del = cur;
            cur = cur->next;
            delete del;
        }
        tail = nullptr;
        head = nullptr;
        count = 0;

        Node *curOther = other.head;
        while (curOther != nullptr){
            Node *newNode = new Node(curOther->data, nullptr);
            if (head == nullptr){
                head = newNode;
                tail = newNode;
            }
            else {
                tail->next = newNode;
                tail = newNode;
            }
            count++;
            curOther = curOther->next;
        }
    }
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
    if (count == 0) throw out_of_range("Empty List");

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
        T val = del->data;
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
    if (count == 0) throw out_of_range("Empty List");
    Node *cur = head;
    int idx = 0;
    while (cur != nullptr){
        if (cur->data == item) {
            SLinkedList::removeAt(idx);
            return true;
        }
        idx++;
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
T& SLinkedList<T>::get(int index) {
    if (count == 0) throw out_of_range("Empty List");
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
    if (count == 0) throw out_of_range("Empty List");
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
    if (count == 0) throw out_of_range("Empty List");
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
bool SLinkedList<T>::contains(const T& item) const {
    if (count == 0) throw out_of_range("Empty List");
    Node *cur = head;
    while (cur != nullptr){
        if (cur->data == item) return true;
        cur = cur->next;
    }
    return false;
}

// Trả về phần tử đầu tiên của danh sách
template<class T>
T& SLinkedList<T>::front() {
    if (count == 0) throw out_of_range("Empty List");
    return head->data;
}

// Trả về phần tử cuối cùng của danh sách
template<class T>
T& SLinkedList<T>::back() {
    if (count == 0) throw out_of_range("Empty List");
    return tail->data;
}

// Xóa và trả về phần tử đầu tiên của danh sách
template<class T>
T SLinkedList<T>::pop_front() {
    if (count == 0) throw out_of_range("Empty List");
    Node *del = head;
    if (count == 1){
        Node *del = head;
        T val = del->data;
        head = nullptr;
        tail = nullptr;
        delete del;
        count--;
        return val;
    }
    T val = del->data;
    head = head->next;
    delete del;
    count--;
    return val;
}

// Xóa và trả về phần tử cuối cùng của danh sách
template<class T>
T SLinkedList<T>::pop_back() {
    if (count == 0) throw out_of_range("Empty List");
    Node *cur = head;
    if (count == 1){
        Node *del = head;
        T val = del->data;
        head = nullptr;
        tail = nullptr;
        delete del;
        count--;
        return val;
    }
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
SLinkedList<T>::Iterator::Iterator(Node *node){
    current = node;
}

// Toán tử gán
template<class T>
typename SLinkedList<T>::Iterator&
SLinkedList<T>::Iterator::operator=(const Iterator& other) {
    current = other.current;
    return *this;
}

// Truy cập phần tử hiện tại
template<class T>
T& SLinkedList<T>::Iterator::operator*() {
    if (current == nullptr) throw out_of_range("Iterator is out of range!");
    return current->data;
}

template<class T>
const T& SLinkedList<T>::Iterator::operator*() const {
    // Time complexity: O(1)
    return current->data;
}


// So sánh iterator khác nhau
template<class T>
bool SLinkedList<T>::Iterator::operator!=(const Iterator& other) const {
    if (current != other.current) return true;
    return false;
}

// So sánh iterator bằng nhau
template<class T>
bool SLinkedList<T>::Iterator::operator==(const Iterator& other) const {
    if (current != other.current) return false;
    return true;
}

// Tiến tiền tố ++it
template<class T>
typename SLinkedList<T>::Iterator&
SLinkedList<T>::Iterator::operator++() {
    if (current == nullptr) throw out_of_range("This is the end, cannot move");
    current = current->next;
    return *this;
}

// Tiến hậu tố it++
template<class T>
typename SLinkedList<T>::Iterator
SLinkedList<T>::Iterator::operator++(int) {
    if (current == nullptr) throw out_of_range("This is the end, cannot move");
    Iterator old = *this;
    current = current->next;
    return old;
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

template<class T>
typename SLinkedList<T>::Iterator SLinkedList<T>::begin() const {
    return Iterator(head);
}

template<class T>
typename SLinkedList<T>::Iterator SLinkedList<T>::end() const {
    return Iterator(nullptr);
}


// ======================= EXPLICIT INSTANTIATION =======================
template class SLinkedList<int>;
template class SLinkedList<double>;
template class SLinkedList<string>;
template class SLinkedList<char>;
template class SLinkedList<float>;
