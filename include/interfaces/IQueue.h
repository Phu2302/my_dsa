#ifndef IQUEUE_H
#define IQUEUE_H
#include "lib.h"

/*
 * Interface: IQueue<T>
 * --------------------
 * Mô tả trừu tượng cho cấu trúc dữ liệu hàng đợi (Queue).
 * Các lớp kế thừa: Queue<T>, Deque<T>, ArrayQueue<T>, LinkedQueue<T>, v.v.
 *
 * Đặc điểm:
 *  - Nguyên tắc FIFO (First In, First Out)
 *  - Cung cấp các thao tác thêm / xóa / truy cập ở đầu và cuối.
 *  - Với Queue: chỉ dùng enqueue() và dequeue()
 *  - Với Deque: có thể dùng thêm enqueueFront() và dequeueBack()
 */

template <class T>
class IQueue {
public:
    virtual ~IQueue() {}

    // ===== Thao tác cơ bản =====
    virtual void enqueue(const T& element) = 0;   // thêm phần tử vào cuối hàng đợi (back)
    virtual T dequeue() = 0;                      // loại bỏ phần tử đầu tiên (front)
    virtual T& front() = 0;                       // trả về phần tử đầu tiên mà không loại bỏ
    virtual T& back() = 0;                        // trả về phần tử cuối cùng mà không loại bỏ
    virtual bool empty() const = 0;               // kiểm tra hàng đợi có rỗng không
    virtual int size() const = 0;                 // trả về số lượng phần tử trong hàng đợi
    virtual void clear() = 0;                     // xóa toàn bộ hàng đợi

    // ===== Thao tác mở rộng (dành cho Deque) =====
    virtual void enqueueFront(const T& element) {} // thêm phần tử vào đầu (Deque)
    virtual T dequeueBack() { return T{}; }         // loại bỏ phần tử cuối (Deque)

    // ===== Tiện ích & mở rộng =====
    virtual bool contains(const T& item) const = 0; // kiểm tra có chứa phần tử item không
    virtual bool remove(const T& item) = 0;         // xóa lần xuất hiện đầu tiên của phần tử item
    virtual string toString() const = 0;            // xuất chuỗi mô tả queue (ví dụ: [front -> back])
};

#endif /* IQUEUE_H */
