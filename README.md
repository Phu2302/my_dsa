# 🧠 My DSA Library

A personal C++ library implementing **Data Structures and Algorithms** from scratch.  
This project is part of my learning journey to master data structures and algorithm design.

---

## ⚙️ Features
- **Modular implementation** of classic data structures (List, Stack, Queue, Hash, Tree, Graph, etc.)
- Includes **sorting**, **searching**, and **graph algorithms**.
- Supports **template classes** for reusability and flexibility.
- Organized structure for **easy testing and extension**.

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
│   ├── linked_list/SLinkedList.cpp
│   ├── linked_list/DLinkedList.cpp
│   ├── queue/Queue.cpp
│   ├── queue/Deque.cpp
│   ├── stack/Stack.cpp
│   ├── hash/Chaining.cpp
│   ├── hash/OpenAddressing.cpp
│   ├── tree/BST.cpp
│   ├── tree/AVL.cpp
│   ├── tree/Heap.cpp
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
│   ├── main.cpp               # Test runner (menu selection)
│   ├── test_array.cpp
│   ├── linked_list/
│   │   └── test_slinkedlist.cpp
│   ├── test_queue.cpp
│   ├── test_stack.cpp
│   ├── test_hash.cpp
│   ├── test_tree.cpp
│   ├── test_graph.cpp
│   └── test_sorting.cpp
│
├── CMakeLists.txt
└── README.md
</details>
```

## 🧱 Build & Run Instructions  

### 🪟 Windows (MinGW / VSCode Terminal)

⚙️ **Initial configuration** (run once to set up CMake):

cmake -S . -B build_win -G "MinGW Makefiles"

🔨 **Rebuild after code changes** (every time you modify or add tests):

cmake --build build_win

🚀 **Run the program:**

build_win\main.exe

---

### 🍎 macOS / Linux

⚙️ **Initial configuration:**

cmake -S . -B build_mac

🔨 **Rebuild after code changes:**

cmake --build build_mac

🚀 **Run the program:**

./build_mac/main
