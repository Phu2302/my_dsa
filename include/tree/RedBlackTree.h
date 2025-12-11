#ifndef REDBLACKTREE_H
#define REDBLACKTREE_H
#include "interfaces/IBinaryTree.h"
#include "lib.h"

/*
 * Class: RedBlackTree<T>
 * ----------------------
 * Cài đặt cấu trúc dữ liệu Cây Đỏ-Đen (Red-Black Tree)
 * Kế thừa từ IBinaryTree<T>.
 *
 * Đặc điểm:
 *  - Là cây nhị phân tìm kiếm (BST) tự cân bằng bằng quy tắc màu.
 *  - Mỗi node có màu: đỏ (RED) hoặc đen (BLACK).
 *  - Đảm bảo:
 *      1. Node gốc luôn đen.
 *      2. Node lá NULL (nil) được xem là đen.
 *      3. Không có 2 node đỏ kề nhau.
 *      4. Mọi đường đi từ gốc đến lá có cùng số lượng node đen.
 *  - Độ cao cây ≤ 2 * log2(n + 1)
 *  - Hiệu năng insert/remove/search: O(log N)
 *  - Yêu cầu: T hỗ trợ so sánh (operator<, operator==).
 */

template <class T>
class RedBlackTree : public IBinaryTree<T> {
private:
    // ===== Enum cho màu của node =====
    enum Color { RED, BLACK };

    // ===== Inner class Node =====
    class Node {
    public:
        T data;         // giá trị lưu trong node
        Color color;    // màu của node (RED / BLACK)
        Node* parent;   // cha
        Node* left;     // con trái
        Node* right;    // con phải

        Node(const T& value, Color c = RED)
            : data(value), color(c),
              parent(nullptr), left(nullptr), right(nullptr) {}
    };

private:
    Node* root;       // node gốc của cây
    int nodeCount;    // số lượng node hiện tại

private:
    // ===== Các hàm tiện ích nội bộ =====
    void clear(Node*& node);                          // xóa toàn bộ cây con
    Node* findMin(Node* node) const;                  // node có giá trị nhỏ nhất
    Node* findMax(Node* node) const;                  // node có giá trị lớn nhất
    bool contains(Node* node, const T& value) const;  // kiểm tra value tồn tại
    int height(Node* node) const;                     // tính chiều cao cây con
    int countLeaves(Node* node) const;                // đếm node lá
    int countInternalNodes(Node* node) const;         // đếm node trong

    // ===== Các hàm hỗ trợ cân bằng (Red-Black rules) =====
    void rotateLeft(Node*& node);                     // xoay trái
    void rotateRight(Node*& node);                    // xoay phải
    void fixInsert(Node*& node);                      // sửa vi phạm sau insert
    void fixRemove(Node*& node, Node* parent);        // sửa vi phạm sau remove
    void transplant(Node*& u, Node*& v);              // thay thế node trong remove

    // ===== Duyệt cây (Traversal) =====
    void inorder(Node* node, stringstream& ss) const;
    void preorder(Node* node, stringstream& ss) const;
    void postorder(Node* node, stringstream& ss) const;
    void levelorder(Node* node, stringstream& ss) const;

public:
    // ===== Constructor & Destructor =====
    RedBlackTree();                                   // constructor mặc định
    RedBlackTree(const RedBlackTree<T>& other);      // constructor sao chép
    ~RedBlackTree();                                  // destructor
    RedBlackTree<T>& operator=(const RedBlackTree<T>& other); // toán tử gán

    // ===== CRUD cơ bản (theo IBinaryTree<T>) =====
    void insert(const T& value) override;             // thêm node có giá trị value
    bool remove(const T& value) override;             // xóa node có giá trị value
    bool contains(const T& value) const override;     // kiểm tra tồn tại value
    void clear() override;                            // xóa toàn bộ cây

    // ===== Truy cập =====
    const T& rootNode() const override;                   // giá trị node gốc
    const T& findMin() const override;                // giá trị nhỏ nhất trong cây
    const T& findMax() const override;                // giá trị lớn nhất trong cây

    // ===== Thông tin & trạng thái =====
    bool empty() const override;                      // cây rỗng?
    int size() const override;                        // số node
    int height() const override;                      // chiều cao

    // ===== Duyệt cây =====
    string inorder() const override;                  // L - Root - R
    string preorder() const override;                 // Root - L - R
    string postorder() const override;                // L - R - Root
    string levelorder() const override;               // duyệt theo tầng

    // ===== Tiện ích mở rộng =====
    int countLeaves() const override;                 // số node lá
    int countInternalNodes() const override;          // số node trong

    // ===== Xuất chuỗi (debug) =====
    string toString() const override;                 // xuất cây dưới dạng chuỗi
};

#endif // REDBLACKTREE_H
