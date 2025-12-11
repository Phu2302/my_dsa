#ifndef QUEUE_H
#define QUEUE_H

#include "interfaces/IQueue.h"
#include "array/ArrayList.h"
#include "linked_list/SLinkedList.h"


/*
 * Class: ArrayQueue<T>
 * --------------------
 * Triển khai hàng đợi (Queue) sử dụng ArrayList làm cấu trúc lưu trữ nội bộ.
 *  - Nguyên tắc FIFO (First In, First Out)
 *  - enqueue(): thêm phần tử vào cuối
 *  - dequeue(): xóa phần tử đầu
 *  - front(): xem phần tử đầu mà không xóa
 *  - back(): xem phần tử cuối mà không xóa
 */
template <class T>
class ArrayQueue : public IQueue<T> {
private:
    ArrayList<T> list;

public:
    // ===== Constructor / Destructor =====
    ArrayQueue();
    ArrayQueue(const ArrayQueue<T>& other);
    ~ArrayQueue();
    ArrayQueue<T>& operator=(const ArrayQueue<T>& other);

    // ===== Core Methods =====
    void enqueue(const T& element) override;
    T dequeue() override;
    T& front() override;
    T& back() override;
    bool empty() const override;
    int size() const override;
    void clear() override;

    // ===== Utility Methods =====
    bool contains(const T& item) const override;
    bool remove(const T& item) override;
    string toString() const override;

    // ===== Iterator (traverse front -> back) =====
    class Iterator {
    private:
        const ArrayQueue<T>* queue;
        int index;
    public:
        Iterator(const ArrayQueue<T>* queue, int index);
        Iterator& operator++();
        //T& operator*();
        const T& operator*() const;
        bool operator!=(const Iterator& other) const;
    };

    Iterator begin() const;
    Iterator end() const;
};


/*
 * Class: LinkedQueue<T>
 * ---------------------
 * Triển khai hàng đợi (Queue) sử dụng SLinkedList làm cấu trúc lưu trữ nội bộ.
 *  - Nguyên tắc FIFO (First In, First Out)
 *  - enqueue(): thêm phần tử vào cuối
 *  - dequeue(): xóa phần tử đầu
 */
template <class T>
class LinkedQueue : public IQueue<T> {
private:
    SLinkedList<T> list;

public:
    // ===== Constructor / Destructor =====
    LinkedQueue();
    LinkedQueue(const LinkedQueue<T>& other);
    ~LinkedQueue();
    LinkedQueue<T>& operator=(const LinkedQueue<T>& other);

    // ===== Core Methods =====
    void enqueue(const T& element) override;
    T dequeue() override;
    T& front() override;
    T& back() override;
    bool empty() const override;
    int size() const override;
    void clear() override;

    // ===== Utility Methods =====
    bool contains(const T& item) const override;
    bool remove(const T& item) override;
    string toString() const override;

    // ===== Iterator =====
    class Iterator {
    private:
        typename SLinkedList<T>::Iterator it;
    public:
        Iterator(const typename SLinkedList<T>::Iterator& listIt);
        Iterator& operator++();
        const T& operator*() const;
        bool operator!=(const Iterator& other) const;
    };

    Iterator begin() const;
    Iterator end() const;
};

#include "data_structures/queue/QueueArray.cpp"

#endif /* QUEUE_H */
