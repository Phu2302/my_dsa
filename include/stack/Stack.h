#ifndef STACK_H
#define STACK_H
#include "interfaces/IStack.h"
#include "interfaces/IList.h"
#include "lib.h"

/*
 * Class: Stack<T>
 * ----------------
 * Cài đặt tổng quát cho ngăn xếp (Stack)
 * sử dụng một danh sách tuyến tính (IList<T>) làm backend.
 *
 * Cho phép linh hoạt chọn kiểu danh sách cụ thể:
 *  - ArrayList<T>
 *  - SLinkedList<T>
 *  - DLinkedList<T>
 *
 * Nguyên tắc LIFO (Last In, First Out).
 */

template <class T>
class Stack : public IStack<T> {
private:
    IList<T>* list;    // backend lưu dữ liệu (ArrayList, SLinkedList, ...)

public:
    // ===== Constructor & Destructor =====
    Stack(IList<T>* impl = nullptr);             // khởi tạo với danh sách backend (mặc định nullptr)
    Stack(const Stack<T>& other);                // sao chép
    ~Stack();                                    // hủy stack và backend nếu cần (tùy theo policy cài đặt)
    Stack<T>& operator=(const Stack<T>& other);  // gán

    // ===== Thao tác cơ bản =====
    void push(const T& element) override;        // thêm phần tử vào đỉnh
    T pop() override;                            // loại bỏ phần tử ở đỉnh và trả về giá trị
    T& top() override;                           // trả về phần tử ở đỉnh mà không loại bỏ
    bool empty() const override;                 // kiểm tra ngăn xếp có rỗng không
    int size() const override;                   // trả về số lượng phần tử
    void clear() override;                       // xóa toàn bộ ngăn xếp

    // ===== Tiện ích & mở rộng =====
    bool contains(const T& item) const override; // kiểm tra có chứa phần tử item không
    bool remove(const T& item) override;         // xóa lần xuất hiện đầu tiên của phần tử item (từ top xuống)
    string toString() const override;            // xuất chuỗi mô tả stack (ví dụ: [top -> bottom])
};

#endif /* STACK_H */
