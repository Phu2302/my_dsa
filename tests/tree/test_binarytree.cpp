#include "tree/BinaryTree.h"
#include <iostream>
#include <cassert>
#include <string>

using namespace std;

// ============================================================================
//  Lớp test kế thừa BinaryTree<int> để truy cập Node, root, nodeCount
// ============================================================================

class TestBinaryTreeInt : public BinaryTree<int> {
public:
    // Tạo một node mới với giá trị cho trước
    BinaryTree<int>::Node* newNode(int value) {
        return new BinaryTree<int>::Node(value);
    }

    // Gán root và nodeCount (chỉ dùng trong test)
    void setRoot(BinaryTree<int>::Node* r, int count) {
        this->root = r;
        this->nodeCount = count;
    }
};

// ============================================================================
//  HÀM 1: Chứa toàn bộ test case cho BinaryTree<int>
// ============================================================================

void test_binarytree_int_cases() {
    cout << "==== Running BinaryTree<int> tests ====" << endl;

    // ---------- Test 1: Cây rỗng ----------
    {
        cout << "[Test 1] Empty tree" << endl;
        TestBinaryTreeInt t;

        // Trạng thái
        assert(t.empty() == true);
        assert(t.size() == 0);
        assert(t.height() == 0);
        assert(t.countLeaves() == 0);
        assert(t.countInternalNodes() == 0);

        // Duyệt cây
        assert(t.inorder() == "");
        assert(t.preorder() == "");
        assert(t.postorder() == "");
        assert(t.levelorder() == "");   // hàm levelorder hiện chưa implement → trả ""

        // toString
        assert(t.toString() == "");

        cout << "  -> OK" << endl;
    }

    // ---------- Test 2: Cây nhỏ 3 node đối xứng ----------
    //        2
    //       / \
    //      1   3
    {
        cout << "[Test 2] Small balanced tree (3 nodes)" << endl;

        TestBinaryTreeInt t;

        auto n1 = t.newNode(1);
        auto n2 = t.newNode(2);
        auto n3 = t.newNode(3);

        n2->left  = n1;
        n2->right = n3;

        t.setRoot(n2, 3);

        // Trạng thái
        assert(t.empty() == false);
        assert(t.size() == 3);
        assert(t.height() == 2);          // 2 tầng
        assert(t.countLeaves() == 2);     // node 1, 3
        assert(t.countInternalNodes() == 1); // node 2

        // Duyệt cây
        assert(t.inorder()   == "1 2 3 ");
        assert(t.preorder()  == "2 1 3 ");
        assert(t.postorder() == "1 3 2 ");

        // levelorder() hiện bạn chưa code → tạm thời không assert non-empty,
        // sau này implement BFS thì có thể expect "2 1 3 "

        // toString hiện return inorder()
        assert(t.toString() == t.inorder());

        cout << "  -> OK" << endl;
    }

    // ---------- Test 3: Cây lệch phải để test height / leaves / internal ----------
    //      1
    //       \
    //        2
    //         \
    //          3
    {
        cout << "[Test 3] Right-skewed tree" << endl;

        TestBinaryTreeInt t;

        auto n1 = t.newNode(1);
        auto n2 = t.newNode(2);
        auto n3 = t.newNode(3);

        n1->right = n2;
        n2->right = n3;

        t.setRoot(n1, 3);

        assert(t.empty() == false);
        assert(t.size() == 3);
        assert(t.height() == 3);          // 3 tầng
        assert(t.countLeaves() == 1);     // chỉ có node 3
        assert(t.countInternalNodes() == 2); // node 1, 2

        assert(t.inorder()   == "1 2 3 ");
        assert(t.preorder()  == "1 2 3 ");
        assert(t.postorder() == "3 2 1 ");

        cout << "  -> OK" << endl;
    }

    // ---------- Test 4: Copy constructor (deep copy) ----------
    {
        cout << "[Test 4] Copy constructor (deep copy)" << endl;

        TestBinaryTreeInt t1;

        auto n1 = t1.newNode(1);
        auto n2 = t1.newNode(2);
        auto n3 = t1.newNode(3);

        n2->left  = n1;
        n2->right = n3;
        t1.setRoot(n2, 3);

        // Gọi copy constructor của lớp con (sẽ gọi copy ctor của BinaryTree<int> bên trong)
        TestBinaryTreeInt t2 = t1;

        // Cùng trạng thái, cùng duyệt cây
        assert(t2.empty() == false);
        assert(t2.size() == 3);
        assert(t2.height() == 2);
        assert(t2.inorder() == "1 2 3 ");

        // Xoá t1, t2 vẫn giữ dữ liệu → chứng minh deep copy
        t1.clear();
        assert(t1.size() == 0);
        assert(t1.inorder() == "");
        assert(t1.empty() == true);

        assert(t2.size() == 3);
        assert(t2.inorder() == "1 2 3 ");
        assert(t2.empty() == false);

        cout << "  -> OK" << endl;
    }

    // ---------- Test 5: Copy assignment operator (deep copy) ----------
    {
        cout << "[Test 5] Copy assignment operator (deep copy)" << endl;

        TestBinaryTreeInt t1;
        TestBinaryTreeInt t2;

        auto n1 = t1.newNode(10);
        auto n2 = t1.newNode(5);
        auto n3 = t1.newNode(20);

        n1->left  = n2;
        n1->right = n3;
        t1.setRoot(n1, 3);

        t2 = t1;    // gọi operator= của BinaryTree<int> qua lớp con

        assert(t2.empty() == false);
        assert(t2.size() == 3);
        assert(t2.height() == 2);
        assert(t2.inorder() == "5 10 20 ");

        t1.clear();
        assert(t1.size() == 0);
        assert(t1.inorder() == "");
        assert(t1.empty() == true);

        assert(t2.size() == 3);
        assert(t2.inorder() == "5 10 20 ");
        assert(t2.empty() == false);

        cout << "  -> OK" << endl;
    }

    // ---------- Test 6: clear() trên cây không rỗng ----------
    {
        cout << "[Test 6] clear() on non-empty tree" << endl;

        TestBinaryTreeInt t;

        auto n1 = t.newNode(1);
        auto n2 = t.newNode(2);
        auto n3 = t.newNode(3);
        auto n4 = t.newNode(4);

        //       2
        //      / \
        //     1   3
        //          \
        //           4
        n2->left  = n1;
        n2->right = n3;
        n3->right = n4;

        t.setRoot(n2, 4);

        assert(t.empty() == false);
        assert(t.size() == 4);
        assert(t.height() == 3);
        assert(t.countLeaves() == 2);         // 1, 4
        assert(t.countInternalNodes() == 2);  // 2, 3

        t.clear();

        assert(t.size() == 0);
        assert(t.height() == 0);
        assert(t.inorder() == "");
        assert(t.empty() == true);

        cout << "  -> OK" << endl;
    }

    cout << "==== All BinaryTree<int> tests passed ====" << endl;
}

// ============================================================================
//  HÀM 2: Hàm public gọi trong main (sau này thêm double/float thì gọi thêm)
// ============================================================================

void test_binarytree() {
    // Hiện tại chỉ test cho int
    test_binarytree_int_cases();
}
