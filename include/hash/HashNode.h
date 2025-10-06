#ifndef HASHNODE_H
#define HASHNODE_H

// ================= HashNode ================= //
// Node cho phương pháp separate chaining
template <typename K, typename V>
class HashNode {
public:
    K key;
    V value;
    HashNode* next;

    HashNode(const K& k, const V& v, HashNode* nxt = nullptr)
        : key(k), value(v), next(nxt) {}
};

#include "hash/HashTable.tpp"
#endif
