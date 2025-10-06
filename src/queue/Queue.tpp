#include "queue/Queue.h"

// ===== Constructor =====
Queue::Queue() {
    // TODO: khởi tạo head, tail, count
}

// ===== Destructor =====
Queue::~Queue() {
    // TODO: giải phóng toàn bộ node
}

// ===== Các hàm thao tác cơ bản =====

// Thêm phần tử vào cuối
void Queue::enqueue(int e) {
    // TODO
}

// Xoá và trả về phần tử đầu
int Queue::dequeue() {
    // TODO
    return 0;
}

// Truy cập phần tử đầu
int& Queue::front() {
    // TODO
    static int dummy = 0;
    return dummy;
}

// Truy cập phần tử cuối
int& Queue::back() {
    // TODO
    static int dummy = 0;
    return dummy;
}

// Kiểm tra rỗng
bool Queue::empty() const {
    // TODO
    return true;
}

// Trả về số phần tử hiện có
int Queue::size() const {
    // TODO
    return 0;
}

// Xoá toàn bộ queue
void Queue::clear() {
    // TODO
}

// Biểu diễn queue dưới dạng chuỗi
string Queue::toString() const {
    // TODO
    return "";
}
