#ifndef IBINARYTREE_H
#define IBINARYTREE_H
#include "lib.h"

/*
 * Interface: IBinaryTree<T>
 * -------------------------
 * Cây nhị phân tổng quát hoặc cây nhị phân tìm kiếm (BST/AVL/RBT) dùng 1 kiểu T.
 */

template <class T>
class IBinaryTree {
public:
    virtual ~IBinaryTree() {}

    // ===== CRUD =====
    virtual void insert(const T& value) {}                         // Thêm node có giá trị T
    virtual bool remove(const T& value) { return false; }          // Xóa node có giá trị T
    virtual bool contains(const T& value) const { return false; }  // Kiểm tra giá trị có tồn tại
    virtual void clear() = 0;                                      // Xóa toàn bộ cây

    // ===== Truy cập =====
    virtual const T& rootNode() const { static T tmp{}; return tmp; }  // Lấy giá trị ở node gốc

    // ===== Trạng thái =====
    virtual bool empty() const = 0;                                // Cây rỗng?
    virtual int size() const = 0;                                  // Số lượng node
    virtual int height() const = 0;                                // Chiều cao cây

    // ===== Traversal =====
    virtual string inorder() const { return ""; }                  // Left - Root - Right
    virtual string preorder() const { return ""; }                 // Root - Left - Right
    virtual string postorder() const { return ""; }                // Left - Right - Root
    virtual string levelorder() const { return ""; }               // Duyệt theo tầng (BFS)

    // ===== Thống kê =====
    virtual int countLeaves() const { return 0; }                  // Số node lá
    virtual int countInternalNodes() const { return 0; }           // Số node có con
    virtual T sumLeafNodes() const { return T{}; }                 // Tổng giá trị các node lá
    virtual const T& findMin() const { static T tmp{}; return tmp; } // Giá trị nhỏ nhất
    virtual const T& findMax() const { static T tmp{}; return tmp; } // Giá trị lớn nhất

    // ===== Debug =====
    virtual string toString() const { return ""; }                 // Xuất cây dạng chuỗi
};

#endif /* IBINARYTREE_H */
