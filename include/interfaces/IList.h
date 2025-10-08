#ifndef ILIST_H
#define ILIST_H
#include "lib.h"

/*
 * Interface: IList<T>
 * -------------------
 * Mô tả trừu tượng cho kiểu dữ liệu danh sách tuyến tính.
 * Các lớp kế thừa: ArrayList<T>, SLinkedList<T>, DLinkedList<T>
 *
 * Yêu cầu:
 *  - T hỗ trợ copy assignment (operator=)
 *  - index tính từ 0
 */

template <class T>
class IList {
public:
    virtual ~IList() {}

    // ===== CRUD cơ bản =====
    virtual void add(const T& element) = 0;               // thêm cuối
    virtual void add(int index, const T& element) = 0;    // thêm tại index
    virtual T removeAt(int index) = 0;                    // xóa tại index
    virtual bool removeItem(const T& item) = 0;           // xóa phần tử có giá trị item
    virtual void set(int index, const T& element) = 0;    // gán lại phần tử tại index

    // ===== Truy cập & thông tin =====
    virtual T& get(int index) = 0;                        // lấy phần tử tại index
    virtual bool empty() const = 0;                       // danh sách rỗng?
    virtual int size() const = 0;                         // số phần tử
    virtual void clear() = 0;                             // xóa toàn bộ danh sách
    virtual int indexOf(const T& item) const = 0;          // vị trí phần tử đầu tiên (hoặc -1)
    virtual bool contains(const T& item) const = 0;        // kiểm tra tồn tại

    // ===== Tiện ích đầu/cuối =====
    virtual T& front() = 0;                               // phần tử đầu
    virtual T& back() = 0;                                // phần tử cuối
    virtual T pop_front() = 0;                            // xóa & trả về phần tử đầu
    virtual T pop_back() = 0;                             // xóa & trả về phần tử cuối

    // ===== Xuất chuỗi (debug) =====
    virtual string toString() const = 0;
};

#endif /* ILIST_H */
