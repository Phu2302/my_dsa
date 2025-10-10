#include "queue/Deque.h"
#include <sstream>

// ===== Constructor =====
template <typename T>
Deque<T>::Deque() {
    // TODO: khởi tạo head, tail, count
}

// ===== Destructor =====
template <typename T>
Deque<T>::~Deque() {
    // TODO: giải phóng toàn bộ node
}

// ===== Các hàm thao tác cơ bản =====

// Thêm phần tử vào đầu
template <typename T>
void Deque<T>::push_front(const T& e) {
    // TODO
}

// Thêm phần tử vào cuối
template <typename T>
void Deque<T>::push_back(const T& e) {
    // TODO
}

// Xoá và trả về phần tử đầu
template <typename T>
T Deque<T>::pop_front() {
    // TODO
    return T();
}

// Xoá và trả về phần tử cuối
template <typename T>
T Deque<T>::pop_back() {
    // TODO
    return T();
}

// Truy cập phần tử đầu
template <typename T>
T& Deque<T>::front() {
    // TODO
    static T dummy{};
    return dummy;
}

// Truy cập phần tử cuối
template <typename T>
T& Deque<T>::back() {
    // TODO
    static T dummy{};
    return dummy;
}

// Kiểm tra rỗng
template <typename T>
bool Deque<T>::empty() const {
    // TODO
    return true;
}

// Trả về số phần tử hiện có
template <typename T>
int Deque<T>::size() const {
    // TODO
    return 0;
}

// Xoá toàn bộ deque
template <typename T>
void Deque<T>::clear() {
    // TODO
}

// Biểu diễn deque dưới dạng chuỗi
template <typename T>
string Deque<T>::toString() const {
    // TODO
    return "";
}
