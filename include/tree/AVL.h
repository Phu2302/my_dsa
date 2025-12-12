#ifndef AVL_H
#define AVL_H
#include "interfaces/IBinaryTree.h"
#include "lib.h"

/*
 * Class: AVLTree<T>
 * -----------------
 * Cây AVL tự cân bằng dựa vào chiều cao.
 */

template <class T>
class AVLTree : public IBinaryTree<T> {
private:
    enum BalanceValue { LH = -1, EH = 0, RH = 1 };

    class Node {
    public:
        T data;              // giá trị
        Node* left;          // con trái
        Node* right;         // con phải
        BalanceValue balance;// hệ số cân bằng
        Node(const T& v, BalanceValue b = EH)
            : data(v), left(nullptr), right(nullptr), balance(b) {}
    };

private:
    Node* root;         // node gốc
    int nodeCount;      // số node

private:
    // ===== Utilities =====
    void clear(Node*& node);                 // xóa cây con
    int height(Node* node) const;            // chiều cao cây con
    int getBalance(Node* node) const;        // hệ số cân bằng
    Node* findMin(Node* node) const;         // node nhỏ nhất
    Node* findMax(Node* node) const;         // node lớn nhất
    bool contains(Node* node, const T& value) const; // kiểm tra tồn tại
    int countLeaves(Node* node) const;       // đếm node lá
    int countInternalNodes(Node* node) const;// đếm node trong

    // ===== Rotations =====
    Node* rotateLeft(Node* node);            // xoay trái
    Node* rotateRight(Node* node);           // xoay 

    // ===== Rebalance =====
    Node* rebalanceLL(Node* node);   // Left-Left case
    Node* rebalanceLR(Node* node);   // Left-Right case
    Node* rebalanceRR(Node* node);   // Right-Right case
    Node* rebalanceRL(Node* node);   // Right-Left case
    Node* rebalanceInsert(Node* node, const T& value); // cân bằng sau insert
    Node* rebalanceAfterDelete(Node* node);            // cân bằng sau delete

    // ===== Core Recursive Operations =====
    Node* insertAVL(Node* node, const T& value);       // insert AVL
    Node* removeAVL(Node* node, const T& value, bool& removed);       // remove AVL

    // ===== Traversals =====
    void inorder(Node* node, stringstream& ss) const;
    void preorder(Node* node, stringstream& ss) const;
    void postorder(Node* node, stringstream& ss) const;
    void levelorder(Node* node, stringstream& ss) const;

public:
    // ===== Constructor / Destructor =====
    AVLTree();
    AVLTree(const AVLTree<T>& other);
    ~AVLTree();
    AVLTree<T>& operator=(const AVLTree<T>& other);

    // ===== CRUD =====
    void insert(const T& value) override;    // thêm giá trị
    bool remove(const T& value) override;    // xóa giá trị
    bool contains(const T& value) const override; // kiểm tra tồn tại
    void clear() override;                   // xóa toàn bộ cây

    // ===== Truy cập =====
    const T& rootNode() const override;      // giá trị node gốc
    const T& findMin() const override;       // giá trị nhỏ nhất
    const T& findMax() const override;       // giá trị lớn nhất

    // ===== Thông tin =====
    bool empty() const override;             // cây rỗng?
    int size() const override;               // số node
    int height() const override;             // chiều cao
    // ===== Duyệt cây =====
    string inorder() const override;         // L - Root - R
    string preorder() const override;        // Root - L - R
    string postorder() const override;       // L - R - Root
    string levelorder() const override;      // BFS

    // ===== Thống kê =====
    int countLeaves() const override;        // số node lá
    int countInternalNodes() const override; // số node trong

    // ===== Debug =====
    string toString() const override;        // xuất chuỗi
    Node* copySubtree(Node* node);
};

#endif // AVL_H
