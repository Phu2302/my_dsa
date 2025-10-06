# 🧠 My DSA Library

A personal C++ library implementing **Data Structures and Algorithms** from scratch.  
This project is part of my learning journey to master data structures and algorithm design.

---

## 📂 Project Structure

<details>
<summary>Click to expand the full directory tree 📁</summary>

```text
my_dsa/
│
├── include/
│   ├── lib.h
│   ├── interfaces/          # Interface/ADT
│   │   ├── IList.h
│   │   ├── IStack.h
│   │   ├── IQueue.h
│   │   ├── IMap.h
│   │   ├── ISet.h
│   │   ├── IGraph.h
│   │   ├── IHeap.h
│   │   └── IBST.h
│   ├── array/
│   │   └── ArrayList.h
│   ├── linked_list/
│   │   ├── SLinkedList.h
│   │   └── DLinkedList.h
│   ├── queue/
│   │   ├── Queue.h
│   │   └── Deque.h
│   ├── stack/
│   │   └── Stack.h
│   ├── hash/
│   │   ├── HashNode.h
│   │   ├── Pair.h
│   │   ├── Chaining.h
│   │   └── OpenAddressing.h
│   ├── heap/
│   │   ├── MaxHeap.h
│   │   └── MinHeap.h
│   ├── tree/
│   │   ├── BST.h
│   │   └── AVL.h
│   └── graph/
│       ├── AdjListGraph.h
│       └── AdjMatrixGraph.h
│
├── src/
│   ├── array/ArrayList.cpp
│   ├── linked_list/SLinkedList.tpp
│   ├── linked_list/DLinkedList.tpp
│   ├── queue/Queue.tpp
│   ├── queue/Deque.tpp
│   ├── stack/Stack.tpp
│   ├── hash/Chaining.tpp
│   ├── hash/OpenAddressing.tpp
│   ├── tree/BST.tpp
│   ├── tree/AVL.tpp
│   ├── tree/Heap.tpp
│   └── graph/AdjListGraph.cpp
│
├── algorithms/
│   ├── Sorting.h
│   ├── Sorting.cpp
│   ├── Searching.h
│   ├── Searching.cpp
│   └── GraphAlgos.cpp
│
├── tests/
│   ├── test_array.cpp
│   ├── test_linked_list.cpp
│   ├── test_queue.cpp
│   ├── test_stack.cpp
│   ├── test_hash.cpp
│   ├── test_tree.cpp
│   ├── test_graph.cpp
│   └── test_sorting.cpp
│
├── CMakeLists.txt
└── README.md
