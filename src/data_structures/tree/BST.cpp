#include "tree/BST.h"
#include "queue/Queue.h"
// ======================= CONSTRUCTOR / DESTRUCTOR =======================

// Default constructor
template<class T>
BinarySearchTree<T>::BinarySearchTree() {
    // Time complexity:
    root = nullptr;
    nodeCount = 0;
}

template<class T>
typename BinarySearchTree<T>::Node* BinarySearchTree<T>::copySubtree(Node* node) {
    if (node == nullptr) return nullptr;

    Node *newNode = new Node(node->data);
    newNode->left = copySubtree(node->left);     // FIXED
    newNode->right = copySubtree(node->right);
    return newNode;
}

// Copy constructor
template<class T>
BinarySearchTree<T>::BinarySearchTree(const BinarySearchTree<T>& other) {
    // Time complexity:
    root = copySubtree(other.root);
    nodeCount = other.nodeCount;
}

// Destructor
template<class T>
BinarySearchTree<T>::~BinarySearchTree() {
    // Time complexity:
    clear();
}

// Copy assignment operator
template<class T>
BinarySearchTree<T>& BinarySearchTree<T>::operator=(const BinarySearchTree<T>& other) {
    // Time complexity:
    if (this == &other) return *this;
    clear();
    root = copySubtree(other.root);
    nodeCount = other.nodeCount;
    return *this;
}


// ======================= CLEAR =======================

// Recursively clear all nodes in subtree
template<class T>
void BinarySearchTree<T>::clear(Node*& node) {
    // Time complexity:
    if (node == nullptr) return;

    clear(node->left);
    clear(node->right);
    delete node;
    node = nullptr;
}

// Clear the entire tree
template<class T>
void BinarySearchTree<T>::clear() {
    // Time complexity:
    clear(root);
    root = nullptr;
    nodeCount = 0;
}


// ======================= INSERT =======================

// Recursive insert helper
template<class T>
typename BinarySearchTree<T>::Node* 
BinarySearchTree<T>::insertRec(Node* node, const T& value) {
    // Time complexity:
    if (node == nullptr){
        node = new Node(value);
        nodeCount++;
        return node;
    }
    
    if (value < node->data) node->left = insertRec(node->left, value);
    if (value >= node->data) node->right = insertRec(node->right, value);
    
    return node;
}

// Insert a new node (value)
template<class T>
void BinarySearchTree<T>::insert(const T& value) {
    // Time complexity:
    root = insertRec(root, value);
}


// ======================= REMOVE =======================

// Recursive remove helper
template<class T>
typename BinarySearchTree<T>::Node* 
BinarySearchTree<T>::removeRec(Node* node, const T& value, bool& removed) {
    // Time complexity:
    if (node == nullptr) return nullptr;

    if (value < node->data) node->left = removeRec(node->left, value, removed);
    else if (value > node->data) node->right = removeRec(node->right, value, removed);
    else {
        removed = true;
        // leaf
        if (node->left == nullptr && node->right == nullptr){
            delete node;
            nodeCount--;
            return nullptr;
            
        }

        // one child
        if (node->left == nullptr){
            Node * child = node->right;
            delete node;
            nodeCount--;
            return child;
        }
        if (node->right == nullptr){
            Node *child = node->left;
            delete node;
            nodeCount--;
            return child;
        }

        // two child
        Node *minNode = findMin(node->right);
        node->data = minNode->data;
        node->right = removeRec(node->right, minNode->data, removed);
    }
    return node;
}

// Remove node by value
template<class T>
bool BinarySearchTree<T>::remove(const T& value) {
    // Time complexity:
    bool removed = false;
    root = removeRec(root, value, removed);
    return removed;
}


// ======================= FIND MIN / FIND MAX =======================

// Find node with smallest value in subtree
template<class T>
typename BinarySearchTree<T>::Node* 
BinarySearchTree<T>::findMin(Node* node) const {
    // Time complexity:
    if (node == nullptr) return nullptr;
    while (node->left) node = node->left;
    return node;
}

// Find node with largest value in subtree
template<class T>
typename BinarySearchTree<T>::Node* 
BinarySearchTree<T>::findMax(Node* node) const {
    // Time complexity:
    if (node == nullptr) return nullptr;
    while (node->right) node = node->right;
    return node;
}

// Return minimum value in tree
template<class T>
const T& BinarySearchTree<T>::findMin() const {
    // Time complexity:
    if (root == nullptr) throw out_of_range("Tree is empty: Cannot find Min");
    Node *min = findMin(root);
    return min->data;
}

// Return maximum value in tree
template<class T>
const T& BinarySearchTree<T>::findMax() const {
    // Time complexity:
    if (root == nullptr) throw out_of_range("Tree is empty: Cannot find Max");
    Node *max = findMax(root);
    return max->data;
}


// ======================= CONTAINS =======================

