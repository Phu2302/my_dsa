#include "tree/BST.h"
#include "lib.h"

// ============================================================================
//  HÀM 1: Chứa tất cả test case cho BinarySearchTree<int>
// ============================================================================

void test_bst_int_cases() {
    cout << "==== Running BinarySearchTree<int> tests ====" << endl;

    // ---------- Test 1: Cây rỗng ----------
    {
        cout << "[BST Test 1] Empty tree" << endl;

        BinarySearchTree<int> bst;

        // Trạng thái cơ bản
        assert(bst.empty() == true);
        assert(bst.size() == 0);
        assert(bst.height() == 0);

        // Thống kê
        assert(bst.countLeaves() == 0);
        assert(bst.countInternalNodes() == 0);

        // Duyệt
        assert(bst.inorder() == "");
        assert(bst.preorder() == "");
        assert(bst.postorder() == "");
        assert(bst.levelorder() == "");

        // toString
        assert(bst.toString() == "");

        // contains
        assert(bst.contains(10) == false);
        
        // Test Exception cho rootNode khi rỗng
        try {
            bst.rootNode();
            // Nếu dòng này chạy nghĩa là không ném lỗi -> Sai
            assert(false && "Should throw exception when accessing root of empty tree");
        } catch (...) {
            // Bắt được lỗi -> Đúng
        }

        cout << "  -> OK" << endl;
    }

    // ---------- Test 2: Insert & Basic Traversals ----------
    //         5
    //       /   \
    //      3     7
    //     / \   / \
    //    2  4  6  8
    {
        cout << "[BST Test 2] Insert & basic traversals" << endl;

        BinarySearchTree<int> bst;
        bst.insert(5);
        bst.insert(3);
        bst.insert(7);
        bst.insert(2);
        bst.insert(4);
        bst.insert(6);
        bst.insert(8);

        assert(bst.empty() == false);
        assert(bst.size() == 7);
        assert(bst.rootNode() == 5); // Check root
        assert(bst.height() > 0);

        // Traversals
        assert(bst.inorder()   == "2 3 4 5 6 7 8 ");
        assert(bst.preorder()  == "5 3 2 4 7 6 8 ");
        assert(bst.postorder() == "2 4 3 6 8 7 5 ");
        
        // Level order (Giờ Queue đã fix xong nên ta bật test này lên)
        assert(bst.levelorder() == "5 3 7 2 4 6 8 ");

        // Min / Max
        assert(bst.findMin() == 2);
        assert(bst.findMax() == 8);

        // contains
        assert(bst.contains(5) == true);
        assert(bst.contains(2) == true);
        assert(bst.contains(100) == false);

        // Thống kê
        assert(bst.countLeaves() == 4);        
        assert(bst.countInternalNodes() == 3); 

        assert(bst.toString() == bst.inorder());

        cout << "  -> OK" << endl;
    }

    // ---------- Test 3: Remove leaf node ----------
    {
        cout << "[BST Test 3] Remove leaf node" << endl;

        BinarySearchTree<int> bst;
        bst.insert(5); bst.insert(3); bst.insert(7); bst.insert(2); bst.insert(4);

        assert(bst.size() == 5);
        bool removed = bst.remove(2);
        
        assert(removed == true);
        assert(bst.size() == 4);
        assert(bst.contains(2) == false);
        assert(bst.inorder() == "3 4 5 7 ");

        cout << "  -> OK" << endl;
    }

    // ---------- Test 4: Remove node with one child ----------
    {
        cout << "[BST Test 4] Remove node with one child" << endl;

        BinarySearchTree<int> bst;
        bst.insert(5); bst.insert(3); bst.insert(2);

        bool removed = bst.remove(3);
        assert(removed == true);
        assert(bst.size() == 2);
        assert(bst.contains(3) == false);

        // 2 có thể là con trái của 5
        assert(bst.inorder() == "2 5 ");

        cout << "  -> OK" << endl;
    }

    // ---------- Test 5: Remove node with two children (Root) ----------
    {
        cout << "[BST Test 5] Remove node with two children (root)" << endl;

        BinarySearchTree<int> bst;
        bst.insert(5); bst.insert(3); bst.insert(7);
        bst.insert(2); bst.insert(4); bst.insert(8);

        bool removed = bst.remove(5);
        assert(removed == true);
        assert(bst.size() == 5);
        assert(bst.contains(5) == false);

        // Node thế mạng (thường là 7 hoặc 6 tùy logic findMin/findMax) lên thay
        // Nhưng inorder vẫn phải bảo toàn thứ tự tăng dần
        assert(bst.inorder() == "2 3 4 7 8 ");
        
        // Kiểm tra xem root có được cập nhật không (thường sẽ là 6 hoặc 7 tùy cách cài đặt)
        // assert(bst.rootNode() != 5); 

        cout << "  -> OK" << endl;
    }

    // ---------- Test 6: Remove non-existing value ----------
    {
        cout << "[BST Test 6] Remove non-existing value" << endl;
        BinarySearchTree<int> bst;
        bst.insert(10); bst.insert(5);

        bool removed = bst.remove(100);
        assert(removed == false);
        assert(bst.size() == 2);
        cout << "  -> OK" << endl;
    }

    // ---------- Test 7: clear() ----------
    {
        cout << "[BST Test 7] clear()" << endl;
        BinarySearchTree<int> bst;
        bst.insert(1); bst.insert(2);

        bst.clear();
        assert(bst.empty() == true);
        assert(bst.size() == 0);
        cout << "  -> OK" << endl;
    }

    // ---------- Test 8: Copy & Assignment ----------
    {
        cout << "[BST Test 8] Copy constructor & assignment" << endl;
        BinarySearchTree<int> bst1;
        bst1.insert(5); bst1.insert(3);

        // Copy
        BinarySearchTree<int> bst2 = bst1;
        assert(bst2.size() == 2);
        
        bst1.insert(1);
        assert(bst1.size() == 3);
        assert(bst2.size() == 2); // Deep copy check

        // Assignment
        BinarySearchTree<int> bst3;
        bst3 = bst1;
        assert(bst3.size() == 3);
        
        cout << "  -> OK" << endl;
    }

    // ---------- Test 9: Edge Cases (Root Update & Duplicates) ----------
    {
        cout << "[BST Test 9] Edge Cases (Root & Duplicates)" << endl;
        BinarySearchTree<int> bst;
        
        bst.insert(10);
        bst.insert(5);
        
        bst.remove(10);
        assert(bst.rootNode() == 5);
        assert(bst.size() == 1);

        // Insert trùng 
        bst.insert(5); 
        assert(bst.size() == 2); 
        assert(bst.inorder() == "5 5 "); 
        cout << "  -> OK" << endl;
    }

    cout << "==== All BinarySearchTree<int> tests passed ====" << endl;
}

// Hàm public gọi từ main()
void test_bst() {
    test_bst_int_cases();
}