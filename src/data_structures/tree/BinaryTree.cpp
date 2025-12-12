#include "tree/BinaryTree.h"

// ======================= CONSTRUCTOR / DESTRUCTOR =======================

template<class T>
BinaryTree<T>::BinaryTree() {
    // Time complexity: O(1)
    root = nullptr;
    nodeCount = 0;
}

template<class T>
typename BinaryTree<T>::Node* BinaryTree<T>::copySubtree(Node* node) {
    // Time complexity: O(n_sub) với n_sub là số node của cây con gốc tại node
    if (!node) return nullptr;

    Node* newNode = new Node(node->data);
    newNode->left  = copySubtree(node->left);
    newNode->right = copySubtree(node->right);
    return newNode;
}

template<class T>
BinaryTree<T>::BinaryTree(const BinaryTree<T>& other) {
    // Time complexity:
    root = copySubtree(other.root);
    nodeCount = other.nodeCount;
}

template<class T>
BinaryTree<T>::~BinaryTree() {
    // Time complexity:
    clear();
}

template<class T>
BinaryTree<T>& BinaryTree<T>::operator=(const BinaryTree<T>& other) {
    // Time complexity:
    if (this == &other) return *this;
    clear();
    root = copySubtree(other.root);
    nodeCount = other.nodeCount;
    return *this;
}

// ======================= CLEAR =======================

template<class T>
void BinaryTree<T>::clear(Node*& node) {
    // Time complexity:
    if (node == nullptr) return;

    clear(node->left);
    clear(node->right);
    delete node;
    node = nullptr;
}

template<class T>
void BinaryTree<T>::clear() {
    // Time complexity:
    clear(root);
    root = nullptr;
    nodeCount = 0;
}

// ======================= HEIGHT =======================

template<class T>
int BinaryTree<T>::height(Node* node) const {
    // Time complexity:
    if (node == nullptr) return 0;
    int lh = height(node->left);
    int rh = height(node->right);

    if (lh > rh) return 1 + lh;
    else return 1 + rh;
}

template<class T>
int BinaryTree<T>::height() const {
    // Time complexity: O(n)
    return height(root);
}

// ======================= COUNT LEAVES =======================

template<class T>
int BinaryTree<T>::countLeaves(Node* node) const {
    // Time complexity:
    if (node == nullptr) return 0;
    if (node->left == nullptr && node->right == nullptr) return 1;
    return countLeaves(node->left) + countLeaves(node->right);
}

template<class T>
int BinaryTree<T>::countLeaves() const {
    // Time complexity:
    return countLeaves(root);
}

// ======================= COUNT INTERNAL NODES =======================

template<class T>
int BinaryTree<T>::countInternalNodes(Node* node) const {
    // Time complexity:
    if (node == nullptr) return 0;
    if (node->left == nullptr && node->right == nullptr) return 0;
    return 1 + countInternalNodes(node->left) +countInternalNodes(node->right);
}

template<class T>
int BinaryTree<T>::countInternalNodes() const {
    // Time complexity:
    return countInternalNodes(root);
}

// ======================= TRAVERSALS =======================

// ----- Inorder -----
template<class T>
void BinaryTree<T>::inorder(Node* node, stringstream& ss) const {
    // Time complexity:
    if (node == nullptr) return;
    inorder(node->left, ss);
    ss << node->data << " ";
    inorder(node->right, ss);
}

template<class T>
string BinaryTree<T>::inorder() const {
    // Time complexity:
    stringstream ss;
    inorder(root, ss);
    return ss.str();
}

// ----- Preorder -----
template<class T>
void BinaryTree<T>::preorder(Node* node, stringstream& ss) const {
    // Time complexity:
    if (node == nullptr) return;
    ss << node->data << " ";
    preorder(node->left, ss);
    preorder(node->right, ss);
}

template<class T>
string BinaryTree<T>::preorder() const {
    // Time complexity:
    stringstream ss;
    preorder(root, ss);
    return ss.str();
}

// ----- Postorder -----
template<class T>
void BinaryTree<T>::postorder(Node* node, stringstream& ss) const {
    // Time complexity:
    if (node == nullptr) return;
    postorder(node->left, ss);
    postorder(node->right, ss);
    ss << node->data << " ";
}

template<class T>
string BinaryTree<T>::postorder() const {
    // Time complexity:
    stringstream ss;
    postorder(root, ss);
    return ss.str();
}

// ----- Levelorder -----
template<class T>
void BinaryTree<T>::levelorder(Node* node, stringstream& ss) const {
    // Time complexity:
}

template<class T>
string BinaryTree<T>::levelorder() const {
    // Time complexity:
    return "";
}

// ======================= STATUS METHODS =======================

template<class T>
bool BinaryTree<T>::empty() const {
    // Time complexity:
    if (nodeCount == 0) return true;
    return false;
}

template<class T>
int BinaryTree<T>::size() const {
    // Time complexity:
    return nodeCount;
}

template<class T>
const T& BinaryTree<T>::rootNode() const {
    // Time complexity:
    return root->data;
}

// ======================= DEBUG / UTILITY =======================

template<class T>
string BinaryTree<T>::toString() const {
    // Time complexity:
    return inorder();
}

// ======================= EXPLICIT INSTANTIATION (optional) =======================

template class BinaryTree<int>;
template class BinaryTree<string>;
template class BinaryTree<double>;
