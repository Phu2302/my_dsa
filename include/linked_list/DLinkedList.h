#ifndef DLINKEDLIST_H
#define DLINKEDLIST_H

#include "interfaces/IList.h"
#include "lib.h"

/*
 * Class: DLinkedList<T>
 * ---------------------
 * Cài đặt danh sách liên kết đôi (doubly linked list)
 * Kế thừa giao diện IList<T>.
 *
 * - Mỗi Node có con trỏ prev và next.
 * - Hỗ trợ iterator hai chiều (++ và --).
 */

template <class T>
class DLinkedList : public IList<T> {
private:
    // ================= Node ================= //
    class Node {
    public:
        T data;       // dữ liệu
        Node* prev;   // nút trước
        Node* next;   // nút kế
        Node(const T& val, Node* p = nullptr, Node* n = nullptr)
            : data(val), prev(p), next(n) {}
    };

    Node* head;   // nút đầu
    Node* tail;   // nút cuối
    int count;    // số lượng phần tử

public:
    // ===== Constructor & Destructor =====
    DLinkedList();
    DLinkedList(const DLinkedList<T>& other);
    ~DLinkedList();
    DLinkedList<T>& operator=(const DLinkedList<T>& other);

    // ===== Các hàm thao tác (theo IList) =====
    void add(const T& e) override;              // thêm cuối
    void add(int index, const T& e) override;   // thêm tại index
    T removeAt(int index) override;             // xóa tại index
    bool removeItem(const T& item) override;    // xóa phần tử có giá trị item
    bool empty() const override;                // kiểm tra rỗng
    int size() const override;                  // trả về số lượng phần tử
    void clear() override;                      // xóa toàn bộ danh sách
    T& get(int index) override;                 // lấy phần tử tại index
    int indexOf(const T& item) const override;  // tìm chỉ số phần tử
    bool contains(const T& item) const override;// kiểm tra chứa phần tử
    string toString() const override;           // chuỗi mô tả danh sách

    T& front() override;                        // phần tử đầu
    T& back() override;                         // phần tử cuối
    void set(int index, const T& e) override;   // thay đổi giá trị tại index
    T pop_front() override;                     // xóa & trả về phần tử đầu
    T pop_back() override;                      // xóa & trả về phần tử 
    
    // ===== Sorting algorithms =====
    void bubbleSort();
    void insertionSort();
    void mergeSort();


    // ===== Iterator =====
    class Iterator {
    private:
        Node* current;   // con trỏ nút hiện tại
    public:
        Iterator(Node* node = nullptr);

        Iterator& operator=(const Iterator& other);
        T& operator*();                       // truy cập data
        bool operator!=(const Iterator& other) const;
        bool operator==(const Iterator& other) const;
        Iterator& operator++();               // tiến tới nút kế
        Iterator operator++(int);             // hậu tố ++
        Iterator& operator--();               // lùi về nút trước
        Iterator operator--(int);             // hậu tố --
    };

    Iterator begin();     // iterator trỏ tới head
    Iterator end();       // iterator sau tail (nullptr)
    Iterator rbegin();    // iterator trỏ tới tail
    Iterator rend();      // iterator trước head (nullptr)
    Iterator begin() const;
    Iterator end() const;

};

#endif /* DLINKEDLIST_H */
