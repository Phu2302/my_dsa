#ifndef BINARYTREE_H
#define BINARYTREE_H
#include "interfaces/IBinaryTree.h"
#include "lib.h"

/*
 * Class: BinaryTree<T>
 * --------------------
 * Lớp cơ sở cho mọi cấu trúc cây nhị phân.
 * Kế thừa từ IBinaryTree<T>.
 *
 * Đặc điểm:
 *  - Mỗi node có tối đa 2 con: left, right.
 *  - Không áp đặt quy tắc sắp xếp (không phải BST).
 *  - Cung cấp các thao tác chung: duyệt cây, đếm node, tính chiều cao, ...
 *  - Được kế thừa bởi: BST<T>, AVL<T>, RedBlackTree<T>, ...
 */

template <class T>
class BinaryTree : public IBinaryTree<T> {
protected:
    // ===== Inner class Node =====
    class Node {
    public:
        T data;           // Giá trị lưu trong node
        Node* left;       // Con trái
        Node* right;      // Con phải

        Node(const T& value)
            : data(value), left(nullptr), right(nullptr) {}
    };

public:
    Node* root;           // Node gốc
    int nodeCount;        // Số lượng node hiện tại

protected:
    // ===== Các hàm tiện ích đệ quy dùng chung =====
    void clear(Node*& node);                           // Xóa cây con gốc tại node
    int height(Node* node) const;                      // Chiều cao của cây con
    int countLeaves(Node* node) const;                 // Đếm node lá trong cây con
    int countInternalNodes(Node* node) const;          // Đếm node trong trong cây con

    void inorder(Node* node, stringstream& ss) const;  // Duyệt L - Root - R từ node
    void preorder(Node* node, stringstream& ss) const; // Duyệt Root - L - R từ node
    void postorder(Node* node, stringstream& ss) const;// Duyệt L - R - Root từ node
    void levelorder(Node* node, stringstream& ss) const;// Duyệt theo tầng từ node

public:
    // ===== Constructor & Destructor =====
    BinaryTree();                                      // Constructor mặc định
    BinaryTree(const BinaryTree<T>& other);            // Constructor sao chép
    virtual ~BinaryTree();                             // Destructor
    BinaryTree<T>& operator=(const BinaryTree<T>& other); // Toán tử gán

    // ===== Các hàm dùng chung (override IBinaryTree<T>) =====
    void clear() override;                             // Xóa toàn bộ cây
    bool empty() const override;                       // Cây rỗng?
    int size() const override;                         // Số node
    int height() const override;                       // Chiều cao cây
    const T& rootNode() const override;                    // Giá trị node gốc

    // ===== Duyệt cây =====
    string inorder() const override;                   // Duyệt L - Root - R
    string preorder() const override;                  // Duyệt Root - L - R
    string postorder() const override;                 // Duyệt L - R - Root
    string levelorder() const override;                // Duyệt theo tầng (BFS)

    // ===== Tiện ích mở rộng =====
    int countLeaves() const override;                  // Số node lá
    int countInternalNodes() const override;           // Số node trong

    // ===== Debug / Xuất chuỗi =====
    string toString() const override;                  // Xuất cây dưới dạng chuỗi

    // Helper
    Node* copySubtree(Node* node);
};

#endif // BINARYTREE_H
