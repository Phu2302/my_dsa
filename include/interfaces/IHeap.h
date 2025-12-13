#ifndef IHEAP_H
#define IHEAP_H

#include "lib.h"

template<class T>
class IHeap {
public:
    virtual ~IHeap() {}

    // ===== Core heap operations =====
    virtual void push(const T& value) = 0;
    virtual void pop() = 0;
    virtual const T& top() const = 0;

    // ===== Extended operations =====
    virtual bool remove(const T& value) = 0; 
    virtual bool contains(const T& value) const = 0; 
    virtual const T& getItem(int index) const = 0;

    // ===== State =====
    virtual bool empty() const = 0;
    virtual int size() const = 0;

    // ===== Utility =====
    virtual void clear() = 0;
    virtual string levelorder() const = 0;
    virtual string toString() const = 0;
};

#endif // IHEAP_H
