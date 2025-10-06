#ifndef HASHTABLE_H
#define HASHTABLE_H

#include "HashNode.h"
#include "Pair.h"
#include <string>
#include <stdexcept>
using namespace std;

// ================= HashTable ================= //
template <typename K, typename V>
class HashTable {
private:
    HashNode<K,V>** table;  // mảng con trỏ tới danh sách (bucket)
    int capacity;           // số bucket
    int count;              // số phần tử hiện có

    int hashFunc(const K& key) const;   // hàm băm
    void rehash();                      // tăng kích thước khi load factor cao

public:
    // ===== Constructor & Destructor =====
    HashTable(int initCapacity = 10);
    ~HashTable();

    // ===== Các hàm thao tác kinh điển =====
    V put(const K& key, const V& value);       // thêm mới hoặc update
    V& get(const K& key);                      // lấy value theo key (throw nếu không có)
    V* search(const K& key);                   // tìm, trả về pointer hoặc nullptr
    V remove(const K& key);                    // xoá theo key, trả về value cũ
    bool remove(const K& key, const V& value); // xoá nếu đúng cả key & value
    bool containsKey(const K& key) const;
    bool containsValue(const V& value) const;

    // ===== Tiện ích =====
    bool empty() const;
    int size() const;
    int bucketCount() const;
    double loadFactor() const;
    void clear();
    string toString(
        string (*key2str)(const K&) = nullptr,
        string (*value2str)(const V&) = nullptr
    ) const;

    // ===== Iterator =====
    class Iterator {
    private:
        HashTable<K,V>* pTable;
        int bucketIndex;
        HashNode<K,V>* current;
    public:
        Iterator(HashTable<K,V>* table = nullptr, int index = 0, HashNode<K,V>* node = nullptr);

        Iterator& operator=(const Iterator& other);
        bool operator!=(const Iterator& other) const;
        Iterator& operator++();                 // ++it
        Iterator operator++(int);               // it++
        Pair<K,V> operator*();                  // trả về cặp (key,value)
    };

    Iterator begin();
    Iterator end();
};

#include "hash/HashTable.tpp"
#endif
