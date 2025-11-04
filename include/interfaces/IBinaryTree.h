#ifndef IBINARYTREE_H
#define IBINARYTREE_H
#include "lib.h"

/*
 * Interface: IBinaryTree<K, V>
 * -----------------------------
 * Mô tả trừu tượng cho cấu trúc dữ liệu Cây Nhị Phân tổng quát (Binary Tree).
 * Các lớp kế thừa: BinarySearchTree<K, V>, AVLTree<K, V>, RedBlackTree<K, V>, ...
 *
 * Yêu cầu:
 *  - K hỗ trợ toán tử so sánh (==, <, >) nếu là cây tìm kiếm.
 *  - Node có tối đa 2 con (left, right).
 */

template <class K, class V>
class IBinaryTree {
public:
    virtual ~IBinaryTree() {}

    // ===== CRUD cơ bản =====
    virtual void insert(const K& key, const V& value) = 0;   // Thêm phần tử (key, value)
    virtual bool remove(const K& key) = 0;                   // Xóa phần tử theo key
    virtual bool contains(const K& key) const = 0;           // Kiểm tra key có tồn tại không
    virtual void clear() = 0;                                // Xóa toàn bộ cây

    // ===== Truy cập =====
    virtual const V& get(const K& key) const = 0;            // Lấy giá trị theo key
    virtual V& get(const K& key) = 0;                        // (phiên bản cho phép ghi)
    virtual const K& rootKey() const = 0;                    // Trả về key của node gốc
    virtual const V& rootValue() const = 0;                  // Trả về giá trị của node gốc

    // ===== Thông tin & trạng thái =====
    virtual bool empty() const = 0;                          // Cây rỗng?
    virtual int size() const = 0;                            // Số node
    virtual int height() const = 0;                          // Chiều cao cây

    // ===== Duyệt cây (Traversal) =====
    virtual string inorder() const = 0;                      // Duyệt trung thứ tự (L - R)
    virtual string preorder() const = 0;                     // Duyệt tiền thứ tự (R - L)
    virtual string postorder() const = 0;                    // Duyệt hậu thứ tự (L - R)
    virtual string levelorder() const = 0;                   // Duyệt theo tầng (Breadth-first)

    // ===== Thống kê & tiện ích =====
    virtual int countLeaves() const = 0;                     // Đếm node lá
    virtual int countInternalNodes() const = 0;              // Đếm node trong
    virtual const K& findMinKey() const = 0;                 // Key nhỏ nhất
    virtual const K& findMaxKey() const = 0;                 // Key lớn nhất

    // ===== Xuất chuỗi (debug) =====
    virtual string toString() const = 0;                     // Xuất cây dưới dạng chuỗi
};

#endif /* IBINARYTREE_H */
