#ifndef ISTACK_H
#define ISTACK_H
#include "lib.h"

/*
 * Interface: IStack<T>
 * --------------------
 * Mô tả trừu tượng cho cấu trúc dữ liệu ngăn xếp (Stack).
 * Các lớp kế thừa: Stack<T>, ArrayStack<T>, LinkedStack<T>, v.v.
 *
 * Đặc điểm:
 *  - Nguyên tắc LIFO (Last In, First Out)
 *  - Thao tác chỉ ở đỉnh ngăn xếp (top)
 *
 * Yêu cầu:
 *  - T hỗ trợ copy assignment (operator=)
 */

template <class T>
class IStack {
public:
    virtual ~IStack() {}

    // ===== Thao tác cơ bản =====
    virtual void push(const T& element) = 0;       // đưa phần tử vào đỉnh ngăn xếp
    virtual T pop() = 0;                           // loại bỏ phần tử ở đỉnh và trả về giá trị của nó
    virtual T& top() = 0;                          // trả về phần tử ở đỉnh mà không loại bỏ
    virtual bool empty() const = 0;                // kiểm tra ngăn xếp có rỗng hay không
    virtual int size() const = 0;                  // trả về số lượng phần tử trong ngăn xếp
    virtual void clear() = 0;                      // xóa toàn bộ ngăn xếp

    // ===== Tiện ích & mở rộng =====
    virtual bool contains(const T& item) const = 0; // kiểm tra ngăn xếp có chứa phần tử item hay không
    virtual bool remove(const T& item) = 0;         // xóa lần xuất hiện đầu tiên của phần tử item (từ top xuống)
    virtual string toString() const = 0;            // xuất chuỗi mô tả stack (ví dụ: [top -> bottom])
};

#endif /* ISTACK_H */