// Check if value exists in subtree
template<class T>
bool BinarySearchTree<T>::contains(Node* node, const T& value) const {
    // Time complexity:
    if (node == nullptr) return false;
    if (value == node->data) return true;
    
    if (value < node->data) return contains(node->left, value);
    else return contains(node->right, value);
}

// Check if value exists
template<class T>
bool BinarySearchTree<T>::contains(const T& value) const {
    // Time complexity:
    return contains(root, value);
}


// ======================= TREE INFO METHODS =======================

// Check if tree is empty
template<class T>
bool BinarySearchTree<T>::empty() const {
    // Time complexity:
    if (root == nullptr) return true;
    if (nodeCount == 0) return true;
    return false;
}

// Return number of nodes
template<class T>
int BinarySearchTree<T>::size() const {
    // Time complexity:
    return nodeCount;
}

// Return height of subtree
template<class T>
int BinarySearchTree<T>::height(Node* node) const {
    // Time complexity:
    if (node == nullptr) return 0;

    int lh = height(node->left);
    int rh = height(node->right);

    if (lh > rh) return 1 + lh;
    else return 1 + rh;
}

// Return height of the tree
template<class T>
int BinarySearchTree<T>::height() const {
    // Time complexity:
    return height(root);
}

// Return value of root node
template<class T>
const T& BinarySearchTree<T>::rootNode() const {
    // Time complexity:
    if (root == nullptr) throw out_of_range("Tree is empty!");
    return root->data;
}


// ======================= COUNT METHODS =======================

// Count number of leaf nodes in subtree
template<class T>
int BinarySearchTree<T>::countLeaves(Node* node) const {
    // Time complexity:
    if (node == nullptr) return 0;
    if (node->left == nullptr && node->right == nullptr) return 1;
    return countLeaves(node->left) + countLeaves(node->right);
}

// Count number of internal nodes in subtree
template<class T>
int BinarySearchTree<T>::countInternalNodes(Node* node) const {
    // Time complexity:
    if (node == nullptr) return 0;
    if (node->left == nullptr && node->right == nullptr) return 0;
    return countInternalNodes(node->left) + countInternalNodes(node->right) + 1;
}

// Count leaf nodes
template<class T>
int BinarySearchTree<T>::countLeaves() const {
    // Time complexity:
    return countLeaves(root);
}

// Count internal nodes
template<class T>
int BinarySearchTree<T>::countInternalNodes() const {
    // Time complexity:
    return countInternalNodes(root);
}


// ======================= TRAVERSAL HELPERS =======================

// Inorder traversal
template<class T>
void BinarySearchTree<T>::inorder(Node* node, stringstream& ss) const {
    // Time complexity:
    if (node == nullptr) return;
    inorder(node->left, ss);
    ss << node->data << " ";
    inorder(node->right, ss);
}

// Preorder traversal
template<class T>
void BinarySearchTree<T>::preorder(Node* node, stringstream& ss) const {
    // Time complexity:
    if (node == nullptr) return;
    ss << node->data << " ";
    preorder(node->left, ss);
    preorder(node->right, ss);
}

// Postorder traversal
template<class T>
void BinarySearchTree<T>::postorder(Node* node, stringstream& ss) const {
    // Time complexity:
    if (node == nullptr) return;
    postorder(node->left, ss);
    postorder(node->right, ss);
    ss << node->data << " ";
}

// Level-order traversal
template<class T>
void BinarySearchTree<T>::levelorder(Node* node, stringstream& ss) const {
    // Time complexity:
    if (node == nullptr) return;
    ArrayQueue<Node*> q; 
    q.enqueue(node); 

    while (!q.empty()) {
        Node* cur = q.dequeue();
        
        ss << cur->data << " ";
        
        if (cur->left)  q.enqueue(cur->left);
        if (cur->right) q.enqueue(cur->right);
    }
}


// ======================= TRAVERSAL PUBLIC =======================

// Return string of inorder traversal
template<class T>
string BinarySearchTree<T>::inorder() const {
    // Time complexity:
    stringstream ss;
    inorder(root, ss);
    return ss.str();
}

// Return string of preorder traversal
template<class T>
string BinarySearchTree<T>::preorder() const {
    // Time complexity:
    stringstream ss;
    preorder(root, ss);
    return ss.str();
}

// Return string of postorder traversal
template<class T>
string BinarySearchTree<T>::postorder() const {
    // Time complexity:
    stringstream ss;
    postorder(root, ss);
    return ss.str();
}

// Return string of levelorder traversal
template<class T>
string BinarySearchTree<T>::levelorder() const {
    // Time complexity:
    stringstream ss;
    levelorder(root, ss);
    return ss.str();
}


// ======================= DEBUG =======================

// Convert tree to string
template<class T>
string BinarySearchTree<T>::toString() const {
    // Time complexity:
    return inorder();
}


// ======================= EXPLICIT INSTANTIATION =======================

template class BinarySearchTree<int>;
template class BinarySearchTree<string>;
template class BinarySearchTree<double>;
