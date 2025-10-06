#ifndef PAIR_H
#define PAIR_H

// ================= Pair ================= //
template <typename K, typename V>
class Pair {
public:
    K key;
    V value;

    Pair(const K& k, const V& v) : key(k), value(v) {}
};

#include "hash/HashTable.tpp"
#endif
