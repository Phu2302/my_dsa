#ifndef SLINKEDLIST_H
#define SLINKEDLIST_H

#include "interfaces/IList.h"

// ================= SLinkedList ================= //
template <class T>
class SLinkedList : public IList<T> {
private:
    class Node {
    public:
        T data;      // dữ liệu
        Node* next;  // con trỏ tới nút tiếp theo

        Node(const T& val, Node* nxt = nullptr){
            data = val;
            next = nxt;
        }
    };

    Node* head;  // nút đầu
    Node* tail;  // nút cuối
    int count;   // số lượng phần tử

public:
    // ===== Constructor & Destructor =====
    SLinkedList();  // constructor
    SLinkedList(const SLinkedList<T>& other);  // constructor sao chép
    ~SLinkedList();  // destructor
    SLinkedList<T>& operator=(const SLinkedList<T>& other);  // toán tử gán

    // ===== Các hàm thao tác (theo IList) =====
    void add(const T& e) override;              // thêm cuối
    void add(int index, const T& e) override;   // thêm tại index
    T removeAt(int index) override;             // xóa tại index
    bool removeItem(const T& item) override;    // xóa phần tử có giá trị item
    bool empty() const override;                // kiểm tra rỗng
    int size() const override;                  // số lượng phần tử
    void clear() override;                      // xóa toàn bộ danh sách
    T& get(int index) override;                 // lấy phần tử tại index
    int indexOf(const T& item) const override;  // tìm chỉ số phần tử
    bool contains(const T& item) const override;// kiểm tra tồn tại
    string toString() const override;           // trả về chuỗi mô tả danh sách

    T& front() override;                        // phần tử đầu
    T& back() override;                         // phần tử cuối
    void set(int index, const T& e) override;   // thay đổi giá trị tại vị trí index
    T pop_front() override;                     // xóa và trả về phần tử đầu
    T pop_back() override;                      // xóa và trả về phần tử cuối

    // ===== Iterator =====
    class Iterator {
    private:
        Node* current;   // con trỏ tới node hiện tại
    public:
        Iterator(Node* node = nullptr);

        Iterator& operator=(const Iterator& other);
        T& operator*();                       // truy cập data
        bool operator!=(const Iterator& other) const;
        bool operator==(const Iterator& other) const;
        Iterator& operator++();               // tiền tố ++it
        Iterator operator++(int);             // hậu tố it++
    };

    Iterator begin();    // iterator trỏ tới head
    Iterator end();      // iterator null (sau tail)
};

#endif // SLINKEDLIST_H
