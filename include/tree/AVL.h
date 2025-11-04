#ifndef AVL_H
#define AVL_H
#include "interfaces/IBinaryTree.h"
#include "lib.h"

/*
 * Class: AVLTree<K, V>
 * --------------------
 * Cài đặt cấu trúc dữ liệu Cây AVL (Adelson-Velsky and Landis Tree)
 * Kế thừa từ IBinaryTree<K, V>.
 *
 * Đặc điểm:
 *  - Là cây nhị phân tìm kiếm (BST) có khả năng tự cân bằng.
 *  - Mỗi node lưu cặp (key, value) và giá trị cân bằng (balance factor).
 *  - balance = -1 → trái cao hơn, 0 → cân bằng, 1 → phải cao hơn.
 *  - Độ cao cây luôn O(log N).
 */

template <class K, class V>
class AVLTree : public IBinaryTree<K, V> {
private:
    // ===== Inner class Node =====
    class Node {
    public:
        K key;          // khóa so sánh
        V value;        // dữ liệu đi kèm
        Node* left;     // con trái
        Node* right;    // con phải
        int balance;    // -1: trái cao, 0: cân bằng, 1: phải cao

        Node(const K& k, const V& v, int b = 0)
            : key(k), value(v), left(nullptr), right(nullptr), balance(b) {}
    };

private:
    Node* root;       // nút gốc của cây
    int nodeCount;    // số lượng node trong cây

private:
    // ===== Các hàm tiện ích đệ quy (nội bộ) =====
    void clear(Node*& node);                              // xóa toàn bộ cây
    int height(Node* node) const;                         // tính chiều cao
    Node* findMin(Node* node) const;                      // tìm node có key nhỏ nhất
    Node* findMax(Node* node) const;                      // tìm node có key lớn nhất
    int countLeaves(Node* node) const;                    // đếm node lá
    int countInternalNodes(Node* node) const;             // đếm node trong

    // ===== Các hàm cân bằng (AVL-specific) =====
    Node* rotateLeft(Node*& node);
    Node* rotateRight(Node*& node);
    Node* balanceLeft(Node*& node, bool& taller);
    Node* balanceRight(Node*& node, bool& taller);
    Node* insertRec(Node*& node, const K& key, const V& value, bool& taller);
    Node* removeRec(Node*& node, const K& key, bool& shorter, bool& success);
    bool contains(Node* node, const K& key) const;
    const V& get(Node* node, const K& key) const;

    void inorder(Node* node, stringstream& ss) const;
    void preorder(Node* node, stringstream& ss) const;
    void postorder(Node* node, stringstream& ss) const;
    void levelorder(Node* node, stringstream& ss) const;

public:
    // ===== Constructor & Destructor =====
    AVLTree();
    AVLTree(const AVLTree<K, V>& other);
    ~AVLTree();
    AVLTree<K, V>& operator=(const AVLTree<K, V>& other);

    // ===== CRUD cơ bản (theo IBinaryTree) =====
    void insert(const K& key, const V& value) override;    // thêm node (key, value)
    bool remove(const K& key) override;                    // xóa node theo key
    bool contains(const K& key) const override;            // kiểm tra tồn tại key
    void clear() override;                                 // xóa toàn bộ cây

    // ===== Truy cập =====
    const V& get(const K& key) const override;             // lấy giá trị theo key (read-only)
    V& get(const K& key) override;                         // lấy giá trị theo key (modifiable)
    const K& rootKey() const override;                     // trả về key của node gốc
    const V& rootValue() const override;                   // trả về value của node gốc

    // ===== Thông tin & trạng thái =====
    bool empty() const override;
    int size() const override;
    int height() const override;

    // ===== Duyệt cây =====
    string inorder() const override;
    string preorder() const override;
    string postorder() const override;
    string levelorder() const override;

    // ===== Tiện ích mở rộng =====
    int countLeaves() const override;
    int countInternalNodes() const override;
    const K& findMinKey() const override;
    const K& findMaxKey() const override;

    // ===== Xuất chuỗi (debug) =====
    string toString() const override;
};

#endif // AVL_H
