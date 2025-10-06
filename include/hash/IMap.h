#ifndef IMAP_H
#define IMAP_H
#include <string>
using namespace std;

template <typename K, typename V>
class IMap {
public:
    virtual ~IMap() {}

    // ===== Các hàm thao tác cơ bản =====
    virtual void put(const K& key, const V& value) = 0;
    virtual V& get(const K& key) = 0;
    virtual bool remove(const K& key) = 0;
    virtual bool containsKey(const K& key) const = 0;
    virtual bool containsValue(const V& value) const = 0;

    // ===== Thông tin bảng =====
    virtual bool empty() const = 0;
    virtual int size() const = 0;
    virtual void clear() = 0;
    virtual string toString() const = 0;
};
#endif
