#ifndef BST_H
#define BST_H
#include "interfaces/IBinaryTree.h"
#include "lib.h"

/*
 * Class: BinarySearchTree<K, V>
 * ------------------------------
 * Cài đặt cấu trúc dữ liệu Cây Nhị Phân Tìm Kiếm (Binary Search Tree).
 * Kế thừa từ IBinaryTree<K, V>.
 *
 * Đặc điểm:
 *  - Là cây nhị phân mà với mỗi node: 
 *      + Key của cây con trái < key của node hiện tại
 *      + Key của cây con phải > key của node hiện tại
 *  - Không tự cân bằng như AVL, Red-Black.
 *  - Phù hợp cho dữ liệu nhỏ hoặc ít thay đổi.
 */

template <class K, class V>
class BinarySearchTree : public IBinaryTree<K, V> {
private:
    // ===== Inner class Node =====
    class Node {
    public:
        K key;         // khóa so sánh
        V value;       // dữ liệu đi kèm
        Node* left;    // con trái
        Node* right;   // con phải

        Node(const K& k, const V& v)
            : key(k), value(v), left(nullptr), right(nullptr) {}
    };

private:
    Node* root;       // node gốc của cây
    int nodeCount;    // số lượng node trong cây

private:
    // ===== Các hàm tiện ích đệ quy (nội bộ) =====
    void clear(Node*& node);                              // xóa toàn bộ cây
    Node* insertRec(Node*& node, const K& key, const V& value); // chèn node mới
    Node* removeRec(Node*& node, const K& key, bool& removed);  // xóa node theo key
    Node* findMin(Node* node) const;                      // node có key nhỏ nhất
    Node* findMax(Node* node) const;                      // node có key lớn nhất
    bool contains(Node* node, const K& key) const;        // kiểm tra key tồn tại
    const V& get(Node* node, const K& key) const;         // lấy value theo key (read-only)
    V& get(Node* node, const K& key);                     // lấy value theo key (modifiable)
    int height(Node* node) const;                         // chiều cao cây
    int countLeaves(Node* node) const;                    // đếm node lá
    int countInternalNodes(Node* node) const;             // đếm node trong

    // ===== Duyệt cây (Traversal) =====
    void inorder(Node* node, stringstream& ss) const;
    void preorder(Node* node, stringstream& ss) const;
    void postorder(Node* node, stringstream& ss) const;
    void levelorder(Node* node, stringstream& ss) const;

public:
    // ===== Constructor & Destructor =====
    BinarySearchTree();
    BinarySearchTree(const BinarySearchTree<K, V>& other);
    ~BinarySearchTree();
    BinarySearchTree<K, V>& operator=(const BinarySearchTree<K, V>& other);

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
    int height() const override;                          // chiều cao cây

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

#endif // BST_H
