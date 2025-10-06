#ifndef QUEUE_H
#define QUEUE_H
#include "interfaces/IQueue.h"
#include "interfaces/IList.h"
#include "lib.h"

/*
 * Class: Queue<T>
 * ----------------
 * Cài đặt tổng quát cho hàng đợi (Queue)
 * sử dụng danh sách tuyến tính (IList<T>) làm backend.
 *
 * Nguyên tắc FIFO (First In, First Out):
 *  - enqueue: thêm phần tử vào cuối (back)
 *  - dequeue: loại bỏ phần tử ở đầu (front)
 */

template <class T>
class Queue : public IQueue<T> {
private:
    IList<T>* list;   // backend lưu dữ liệu (ArrayList, SLinkedList, ...)

public:
    // ===== Constructor & Destructor =====
    Queue(IList<T>* impl = nullptr);              // khởi tạo với backend (nếu nullptr thì dùng ArrayList)
    Queue(const Queue<T>& other);                 // sao chép
    ~Queue();                                    // hủy queue và backend nếu cần
    Queue<T>& operator=(const Queue<T>& other);  // gán

    // ===== Thao tác cơ bản =====
    void enqueue(const T& element) override;     // thêm phần tử vào cuối
    T dequeue() override;                        // loại bỏ phần tử đầu tiên
    T& front() override;                         // trả về phần tử đầu tiên
    T& back() override;                          // trả về phần tử cuối cùng
    bool empty() const override;                 // kiểm tra hàng đợi có rỗng không
    int size() const override;                   // trả về số lượng phần tử
    void clear() override;                       // xóa toàn bộ hàng đợi

    // ===== Tiện ích & mở rộng =====
    bool contains(const T& item) const override; // kiểm tra có chứa phần tử item không
    bool remove(const T& item) override;         // xóa phần tử đầu tiên trùng item
    string toString() const override;            // xuất chuỗi mô tả queue (front -> back)
};

#endif /* QUEUE_H */
