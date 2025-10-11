#include "stack/Stack.h"
#include "lib.h"

template<typename T>
void testArrayStackTemplate(const std::string& typeName) {
    ArrayStack<T> st;
    cout << "=== Test ArrayStack<" << typeName << "> ===\n\n";

    // ==== Test push() ====
    cout << "--- Test push(e) ---\n";
    st.push(10);
    st.push(20);
    st.push(30);
    cout << "After push(10,20,30): " << st.toString() << endl;
    st.push(40);
    st.push(50);
    cout << "After push(40,50): " << st.toString() << endl;

    // ==== Test top() ====
    cout << "\n--- Test top() ---\n";
    cout << "Current top: " << st.top() << endl;
    st.push(99);
    cout << "After push(99), top(): " << st.top() << endl;

    // ==== Test pop() ====
    cout << "\n--- Test pop() ---\n";
    cout << "Pop: " << st.pop() << endl;
    cout << "After pop(): " << st.toString() << endl;
    cout << "Pop again: " << st.pop() << endl;
    cout << "After pop(): " << st.toString() << endl;

    // ==== Test contains() ====
    cout << "\n--- Test contains(e) ---\n";
    cout << "Contains 30? " << (st.contains(30) ? "Yes" : "No") << endl;
    cout << "Contains 999? " << (st.contains(999) ? "Yes" : "No") << endl;

    // ==== Test remove(e) ====
    cout << "\n--- Test remove(e) ---\n";
    cout << "Before remove(30): " << st.toString() << endl;
    cout << "remove(30): " << (st.remove(30) ? "Yes" : "No") << endl;
    cout << "After remove(30): " << st.toString() << endl;
    cout << "remove(999): " << (st.remove(999) ? "Yes" : "No") << endl;
    cout << "After remove(999): " << st.toString() << endl;

    // ==== Test size() & empty() ====
    cout << "\n--- Test size() & empty() ---\n";
    cout << "Size: " << st.size() << endl;
    cout << "Empty? " << (st.empty() ? "Yes" : "No") << endl;

    // ==== Test clear() ====
    cout << "\n--- Test clear() ---\n";
    st.clear();
    cout << "After clear: " << st.toString() << endl;
    cout << "Size: " << st.size() << ", Empty? " << (st.empty() ? "Yes" : "No") << endl;

    // ==== Test pop() on empty stack ====
    cout << "\n--- Test pop() on empty stack ---\n";
    try {
        st.pop();
    } catch (std::out_of_range& e) {
        cout << "Caught exception: " << e.what() << endl;
    }

    // ==== Test copy constructor ====
    cout << "\n--- Test copy constructor ---\n";
    st.push(1);
    st.push(2);
    st.push(3);
    ArrayStack<T> st2(st);
    cout << "Original: " << st.toString() << endl;
    cout << "Copy: " << st2.toString() << endl;

    // ==== Test operator= ====
    cout << "\n--- Test operator= ---\n";
    ArrayStack<T> st3;
    st3 = st;
    cout << "Assigned st3 = st: " << st3.toString() << endl;

    // ==== Test Iterator ====
    cout << "\n=== Test Iterator ===\n";
    ArrayStack<T> st4;
    st4.push(10);
    st4.push(20);
    st4.push(30);
    cout << "Stack: " << st4.toString() << endl;
    cout << "Traverse (top -> bottom): ";
    for (auto it = st4.begin(); it != st4.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    // ==== Test iterator edge case ====
    auto it = st4.begin();
    cout << "Iterator begin(): " << *it << endl;
    ++it;
    cout << "Next element: " << *it << endl;

    // ==== Test multiple pops ====
    cout << "\n--- Test multiple pops ---\n";
    while (!st4.empty()) {
        cout << "Pop: " << st4.pop() << " -> " << st4.toString() << endl;
    }

    cout << "\n=== END TEST ===\n\n";
}

void test_arraystack() {
    testArrayStackTemplate<int>("int");
}
