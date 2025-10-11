#ifndef CHAINING_H
#define CHAINING_H
#include <iostream>
#include <string>
#include "hash/IMap.h"
#include "hash/HashNode.h"
using namespace std;

template <typename K, typename V>
class Chaining : public IMap<K,V> {
private:
    HashNode<K,V>** table;   // mảng con trỏ bucket
    int capacity;            // kích thước bảng
    int count;               // số phần tử hiện có

    int hashFunction(const K& key) const;

public:
    // ===== Constructor & Destructor =====
    Chaining(int cap = 101);
    ~Chaining();

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

#include "hash/Chaining.tpp"
#endif
