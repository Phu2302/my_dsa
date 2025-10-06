#ifndef OPENADDRESSING_H
#define OPENADDRESSING_H
#include <iostream>
#include <string>
#include "hash/IMap.h"
#include "hash/Pair.h"
using namespace std;

template <typename K, typename V>
class OpenAddressing : public IMap<K,V> {
private:
    Pair<K,V>* table;    // mảng lưu trực tiếp key-value
    bool* occupied;      // đánh dấu slot đã dùng
    int capacity;        // kích thước bảng
    int count;           // số phần tử hiện có

    int hashFunction(const K& key) const;
    int probe(int index, int step) const;  // linear/quadratic/double hashing

public:
    // ===== Constructor & Destructor =====
    OpenAddressing(int cap = 101);
    ~OpenAddressing();

    // ===== Các hàm thao tác cơ bản =====
    void put(const K& key, const V& value) override;
    V& get(const K& key) override;
    bool remove(const K& key) override;
    bool containsKey(const K& key) const override;
    bool containsValue(const V& value) const override;

    // ===== Thông tin bảng =====
    bool empty() const override;
    int size() const override;
    void clear() override;
    string toString() const override;
};

#include "hash/OpenAddressing.tpp"
#endif
