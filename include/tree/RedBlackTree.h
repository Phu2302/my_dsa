#ifndef REDBLACKTREE_H
#define REDBLACKTREE_H
#include "interfaces/IBinaryTree.h"
#include "lib.h"

/*
 * Class: RedBlackTree<K, V>
 * --------------------------
 * Cài đặt cấu trúc dữ liệu Cây Đỏ-Đen (Red-Black Tree)
 * Kế thừa từ IBinaryTree<K, V>.
 *
 * Đặc điểm:
 *  - Là cây nhị phân tìm kiếm (BST) có khả năng tự cân bằng bằng quy tắc màu.
 *  - Mỗi node có màu: đỏ (RED) hoặc đen (BLACK).
 *  - Đảm bảo:
 *      1. Node gốc luôn đen.
 *      2. Node lá NULL (nil) được xem là đen.
 *      3. Không có 2 node đỏ kề nhau.
 *      4. Mọi đường đi từ gốc đến lá có cùng số lượng node đen.
 *  - Độ cao cây ≤ 2 * log2(n + 1)
 *  - Hiệu năng insert/remove/search: O(log N)
 */

template <class K, class V>
class RedBlackTree : public IBinaryTree<K, V> {
private:
    // ===== Enum cho màu của node =====
    enum Color { RED, BLACK };

    // ===== Inner class Node =====
    class Node {
    public:
        K key;           // khóa so sánh
        V value;         // dữ liệu đi kèm
        Color color;     // màu của node (RED / BLACK)
        Node* parent;    // cha
        Node* left;      // con trái
        Node* right;     // con phải

        Node(const K& k, const V& v, Color c = RED)
            : key(k), value(v), color(c),
              parent(nullptr), left(nullptr), right(nullptr) {}
    };

private:
    Node* root;       // node gốc của cây
    int nodeCount;    // số lượng node hiện tại

private:
    // ===== Các hàm tiện ích nội bộ =====
    void clear(Node*& node);                              // xóa toàn bộ cây
    Node* findMin(Node* node) const;                      // node nhỏ nhất
    Node* findMax(Node* node) const;                      // node lớn nhất
    bool contains(Node* node, const K& key) const;        // kiểm tra key tồn tại
    const V& get(Node* node, const K& key) const;         // lấy value theo key
    V& get(Node* node, const K& key);                     // bản modifiable
    int height(Node* node) const;                         // tính chiều cao
    int countLeaves(Node* node) const;                    // đếm node lá
    int countInternalNodes(Node* node) const;             // đếm node trong

    // ===== Các hàm hỗ trợ cân bằng (Red-Black rules) =====
    void rotateLeft(Node*& node);
    void rotateRight(Node*& node);
    void fixInsert(Node*& node);                          // sửa vi phạm sau insert
    void fixRemove(Node*& node, Node* parent);             // sửa vi phạm sau xóa
    void transplant(Node*& u, Node*& v);                  // thay thế node trong remove

    // ===== Duyệt cây (Traversal) =====
    void inorder(Node* node, stringstream& ss) const;
    void preorder(Node* node, stringstream& ss) const;
    void postorder(Node* node, stringstream& ss) const;
    void levelorder(Node* node, stringstream& ss) const;

public:
    // ===== Constructor & Destructor =====
    RedBlackTree();
    RedBlackTree(const RedBlackTree<K, V>& other);
    ~RedBlackTree();
    RedBlackTree<K, V>& operator=(const RedBlackTree<K, V>& other);

    // ===== CRUD cơ bản (theo IBinaryTree) =====
    void insert(const K& key, const V& value) override;   // thêm node (key, value)
    bool remove(const K& key) override;                   // xóa node theo key
    bool contains(const K& key) const override;           // kiểm tra tồn tại key
    void clear() override;                                // xóa toàn bộ cây

    // ===== Truy cập =====
    const V& get(const K& key) const override;            // lấy giá trị theo key (read-only)
    V& get(const K& key) override;                        // lấy giá trị theo key (modifiable)
    const K& rootKey() const override;                    // key của node gốc
    const V& rootValue() const override;                  // value của node gốc

    // ===== Thông tin & trạng thái =====
    bool empty() const override;                          // cây rỗng?
    int size() const override;                            // số node
    int height() const override;                          // chiều cao

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

#endif // REDBLACKTREE_H
