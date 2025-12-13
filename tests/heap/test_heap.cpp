#include "heap/Heap.h"
#include "lib.h"

// ============================================================================
// Helper: validate heap property via getItem()
// ============================================================================

static void assert_maxheap_property(MaxHeap<int>& h) {
    int n = h.size();
    for (int i = 1; i < n; i++) {
        int parent = (i - 1) / 2;
        assert(h.getItem(parent) >= h.getItem(i));
    }
}

static void assert_minheap_property(MinHeap<int>& h) {
    int n = h.size();
    for (int i = 1; i < n; i++) {
        int parent = (i - 1) / 2;
        assert(h.getItem(parent) <= h.getItem(i));
    }
}

// ============================================================================
// All test cases for Heap<int> (MaxHeap + MinHeap)
// ============================================================================

void test_heap_int_cases() {
    cout << "==== Running Heap<int> tests (MaxHeap + MinHeap) ====" << endl;

    // ========================================================================
    // MAX HEAP
    // ========================================================================

    // [1] Empty heap
    {
        MaxHeap<int> h;

        assert(h.empty() == true);
        assert(h.size() == 0);
        assert(h.levelorder() == "");

        assert(h.contains(10) == false);
        assert(h.remove(10) == false);

        h.pop();
        h.clear();

        assert(h.empty() == true);
        assert(h.size() == 0);

        try {
            h.top();
            assert(false);
        } catch (...) {}

        try {
            h.getItem(0);
            assert(false);
        } catch (...) {}
    }

    // [2] push + top + property
    {
        MaxHeap<int> h;
        h.push(5);
        h.push(3);
        h.push(7);
        h.push(2);
        h.push(4);
        h.push(6);
        h.push(8);

        assert(h.empty() == false);
        assert(h.size() == 7);

        assert(h.top() == 8);
        assert(h.getItem(0) == h.top());

        assert_maxheap_property(h);

        assert(h.contains(5) == true);
        assert(h.contains(2) == true);
        assert(h.contains(100) == false);

        assert(h.levelorder() != "");
    }

    // [3] pop
    {
        MaxHeap<int> h;
        h.push(5); h.push(3); h.push(7); h.push(2); h.push(4); h.push(6); h.push(8);

        assert(h.top() == 8);
        h.pop();

        assert(h.size() == 6);
        assert(h.top() == 7);

        assert_maxheap_property(h);
    }

    // [4] remove (existing / non-existing)
    {
        MaxHeap<int> h;
        h.push(5); h.push(3); h.push(7); h.push(2); h.push(4); h.push(6); h.push(8);

        bool removed = h.remove(4);
        assert(removed == true);
        assert(h.size() == 6);
        assert(h.contains(4) == false);

        assert_maxheap_property(h);

        removed = h.remove(999);
        assert(removed == false);
        assert(h.size() == 6);
    }

    // [5] duplicates
    {
        MaxHeap<int> h;
        h.push(10);
        h.push(10);
        h.push(5);

        assert(h.size() == 3);
        assert(h.top() == 10);

        bool removed = h.remove(10);
        assert(removed == true);
        assert(h.size() == 2);
        assert(h.contains(10) == true);

        assert_maxheap_property(h);
    }

    // [6] push many (capacity growth)
    {
        MaxHeap<int> h;
        for (int i = 1; i <= 25; i++) h.push(i);

        assert(h.size() == 25);
        assert(h.top() == 25);

        assert_maxheap_property(h);
    }

    // [7] getItem bounds
    {
        MaxHeap<int> h;
        h.push(3); h.push(1); h.push(2);

        assert(h.getItem(0) == h.top());

        try {
            h.getItem(-1);
            assert(false);
        } catch (...) {}

        try {
            h.getItem(h.size());
            assert(false);
        } catch (...) {}
    }

    // [8] clear
    {
        MaxHeap<int> h;
        h.push(1); h.push(2); h.push(3);

        h.clear();

        assert(h.empty() == true);
        assert(h.size() == 0);
        assert(h.levelorder() == "");
    }

    // ========================================================================
    // MIN HEAP
    // ========================================================================

    // [1] Empty heap
    {
        MinHeap<int> h;

        assert(h.empty() == true);
        assert(h.size() == 0);
        assert(h.levelorder() == "");

        assert(h.contains(10) == false);
        assert(h.remove(10) == false);

        h.pop();
        h.clear();

        try {
            h.top();
            assert(false);
        } catch (...) {}

        try {
            h.getItem(0);
            assert(false);
        } catch (...) {}
    }

    // [2] push + top + property
    {
        MinHeap<int> h;
        h.push(5);
        h.push(3);
        h.push(7);
        h.push(2);
        h.push(4);
        h.push(6);
        h.push(8);

        assert(h.empty() == false);
        assert(h.size() == 7);

        assert(h.top() == 2);
        assert(h.getItem(0) == h.top());

        assert_minheap_property(h);

        assert(h.contains(5) == true);
        assert(h.contains(2) == true);
        assert(h.contains(100) == false);

        assert(h.levelorder() != "");
    }

    // [3] pop
    {
        MinHeap<int> h;
        h.push(5); h.push(3); h.push(7); h.push(2); h.push(4); h.push(6); h.push(8);

        assert(h.top() == 2);
        h.pop();

        assert(h.size() == 6);
        assert(h.top() == 3);

        assert_minheap_property(h);
    }

    // [4] remove (existing / non-existing)
    {
        MinHeap<int> h;
        h.push(5); h.push(3); h.push(7); h.push(2); h.push(4); h.push(6); h.push(8);

        bool removed = h.remove(4);
        assert(removed == true);
        assert(h.size() == 6);
        assert(h.contains(4) == false);

        assert_minheap_property(h);

        removed = h.remove(999);
        assert(removed == false);
        assert(h.size() == 6);
    }

    // [5] duplicates
    {
        MinHeap<int> h;
        h.push(10);
        h.push(10);
        h.push(5);

        assert(h.size() == 3);
        assert(h.top() == 5);

        bool removed = h.remove(10);
        assert(removed == true);
        assert(h.size() == 2);
        assert(h.contains(10) == true);

        assert_minheap_property(h);
    }

    // [6] push many (capacity growth)
    {
        MinHeap<int> h;
        for (int i = 25; i >= 1; i--) h.push(i);

        assert(h.size() == 25);
        assert(h.top() == 1);

        assert_minheap_property(h);
    }

    // [7] getItem bounds
    {
        MinHeap<int> h;
        h.push(3); h.push(1); h.push(2);

        assert(h.getItem(0) == h.top());

        try {
            h.getItem(-1);
            assert(false);
        } catch (...) {}

        try {
            h.getItem(h.size());
            assert(false);
        } catch (...) {}
    }

    // [8] clear
    {
        MinHeap<int> h;
        h.push(1); h.push(2); h.push(3);

        h.clear();

        assert(h.empty() == true);
        assert(h.size() == 0);
        assert(h.levelorder() == "");
    }

    cout << "==== All Heap<int> tests passed (MaxHeap + MinHeap) ====" << endl;
}

// Public entry for main()
void test_heap() {
    test_heap_int_cases();
}
