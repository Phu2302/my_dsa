#include "tree/AVL.h"
#include "lib.h"

// ============================================================================
//  HÀM 1: Chứa tất cả test case cho AVLTree<int>
// ============================================================================

void test_avl_int_cases() {
    cout << "==== Running AVLTree<int> tests ====" << endl;

    // ---------- Test 1: Cây rỗng ----------
    {
        cout << "[AVL Test 1] Empty tree" << endl;

        AVLTree<int> avl;

        // Trạng thái cơ bản
        assert(avl.empty() == true);
        assert(avl.size() == 0);
        assert(avl.height() == 0);

        // Thống kê
        assert(avl.countLeaves() == 0);
        assert(avl.countInternalNodes() == 0);

        // Duyệt
        assert(avl.inorder() == "");
        assert(avl.preorder() == "");
        assert(avl.postorder() == "");
        assert(avl.levelorder() == "");

        // toString
        assert(avl.toString() == "");

        // contains
        assert(avl.contains(10) == false);

        // Test Exception cho rootNode khi rỗng (nếu bạn cài ném lỗi)
        try {
            avl.rootNode();
            // Nếu tới đây mà không ném lỗi -> Sai
            assert(false && "Should throw exception when accessing root of empty AVL tree");
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
        cout << "[AVL Test 2] Insert & basic traversals" << endl;

        AVLTree<int> avl;
        avl.insert(5);
        avl.insert(3);
        avl.insert(7);
        avl.insert(2);
        avl.insert(4);
        avl.insert(6);
        avl.insert(8);

        assert(avl.empty() == false);
        assert(avl.size() == 7);
        assert(avl.rootNode() == 5);       // Với dãy này AVL vẫn cân bằng đẹp
        assert(avl.height() > 0);

        // Traversals
        assert(avl.inorder()   == "2 3 4 5 6 7 8 ");
        assert(avl.preorder()  == "5 3 2 4 7 6 8 ");
        assert(avl.postorder() == "2 4 3 6 8 7 5 ");
        assert(avl.levelorder() == "5 3 7 2 4 6 8 ");

        // Min / Max
        assert(avl.findMin() == 2);
        assert(avl.findMax() == 8);

        // contains
        assert(avl.contains(5) == true);
        assert(avl.contains(2) == true);
        assert(avl.contains(100) == false);

        // Thống kê
        assert(avl.countLeaves() == 4);          // 2,4,6,8
        assert(avl.countInternalNodes() == 3);   // 5,3,7

        // toString
        assert(avl.toString() == avl.inorder());

        cout << "  -> OK" << endl;
    }

    // ---------- Test 3: Rotations LL / RR / LR / RL ----------
    {
        cout << "[AVL Test 3] Rotations (LL, RR, LR, RL)" << endl;

        // LL: insert 30, 20, 10
        {
            AVLTree<int> avl;
            avl.insert(30);
            avl.insert(20);
            avl.insert(10);   // gây mất cân bằng LL

            assert(avl.inorder() == "10 20 30 ");
            assert(avl.rootNode() == 20);
            assert(avl.height() == 2);
            assert(avl.levelorder() == "20 10 30 ");
        }

        // RR: insert 10, 20, 30
        {
            AVLTree<int> avl;
            avl.insert(10);
            avl.insert(20);
            avl.insert(30);   // RR

            assert(avl.inorder() == "10 20 30 ");
            assert(avl.rootNode() == 20);
            assert(avl.height() == 2);
            assert(avl.levelorder() == "20 10 30 ");
        }

        // LR: insert 30, 10, 20
        {
            AVLTree<int> avl;
            avl.insert(30);
            avl.insert(10);
            avl.insert(20);   // LR

            assert(avl.inorder() == "10 20 30 ");
            assert(avl.rootNode() == 20);
            assert(avl.height() == 2);
            assert(avl.levelorder() == "20 10 30 ");
        }

        // RL: insert 10, 30, 20
        {
            AVLTree<int> avl;
            avl.insert(10);
            avl.insert(30);
            avl.insert(20);   // RL

            assert(avl.inorder() == "10 20 30 ");
            assert(avl.rootNode() == 20);
            assert(avl.height() == 2);
            assert(avl.levelorder() == "20 10 30 ");
        }

        cout << "  -> OK" << endl;
    }

    // ---------- Test 4: Remove leaf node ----------
    {
        cout << "[AVL Test 4] Remove leaf node" << endl;

        AVLTree<int> avl;
        avl.insert(5);
        avl.insert(3);
        avl.insert(7);
        avl.insert(2);   // leaf
        avl.insert(4);

        assert(avl.size() == 5);
        assert(avl.contains(2));

        bool removed = avl.remove(2);
        assert(removed == true);
        assert(avl.size() == 4);
        assert(!avl.contains(2));
        assert(avl.inorder() == "3 4 5 7 ");

        cout << "  -> OK" << endl;
    }

    // ---------- Test 5: Remove node with one child ----------
    {
        cout << "[AVL Test 5] Remove node with one child" << endl;

        AVLTree<int> avl;
        avl.insert(5);
        avl.insert(3);
        avl.insert(2);   // 2 là con trái của 3

        bool removed = avl.remove(3);
        assert(removed == true);
        assert(avl.size() == 2);
        assert(!avl.contains(3));
        assert(avl.contains(2));
        assert(avl.inorder() == "2 5 ");

        cout << "  -> OK" << endl;
    }

    // ---------- Test 6: Remove node with two children (root) ----------
    {
        cout << "[AVL Test 6] Remove node with two children (root)" << endl;

        AVLTree<int> avl;
        avl.insert(5);
        avl.insert(3);
        avl.insert(7);
        avl.insert(2);
        avl.insert(4);
        avl.insert(6);
        avl.insert(8);

        assert(avl.size() == 7);
        assert(avl.contains(5));

        bool removed = avl.remove(5);
        assert(removed == true);
        assert(avl.size() == 6);
        assert(!avl.contains(5));

        // Inorder vẫn phải sorted
        assert(avl.inorder() == "2 3 4 6 7 8 ");

        cout << "  -> OK" << endl;
    }

    // ---------- Test 7: Remove non-existing value ----------
    {
        cout << "[AVL Test 7] Remove non-existing value" << endl;

        AVLTree<int> avl;
        avl.insert(10);
        avl.insert(5);

        bool removed = avl.remove(100);
        assert(removed == false);
        assert(avl.size() == 2);
        assert(avl.contains(10));
        assert(avl.contains(5));

        cout << "  -> OK" << endl;
    }

    // ---------- Test 8: clear() ----------
    {
        cout << "[AVL Test 8] clear()" << endl;

        AVLTree<int> avl;
        avl.insert(1);
        avl.insert(2);
        avl.insert(3);

        assert(avl.empty() == false);
        assert(avl.size() == 3);

        avl.clear();
        assert(avl.empty() == true);
        assert(avl.size() == 0);
        assert(avl.height() == 0);
        assert(avl.inorder() == "");
        assert(avl.preorder() == "");
        assert(avl.postorder() == "");
        assert(avl.levelorder() == "");

        cout << "  -> OK" << endl;
    }

    // ---------- Test 9: Copy constructor & assignment ----------
    {
        cout << "[AVL Test 9] Copy constructor & assignment" << endl;

        AVLTree<int> avl1;
        avl1.insert(5);
        avl1.insert(3);
        avl1.insert(7);

        // Copy constructor
        AVLTree<int> avl2 = avl1;
        assert(avl2.size() == 3);
        assert(avl2.inorder() == avl1.inorder());

        // Thay đổi avl1 không ảnh hưởng avl2 (deep copy)
        avl1.insert(1);
        assert(avl1.size() == 4);
        assert(avl2.size() == 3);

        // Assignment operator
        AVLTree<int> avl3;
        avl3.insert(100);
        avl3 = avl1;
        assert(avl3.size() == avl1.size());
        assert(avl3.inorder() == avl1.inorder());

        cout << "  -> OK" << endl;
    }

    // ---------- Test 10: Thống kê leaves / internal nodes ----------
    {
        cout << "[AVL Test 10] countLeaves() & countInternalNodes()" << endl;

        AVLTree<int> avl;
        avl.insert(10);
        avl.insert(5);
        avl.insert(15);
        avl.insert(2);
        avl.insert(7);

        // Cây (một dạng có thể là):
        //        10
        //       /  \
        //      5    15
        //     / \
        //    2   7
        //
        // Lá: 2,7,15  => 3
        // Node trong: 10,5 => 2
        assert(avl.countLeaves() == 3);
        assert(avl.countInternalNodes() == 2);

        cout << "  -> OK" << endl;
    }

    cout << "==== All AVLTree<int> tests passed ====" << endl;
}

// ============================================================================
//  HÀM PUBLIC: Gọi từ main()
// ============================================================================

void test_avl() {
    test_avl_int_cases();
}
