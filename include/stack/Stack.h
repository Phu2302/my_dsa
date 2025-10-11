#ifndef STACK_H
#define STACK_H

#include "interfaces/IStack.h"
#include "array/ArrayList.h"
#include "linked_list/SLinkedList.h"
#include "lib.h"

/*
 * File: Stack.h
 * -------------
 * Khai báo 2 lớp Stack:
 *  - ArrayStack<T>: sử dụng ArrayList<T>.
 *  - LinkedStack<T>: sử dụng SLinkedList<T>.
 * Mỗi lớp đều có Iterator duyệt phần tử theo thứ tự từ top → bottom.
 */

// ===================== ARRAY STACK =====================
template <class T>
class ArrayStack : public IStack<T> {
private:
    ArrayList<T> list;

public:
    // ===== Constructor / Destructor =====
    ArrayStack();
    ArrayStack(const ArrayStack<T>& other);
    ~ArrayStack();
    ArrayStack<T>& operator=(const ArrayStack<T>& other);

    // ===== Core Methods =====
    void push(const T& element) override;
    T pop() override;
    T& top() override;
    bool empty() const override;
    int size() const override;
    void clear() override;
    bool contains(const T& item) const override;
    bool remove(const T& item) override;
    string toString() const override;

    // ===== Iterator (inner class) =====
    class Iterator {
    private:
        const ArrayStack<T>* stack; // trỏ tới stack gốc
        int index;                  // chỉ số hiện tại
    public:
        Iterator(const ArrayStack<T>* stack, int index);
        Iterator& operator++();     // tiến tới phần tử kế (top → bottom)
        const T& operator*() const;
        bool operator!=(const Iterator& other) const;
    };

    Iterator begin() const;  // phần tử top
    Iterator end() const;    // sau phần tử cuối (bottom)
};

// ===================== LINKED STACK =====================
template <class T>
class LinkedStack : public IStack<T> {
private:
    SLinkedList<T> list;

public:
    // ===== Constructor / Destructor =====
    LinkedStack();
    LinkedStack(const LinkedStack<T>& other);
    ~LinkedStack();
    LinkedStack<T>& operator=(const LinkedStack<T>& other);

    // ===== Core Methods =====
    void push(const T& element) override;
    T pop() override;
    T& top() override;
    bool empty() const override;
    int size() const override;
    void clear() override;
    bool contains(const T& item) const override;
    bool remove(const T& item) override;
    string toString() const override;

    // ===== Iterator (inner class) =====
    class Iterator {
    private:
        typename SLinkedList<T>::Iterator it; // dùng iterator của SLinkedList
    public:
        Iterator(const typename SLinkedList<T>::Iterator& listIt);
        Iterator& operator++();  
        //T& operator*() const;
        const T& operator*() const;
        bool operator!=(const Iterator& other) const;
    };

    Iterator begin() const;  // top
    Iterator end() const;    // null
};

// ===================== DEFAULT STACK TYPE =====================
template <class T>
using Stack = LinkedStack<T>;

#endif /* STACK_H */
