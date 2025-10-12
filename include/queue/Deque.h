#ifndef DEQUE_H
#define DEQUE_H

#include "interfaces/IQueue.h"
#include "array/ArrayList.h"
#include "linked_list/DLinkedList.h"

/*
 * Class: ArrayDeque<T>
 * --------------------
 * Triển khai deque (Double-ended Queue) sử dụng ArrayList.
 *  - Cho phép thêm / xóa ở cả hai đầu.
 *  - enqueueFront(): thêm vào đầu
 *  - enqueue(): thêm vào cuối
 *  - dequeue(): xóa ở đầu
 *  - dequeueBack(): xóa ở cuối
 */
template <class T>
class ArrayDeque : public IQueue<T> {
private:
    ArrayList<T> list;

public:
    // ===== Constructor / Destructor =====
    ArrayDeque();
    ArrayDeque(const ArrayDeque<T>& other);
    ~ArrayDeque();
    ArrayDeque<T>& operator=(const ArrayDeque<T>& other);

    // ===== Core Queue Methods =====
    void enqueue(const T& element) override;
    T dequeue() override;
    T& front() override;
    T& back() override;
    bool empty() const override;
    int size() const override;
    void clear() override;

    // ===== Extended Deque Methods =====
    void enqueueFront(const T& element) override;
    T dequeueBack() override;

    // ===== Utility Methods =====
    bool contains(const T& item) const override;
    bool remove(const T& item) override;
    string toString() const override;

    class Iterator {
    private:
        const ArrayDeque<T>* deque;
        int index;
    public:
        Iterator(const ArrayDeque<T>* dq, int idx);
        Iterator& operator++();
        T& operator*();
        bool operator!=(const Iterator& other) const;
    };

Iterator begin() const;
Iterator end() const;

};


/*
 * Class: LinkedDeque<T>
 * ---------------------
 * Triển khai deque sử dụng DLinkedList.
 *  - Dễ dàng thao tác ở cả đầu và cuối nhờ con trỏ prev/next.
 */
template <class T>
class LinkedDeque : public IQueue<T> {
private:
    DLinkedList<T> list;

public:
    // ===== Constructor / Destructor =====
    LinkedDeque();
    LinkedDeque(const LinkedDeque<T>& other);
    ~LinkedDeque();
    LinkedDeque<T>& operator=(const LinkedDeque<T>& other);

    // ===== Core Queue Methods =====
    void enqueue(const T& element) override;
    T dequeue() override;
    T& front() override;
    T& back() override;
    bool empty() const override;
    int size() const override;
    void clear() override;

    // ===== Extended Deque Methods =====
    void enqueueFront(const T& element) override;
    T dequeueBack() override;

    // ===== Utility Methods =====
    bool contains(const T& item) const override;
    bool remove(const T& item) override;
    string toString() const override;

    class Iterator {
    private:
        typename DLinkedList<T>::Iterator it;
    public:
        Iterator(const typename DLinkedList<T>::Iterator& listIt);
        Iterator& operator++();
        const T& operator*() const;
        bool operator!=(const Iterator& other) const;
    };

Iterator begin() const;
Iterator end() const;

};

#endif /* DEQUE_H */
