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
│   ├── lib.h                # Library and using namespace std;
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
│   ├── main.cpp               # Test runner
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
├── LICENSE
└── README.md
```
</details>

---

## 🧱 Build & Run Instructions  

### 🪟 Windows (MinGW / VSCode Terminal)

⚙️ **Initial configuration** (run once to set up CMake):

```bash
cmake -S . -B build_win -G "MinGW Makefiles"
```

🔨 **Rebuild after code changes** (every time you modify or add tests):

```bash
cmake --build build_win
```

🚀 **Run the program:**

```bash
build_win/main.exe
```

---
### 🍎 macOS / Linux

⚙️ **Initial configuration:**

```bash
cmake -S . -B build_mac
```

🔨 **Rebuild after code changes:**

```bash
cmake --build build_mac
```

🚀 **Run the program:**

```bash
./build_mac/main
```