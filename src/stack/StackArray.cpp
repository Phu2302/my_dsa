#include "stack/Stack.h"
#include "array/ArrayList.h"
#include "lib.h"

// ======================= CONSTRUCTOR / DESTRUCTOR =======================

// Khởi tạo stack: nếu không truyền backend, dùng ArrayList mặc định
template<class T>
Stack<T>::Stack(IList<T>* impl) {
    // TODO
}

// Constructor sao chép
template<class T>
Stack<T>::Stack(const Stack<T>& other) {
    // TODO
}

// Destructor: giải phóng tài nguyên backend nếu có
template<class T>
Stack<T>::~Stack() {
    // TODO
}

// Toán tử gán
template<class T>
Stack<T>& Stack<T>::operator=(const Stack<T>& other) {
    // TODO
    return *this;
}

// ======================= CÀI ĐẶT CÁC HÀM IStack =======================

// Thêm phần tử vào đỉnh stack
template<class T>
void Stack<T>::push(const T& element) {
    // TODO
}

// Loại bỏ phần tử ở đỉnh và trả về giá trị của nó
template<class T>
T Stack<T>::pop() {
    // TODO
    return T{};
}

// Trả về phần tử ở đỉnh mà không loại bỏ
template<class T>
T& Stack<T>::top() {
    // TODO
    static T temp{};
    return temp;
}

// Kiểm tra ngăn xếp có rỗng không
template<class T>
bool Stack<T>::empty() const {
    // TODO
    return false;
}

// Trả về số lượng phần tử trong ngăn xếp
template<class T>
int Stack<T>::size() const {
    // TODO
    return 0;
}

// Xóa toàn bộ ngăn xếp
template<class T>
void Stack<T>::clear() {
    // TODO
}

// ======================= TIỆN ÍCH & MỞ RỘNG =======================

// Kiểm tra có chứa phần tử item không
template<class T>
bool Stack<T>::contains(const T& item) const {
    // TODO
    return false;
}

// Xóa lần xuất hiện đầu tiên của phần tử item (từ top xuống)
template<class T>
bool Stack<T>::remove(const T& item) {
    // TODO
    return false;
}

// Xuất chuỗi mô tả stack (ví dụ: [top -> bottom])
template<class T>
string Stack<T>::toString() const {
    // TODO
    return "[]";
}

// ======================= EXPLICIT INSTANTIATION =======================
template class Stack<int>;
template class Stack<double>;
template class Stack<string>;
template class Stack<char>;
template class Stack<float>;
