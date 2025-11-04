#ifndef BINARYTREE_H
#define BINARYTREE_H
#include "interfaces/IBinaryTree.h"
#include "lib.h"

/*
 * Class: BinaryTree<K, V>
 * -----------------------
 * Lớp cơ sở trừu tượng cho mọi cấu trúc cây nhị phân.
 * Kế thừa từ IBinaryTree<K, V>.
 *
 * Đặc điểm:
 *  - Mỗi node có tối đa 2 con: left, right.
 *  - Không áp đặt quy tắc sắp xếp (không phải BST).
 *  - Cung cấp các thao tác chung: duyệt cây, đếm node, tính chiều cao, ...
 *  - Được kế thừa bởi: BinarySearchTree<K,V>, AVLTree<K,V>, RedBlackTree<K,V>, ...
 */

template <class K, class V>
class BinaryTree : public IBinaryTree<K, V> {
protected:
    // ===== Inner class Node =====
    class Node {
    public:
        K key;        // khóa
        V value;      // dữ liệu
        Node* left;   // con trái
        Node* right;  // con phải

        Node(const K& k, const V& v)
            : key(k), value(v), left(nullptr), right(nullptr) {}
    };

protected:
    Node* root;       // node gốc
    int nodeCount;    // số lượng node hiện tại

protected:
    // ===== Các hàm tiện ích đệ quy dùng chung =====
    void clear(Node*& node);                       // xóa toàn bộ cây
    int height(Node* node) const;                  // tính chiều cao
    int countLeaves(Node* node) const;             // đếm số node lá
    int countInternalNodes(Node* node) const;      // đếm node trong

    void inorder(Node* node, stringstream& ss) const;
    void preorder(Node* node, stringstream& ss) const;
    void postorder(Node* node, stringstream& ss) const;
    void levelorder(Node* node, stringstream& ss) const;

public:
    // ===== Constructor & Destructor =====
    BinaryTree();
    BinaryTree(const BinaryTree<K, V>& other);
    virtual ~BinaryTree();
    BinaryTree<K, V>& operator=(const BinaryTree<K, V>& other);

    // ===== CRUD cơ bản (phải override ở lớp con) =====
    virtual void insert(const K& key, const V& value) = 0;
    virtual bool remove(const K& key) = 0;
    virtual bool contains(const K& key) const = 0;
    virtual const V& get(const K& key) const = 0;
    virtual V& get(const K& key) = 0;

    // ===== Các hàm dùng chung =====
    void clear() override;             // xóa toàn bộ cây
    bool empty() const override;       // cây rỗng?
    int size() const override;         // số node
    int height() const override;       // chiều cao

    // ===== Duyệt cây =====
    string inorder() const override;
    string preorder() const override;
    string postorder() const override;
    string levelorder() const override;

    // ===== Tiện ích mở rộng =====
    int countLeaves() const override;
    int countInternalNodes() const override;

    // ===== Debug / Xuất chuỗi =====
    string toString() const override;
};

#endif // BINARYTREE_H
