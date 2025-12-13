#ifndef HEAP_H
#define HEAP_H

#include "interfaces/IHeap.h"
#include "lib.h"

template<class T>
class Heap : public IHeap<T> {
protected:
    T* arr;
    int capacity;
    int count;

protected:
    // ===== Internal utilities =====
    void ensureCapacity(int minCapacity);
    void reheapUp(int index);
    void reheapDown(int index);

    // Comparison rule (Min / Max)
    virtual bool compare(const T& a, const T& b) const = 0;

public:
    // ===== Constructor / Destructor =====
    Heap();
    virtual ~Heap();

    // ===== Core operations =====
    void push(const T& value) override;
    void pop() override;
    const T& top() const override;

    // ===== Extended operations =====
    bool remove(const T& value) override;
    bool contains(const T& value) const override;
    const T& getItem(int index) const override;

    // ===== State =====
    bool empty() const override;
    int size() const override;

    // ===== Utility =====
    void clear() override;
    string levelorder() const override;
    string toString() const override;
};

// ======================= MaxHeap =======================

template<class T>
class MaxHeap : public Heap<T> {
public:
    MaxHeap();
    ~MaxHeap();

protected:
    bool compare(const T& a, const T& b) const override;
};

// ======================= MinHeap =======================

template<class T>
class MinHeap : public Heap<T> {
public:
    MinHeap();
    ~MinHeap();

protected:
    bool compare(const T& a, const T& b) const override;
};

#endif // HEAP_H
