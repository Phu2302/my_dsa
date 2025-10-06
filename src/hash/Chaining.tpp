#include "hash/Chaining.h"
#include <sstream>

// ===== Constructor =====
template <typename K, typename V>
Chaining<K,V>::Chaining(int cap) {
    // TODO: cấp phát mảng con trỏ HashNode*, gán capacity, set count = 0
}

// ===== Destructor =====
template <typename K, typename V>
Chaining<K,V>::~Chaining() {
    // TODO: giải phóng toàn bộ node trong từng bucket, rồi giải phóng table
}

// ===== Hàm băm =====
template <typename K, typename V>
int Chaining<K,V>::hashFunction(const K& key) const {
    // TODO: chuyển key thành chỉ số (vd: std::hash<K>()(key) % capacity)
    return 0;
}

// ===== Các hàm thao tác cơ bản =====

// Thêm hoặc cập nhật phần tử
template <typename K, typename V>
void Chaining<K,V>::put(const K& key, const V& value) {
    // TODO
}

// Lấy giá trị theo key
template <typename K, typename V>
V& Chaining<K,V>::get(const K& key) {
    // TODO
    static V dummy{};
    return dummy;
}

// Xoá phần tử theo key
template <typename K, typename V>
bool Chaining<K,V>::remove(const K& key) {
    // TODO
    return false;
}

// Kiểm tra tồn tại key
template <typename K, typename V>
bool Chaining<K,V>::containsKey(const K& key) const {
    // TODO
    return false;
}

// Kiểm tra tồn tại value
template <typename K, typename V>
bool Chaining<K,V>::containsValue(const V& value) const {
    // TODO
    return false;
}

// ===== Thông tin bảng =====

// Kiểm tra rỗng
template <typename K, typename V>
bool Chaining<K,V>::empty() const {
    // TODO
    return true;
}

// Trả về số phần tử
template <typename K, typename V>
int Chaining<K,V>::size() const {
    // TODO
    return 0;
}

// Xoá toàn bộ bảng
template <typename K, typename V>
void Chaining<K,V>::clear() {
    // TODO
}

// Biểu diễn bảng dưới dạng chuỗi
template <typename K, typename V>
string Chaining<K,V>::toString() const {
    // TODO: duyệt toàn bộ bucket, nối key-value thành chuỗi
    return "";
}