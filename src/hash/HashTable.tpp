#include "hash/HashTable.h"
#include <sstream>

// ===== Constructor =====
template <typename K, typename V>
HashTable<K,V>::HashTable(int initCapacity) {
    // TODO: khởi tạo table (mảng bucket), capacity, count
}

// ===== Destructor =====
template <typename K, typename V>
HashTable<K,V>::~HashTable() {
    // TODO: giải phóng toàn bộ node trong các bucket và thu hồi mảng table
}

// ===== Hàm băm & Rehash =====

// Hàm băm
template <typename K, typename V>
int HashTable<K,V>::hashFunc(const K& key) const {
    // TODO: chuyển key -> chỉ số bucket [0..capacity-1]
    return 0;
}

// Tăng kích thước & phân phối lại
template <typename K, typename V>
void HashTable<K,V>::rehash() {
    // TODO: tăng capacity (vd: *2), tạo bảng mới, dời node sang bucket mới
}

// ===== Các hàm thao tác cơ bản =====

// Thêm mới hoặc cập nhật
template <typename K, typename V>
V HashTable<K,V>::put(const K& key, const V& value) {
    // TODO: nếu tồn tại key -> cập nhật và trả về value cũ; nếu chưa -> chèn và trả về value mới/hoặc value cũ mặc định
    return V();
}

// Lấy value theo key (throw nếu không có)
template <typename K, typename V>
V& HashTable<K,V>::get(const K& key) {
    // TODO: tìm node theo key; nếu không thấy -> throw std::out_of_range
    static V tmp{}; // placeholder
    return tmp;
}

// Tìm, trả về con trỏ tới value (nullptr nếu không có)
template <typename K, typename V>
V* HashTable<K,V>::search(const K& key) {
    // TODO: duyệt bucket tương ứng và trả về &node->value nếu tìm thấy
    return nullptr;
}

// Xoá theo key, trả về value cũ
template <typename K, typename V>
V HashTable<K,V>::remove(const K& key) {
    // TODO: tìm và xoá node có key; cập nhật count; trả về value cũ
    return V();
}

// Xoá theo key & value, trả về true nếu xoá
template <typename K, typename V>
bool HashTable<K,V>::remove(const K& key, const V& value) {
    // TODO: chỉ xoá khi cả key và value khớp
    return false;
}

// Kiểm tra có key
template <typename K, typename V>
bool HashTable<K,V>::containsKey(const K& key) const {
    // TODO
    return false;
}

// Kiểm tra có value
template <typename K, typename V>
bool HashTable<K,V>::containsValue(const V& value) const {
    // TODO: duyệt toàn bảng để tìm value
    return false;
}

// ===== Các hàm tiện ích =====

template <typename K, typename V>
bool HashTable<K,V>::empty() const {
    // TODO
    return true;
}

template <typename K, typename V>
int HashTable<K,V>::size() const {
    // TODO
    return 0;
}

template <typename K, typename V>
int HashTable<K,V>::bucketCount() const {
    // TODO
    return 0;
}

template <typename K, typename V>
double HashTable<K,V>::loadFactor() const {
    // TODO: trả về (double)count / capacity
    return 0.0;
}

template <typename K, typename V>
void HashTable<K,V>::clear() {
    // TODO: giải phóng toàn bộ node và reset count
}

// ===== ToString =====
template <typename K, typename V>
string HashTable<K,V>::toString(
    string (*key2str)(const K&),
    string (*value2str)(const V&)
) const {
    // TODO: duyệt toàn bộ bucket, ghép chuỗi theo định dạng mong muốn
    return "";
}

// ===== Iterator =====

// Constructor
template <typename K, typename V>
HashTable<K,V>::Iterator::Iterator(HashTable<K,V>* table, int index, HashNode<K,V>* node) {
    // TODO: khởi tạo iterator với pTable, bucketIndex, current
}

// Toán tử gán
template <typename K, typename V>
typename HashTable<K,V>::Iterator& 
HashTable<K,V>::Iterator::operator=(const Iterator& other) {
    // TODO
    return *this;
}

// So sánh khác nhau
template <typename K, typename V>
bool HashTable<K,V>::Iterator::operator!=(const Iterator& other) const {
    // TODO
    return true;
}

// Tiến (++it)
template <typename K, typename V>
typename HashTable<K,V>::Iterator& 
HashTable<K,V>::Iterator::operator++() {
    // TODO: di chuyển current sang phần tử kế tiếp (qua next hoặc nhảy bucket)
    return *this;
}

// Tiến (it++)
template <typename K, typename V>
typename HashTable<K,V>::Iterator 
HashTable<K,V>::Iterator::operator++(int) {
    // TODO: lưu lại bản sao, ++this, trả về bản sao
    Iterator tmp = *this;
    return tmp;
}

// Dereference
template <typename K, typename V>
Pair<K,V> HashTable<K,V>::Iterator::operator*() {
    // TODO: trả về cặp (key,value) của current
    return Pair<K,V>(K(), V());
}

// ===== Begin & End =====
template <typename K, typename V>
typename HashTable<K,V>::Iterator HashTable<K,V>::begin() {
    // TODO: tìm bucket đầu tiên có phần tử và trả về iterator tại đó
    return Iterator(this, 0, nullptr);
}

template <typename K, typename V>
typename HashTable<K,V>::Iterator HashTable<K,V>::end() {
    // TODO: trả về iterator đánh dấu hết bảng (null)
    return Iterator(this, capacity, nullptr);
}
