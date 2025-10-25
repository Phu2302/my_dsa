#include "hash/OpenAddressing.h"
#include <sstream>

// ===== Constructor =====
template <typename K, typename V>
OpenAddressing<K,V>::OpenAddressing(int cap) {
    // TODO: cấp phát mảng Pair<K,V>, mảng occupied
    // gán capacity, set count = 0
}

// ===== Destructor =====
template <typename K, typename V>
OpenAddressing<K,V>::~OpenAddressing() {
    // TODO: giải phóng table và occupied
}

// ===== Hàm băm =====
template <typename K, typename V>
int OpenAddressing<K,V>::hashFunction(const K& key) const {
    // TODO: ví dụ std::hash<K>()(key) % capacity
    return 0;
}

// ===== Hàm probe (linear/quadratic/double hashing) =====
template <typename K, typename V>
int OpenAddressing<K,V>::probe(int index, int step) const {
    // TODO: ví dụ linear probing: (index + step) % capacity
    return 0;
}

// ===== Các hàm thao tác cơ bản =====

// Thêm hoặc cập nhật phần tử
template <typename K, typename V>
void OpenAddressing<K,V>::put(const K& key, const V& value) {
    // TODO
}

// Lấy giá trị theo key
template <typename K, typename V>
V& OpenAddressing<K,V>::get(const K& key) {
    // TODO
    static V dummy{};
    return dummy;
}

// Xoá phần tử theo key
template <typename K, typename V>
bool OpenAddressing<K,V>::remove(const K& key) {
    // TODO
    return false;
}

// Kiểm tra tồn tại key
template <typename K, typename V>
bool OpenAddressing<K,V>::containsKey(const K& key) const {
    // TODO
    return false;
}

// Kiểm tra tồn tại value
template <typename K, typename V>
bool OpenAddressing<K,V>::containsValue(const V& value) const {
    // TODO
    return false;
}

// ===== Thông tin bảng =====

// Kiểm tra rỗng
template <typename K, typename V>
bool OpenAddressing<K,V>::empty() const {
    // TODO
    return true;
}

// Trả về số phần tử
template <typename K, typename V>
int OpenAddressing<K,V>::size() const {
    // TODO
    return 0;
}

// Xoá toàn bộ bảng
template <typename K, typename V>
void OpenAddressing<K,V>::clear() {
    // TODO
}

// Biểu diễn bảng dưới dạng chuỗi
template <typename K, typename V>
string OpenAddressing<K,V>::toString() const {
    // TODO: duyệt table, nối key-value thành chuỗi
    return "";
}