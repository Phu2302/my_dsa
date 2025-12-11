#ifndef ARRAYLIST_H
#define ARRAYLIST_H

#include "interfaces/IList.h"

template<class T>
class ArrayList : public IList<T> {
private:
    T* arr;
    int capacity;
    int count;
    void ensureCapacity(int cap);

public:
    // ===== Constructor / Destructor =====
    ArrayList(int initCapacity = 10);
    ArrayList(const ArrayList& other);
    ~ArrayList();
    ArrayList& operator=(const ArrayList& other);

    // ===== Implement IList<T> =====
    void add(const T& e) override;
    void add(int index, const T& e) override;
    T removeAt(int index) override;
    bool removeItem(const T& item) override;
    bool empty() const override;
    int size() const override;
    void clear() override;
    T& get(int index) override;
    const T& get(int index) const;
    void set(int index, const T& e) override;
    int indexOf(const T& item) const override;
    bool contains(const T& item) const override;
    T& front() override;
    T& back() override;
    T pop_front() override;
    T pop_back() override;
    string toString() const override;

    // ===== Sorting algorithms =====
    void printList() const;
    void bubbleSort();
    void selectionSort();
    void insertionSort();
    void shellSort();
    void quickSort();
    void mergeSort();
    void heapSort();

    int partition(int low, int high);
    void quickSortHelper(int low, int high);
    void merge(int left, int mid, int right);
    void mergeSortHelper(int left, int right);
    void heapify(int n, int i);

    // ===== Iterator chuẩn =====
    class Iterator {
    private:
        int cursor;           // vị trí hiện tại
        ArrayList<T>* pList;  // danh sách mà iterator duyệt
    public:
        // Constructor
        Iterator(ArrayList<T>* list = nullptr, int index = 0);

        // Toán tử gán
        Iterator& operator=(const Iterator& other);

        // Truy cập giá trị hiện tại
        T& operator*();

        // So sánh iterator khác nhau
        bool operator!=(const Iterator& other) const;

        // Tiến (++it, it++)
        Iterator& operator++();    // tiền tố ++it
        Iterator operator++(int);  // hậu tố it++

        // Lùi (--it, it--)
        Iterator& operator--();    // tiền tố --it
        Iterator operator--(int);  // hậu tố it--
    };

    // Trả về iterator đầu/cuối
    Iterator begin();
    Iterator end();
    Iterator begin() const;
    Iterator end() const;
};

#include "data_structures/array/ArrayList.cpp"
#include "algorithms/sorting.cpp"

#endif // ARRAYLIST_H