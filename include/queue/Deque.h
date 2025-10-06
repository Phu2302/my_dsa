#ifndef DEQUE_H
#define DEQUE_H
#include "interfaces/IQueue.h"
#include "interfaces/IList.h"
#include "lib.h"

/*
 * Class: Deque<T>
 * ----------------
 * Cài đặt tổng quát cho hàng đợi hai đầu (Deque)
 * sử dụng danh sách tuyến tính (IList<T>) làm backend.
 *
 * Nguyên tắc:
 *  - Có thể thêm / xóa ở cả đầu và cuối.
 *  - Kết hợp được cả hành vi của Stack và Queue.
 */

template <class T>
class Deque : public IQueue<T> {
private:
    IList<T>* list;   // backend lưu dữ liệu (ArrayList, SLinkedList, ...)

public:
    // ===== Constructor & Destructor =====
    Deque(IList<T>* impl = nullptr);             // khởi tạo với backend (nếu nullptr thì dùng ArrayList)
    Deque(const Deque<T>& other);                // sao chép
    ~Deque();                                   // hủy deque và backend nếu cần
    Deque<T>& operator=(const Deque<T>& other); // gán

    // ===== Thao tác cơ bản =====
    void enqueue(const T& element) override;    // thêm phần tử vào cuối (back)
    void enqueueFront(const T& element) override; // thêm phần tử vào đầu (front)
    T dequeue() override;                       // loại bỏ phần tử đầu tiên
    T dequeueBack() override;                   // loại bỏ phần tử cuối cùng
    T& front() override;                        // trả về phần tử đầu
    T& back() override;                         // trả về phần tử cuối
    bool empty() const override;                // kiểm tra deque có rỗng không
    int size() const override;                  // trả về số lượng phần tử
    void clear() override;                      // xóa toàn bộ deque

    // ===== Tiện ích & mở rộng =====
    bool contains(const T& item) const override; // kiểm tra có chứa phần tử item không
    bool remove(const T& item) override;         // xóa lần xuất hiện đầu tiên của phần tử item
    string toString() const override;            // xuất chuỗi mô tả deque (front -> back)
};

#endif /* DEQUE_H */
