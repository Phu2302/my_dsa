#ifndef BST_H
#define BST_H
#include "interfaces/IBinaryTree.h"
#include "queue/Queue.h"
#include "lib.h"

/*
 * Class: BinarySearchTree<T>
 * --------------------------
 * Cài đặt cấu trúc dữ liệu Cây Nhị Phân Tìm Kiếm (Binary Search Tree).
 * Kế thừa từ IBinaryTree<T>.
 *
 * Đặc điểm:
 *  - Với mỗi node:
 *      + Giá trị cây con trái  < giá trị node hiện tại
 *      + Giá trị cây con phải > giá trị node hiện tại
 *  - Không tự cân bằng (không phải AVL, Red-Black).
 *  - Phù hợp cho dữ liệu nhỏ hoặc ít thay đổi.
 *  - Yêu cầu: T hỗ trợ so sánh (operator<, operator==).
 */

template <class T>
class BinarySearchTree : public IBinaryTree<T> {
private:
    // ===== Inner class Node =====
    class Node {
    public:
        T data;       // Giá trị lưu trong node
        Node* left;   // Con trái
        Node* right;  // Con phải

        Node(const T& value)
            : data(value), left(nullptr), right(nullptr) {}
    };

private:
    Node* root;       // Node gốc của cây
    int nodeCount;    // Số lượng node trong cây

private:
    // ===== Các hàm tiện ích đệ quy (nội bộ) =====
    void clear(Node*& node);                        // Xóa toàn bộ cây con gốc tại node
    Node* insertRec(Node* node, const T& value);   // Chèn node mới (BST logic)
    Node* removeRec(Node* node, const T& value, bool& removed); // Xóa node có giá trị value
    Node* findMin(Node* node) const;                // Node có giá trị nhỏ nhất trong cây con
    Node* findMax(Node* node) const;                // Node có giá trị lớn nhất trong cây con
    bool contains(Node* node, const T& value) const;// Kiểm tra value tồn tại
    int height(Node* node) const;                   // Chiều cao cây con
    int countLeaves(Node* node) const;              // Đếm node lá
    int countInternalNodes(Node* node) const;       // Đếm node trong

    // ===== Duyệt cây (Traversal) =====
    void inorder(Node* node, stringstream& ss) const;
    void preorder(Node* node, stringstream& ss) const;
    void postorder(Node* node, stringstream& ss) const;
    void levelorder(Node* node, stringstream& ss) const;

public:
    // ===== Constructor & Destructor =====
    BinarySearchTree();                             // Constructor mặc định
    BinarySearchTree(const BinarySearchTree<T>& other); // Constructor sao chép
    ~BinarySearchTree();                            // Destructor
    BinarySearchTree<T>& operator=(const BinarySearchTree<T>& other); // Toán tử gán

    // ===== CRUD cơ bản (theo IBinaryTree<T>) =====
    void insert(const T& value) override;           // Thêm node có giá trị value
    bool remove(const T& value) override;           // Xóa node có giá trị value
    bool contains(const T& value) const override;   // Kiểm tra tồn tại value
    void clear() override;                          // Xóa toàn bộ cây

    // ===== Truy cập =====
    const T& rootNode() const override;                 // Giá trị node gốc
    const T& findMin() const override;              // Giá trị nhỏ nhất (BST)
    const T& findMax() const override;              // Giá trị lớn nhất (BST)

    // ===== Thông tin & trạng thái =====
    bool empty() const override;                    // Cây rỗng?
    int size() const override;                      // Số node trong cây
    int height() const override;                    // Chiều cao cây

    // ===== Duyệt cây =====
    string inorder() const override;                // Left - Root - Right
    string preorder() const override;               // Root - Left - Right
    string postorder() const override;              // Left - Right - Root
    string levelorder() const override;             // Duyệt theo tầng (BFS)

    // ===== Tiện ích mở rộng =====
    int countLeaves() const override;               // Số node lá
    int countInternalNodes() const override;        // Số node trong

    // ===== Xuất chuỗi (debug) =====
    string toString() const override;               // Xuất cây dưới dạng chuỗi

    // Helper
    Node* copySubtree(Node* node);
};

#endif // BST_H
