#include "tree/AVL.h"
#include "queue/Queue.h"
// ================== CONSTRUCTOR / DESTRUCTOR =====================

template<class T>
AVLTree<T>::AVLTree() {
    // Time complexity:
    root = nullptr;
    nodeCount = 0;
}

template<class T>
typename AVLTree<T>::Node* AVLTree<T>::copySubtree(Node* node) {
    if (node == nullptr) return nullptr;

    Node *newNode = new Node(node->data);
    newNode->left = copySubtree(node->left);
    newNode->right = copySubtree(node->right);
    return newNode;
}

template<class T>
AVLTree<T>::AVLTree(const AVLTree<T>& other) {
    // Time complexity:
    root = copySubtree(other.root);
    nodeCount = other.nodeCount;
}

template<class T>
AVLTree<T>::~AVLTree() {
    // Time complexity:
    clear();
}

template<class T>
AVLTree<T>& AVLTree<T>::operator=(const AVLTree<T>& other) {
    // Time complexity:
    if (this == &other) return *this;
    clear();
    root = copySubtree(other.root);
    nodeCount = other.nodeCount;
    return *this;
}

// ================= CLEAR =======================

template<class T>
void AVLTree<T>::clear(Node*& node) {
    // Time complexity:
    if (node == nullptr) return;
    clear(node->left);
    clear(node->right);
    delete node;
    node = nullptr;
}

template<class T>
void AVLTree<T>::clear() {
    // Time complexity:
    clear(root);
    root = nullptr;
    nodeCount = 0;
}

// ================= HEIGHT ========================

template<class T>
int AVLTree<T>::height(Node* node) const {
    // Time complexity:
    if (node == nullptr) return 0;
    
    int lh = height(node->left);
    int rh = height(node->right);

    if (lh > rh) return 1 + lh;
    else return 1 + rh;
}

template<class T>
int AVLTree<T>::height() const {
    // Time complexity:
    return height(root);
}


// ================= GET BALANCE =======================

template<class T>
int AVLTree<T>::getBalance(Node* node) const {
    // Time complexity: O(N) (Do hàm height của bạn là O(N))
    if (node == nullptr) return 0;
    return height(node->left) - height(node->right);
}

// ================= FIND MIN ======================

template<class T>
typename AVLTree<T>::Node* 
AVLTree<T>::findMin(Node* node) const {
    // Time complexity:
    if (node == nullptr) return nullptr;
    while (node->left) node = node->left;
    return node;
}

template<class T>
const T& AVLTree<T>::findMin() const {
    // Time complexity:
    if (root == nullptr) throw out_of_range("Tree empty");
    Node *min = findMin(root);
    return min->data;
}

// ================= FIND MAX ======================

template<class T>
typename AVLTree<T>::Node*
AVLTree<T>::findMax(Node* node) const {
    // Time complexity:
    if (node == nullptr) return nullptr;
    while (node->right) node = node->right;
    return node;
}

template<class T>
const T& AVLTree<T>::findMax() const {
    // Time complexity:
    if (root == nullptr) throw out_of_range("Tree empty");
    Node *max = findMax(root);
    return max->data;
}

// ================= CONTAINS ======================

template<class T>
bool AVLTree<T>::contains(Node* node, const T& value) const {
    // Time complexity:
    if (node == nullptr) return false;

    if (value == node->data) return true;

    if (value < node->data) return contains(node->left, value);
    else return contains(node->right, value);
}

template<class T>
bool AVLTree<T>::contains(const T& value) const {
    // Time complexity:
    return contains(root, value);
}

// ================= COUNT LEAVES ===============================

template<class T>
int AVLTree<T>::countLeaves(Node* node) const {
    // Time complexity:
    if (node == nullptr) return 0;
    if (node->left == nullptr && node->right == nullptr) return 1;
    return countLeaves(node->left) + countLeaves(node->right);
}

template<class T>
int AVLTree<T>::countLeaves() const {
    // Time complexity:
    return countLeaves(root);
}

// ================= COUNT INTERNAL ============================

template<class T>
int AVLTree<T>::countInternalNodes(Node* node) const {
    // Time complexity:
    if (node == nullptr) return 0;
    if (node->left == nullptr && node->right == nullptr) return 0;
    return 1 + countInternalNodes(node->left) + countInternalNodes(node->right);
}

template<class T>
int AVLTree<T>::countInternalNodes() const {
    // Time complexity:
    return countInternalNodes(root);
}

// ================= ROTATIONS ======================

template<class T>
typename AVLTree<T>::Node*
AVLTree<T>::rotateLeft(Node* node) {
    // Time complexity:
    if (node == nullptr || node->right == nullptr) return nullptr;
    Node *temp = node->right;
    node->right = temp->left;
    temp->left = node;
    return temp;
}

template<class T>
typename AVLTree<T>::Node*
AVLTree<T>::rotateRight(Node* node) {
    // Time complexity:
    if (node == nullptr || node->left == nullptr) return nullptr;
    Node *temp = node->left;
    node->left = temp->right;
    temp->right = node;
    return temp;
}

// ================= REBALANCE CASES ======================

template<class T>
typename AVLTree<T>::Node*
AVLTree<T>::rebalanceLL(Node* node) {
    return rotateRight(node);
}

template<class T>
typename AVLTree<T>::Node*
AVLTree<T>::rebalanceLR(Node* node) {
    node->left = rotateLeft(node->left);
    return rotateRight(node);
}

template<class T>
typename AVLTree<T>::Node*
AVLTree<T>::rebalanceRR(Node* node) {
    return rotateLeft(node);
}

template<class T>
typename AVLTree<T>::Node*
AVLTree<T>::rebalanceRL(Node* node) {
    node->right = rotateRight(node->right);
    return rotateLeft(node);
}



// ================= INSERT LOGIC ===============================

template<class T>
typename AVLTree<T>::Node*
AVLTree<T>::rebalanceInsert(Node* node, const T& value) {
    // Time complexity:
    int balance = getBalance(node);

    // Lech trai
    if (balance > 1){
        if (value < node->left->data) return rebalanceLL(node); // LL
        if (value >= node->left->data) return rebalanceLR(node); // LR
    }

    // Lech phai
    if (balance < -1){
        if (value >= node->right->data) return rebalanceRR(node); // RR
        if (value < node->right->data) return rebalanceRL(node); // RL
    }
    return node; // ko lech
}

template<class T>
typename AVLTree<T>::Node*
AVLTree<T>::insertAVL(Node* node, const T& value) {
    // Time complexity:
    if (node == nullptr){
        node = new Node(value);
        nodeCount++;
        return node;
    }

    if (value < node->data)  node->left = insertAVL(node->left, value);
    if (value >= node->data) node->right = insertAVL(node->right, value);

    return rebalanceInsert(node, value);
}

template<class T>
void AVLTree<T>::insert(const T& value) {
    // Time complexity:
    root = insertAVL(root, value);
}


// ================= REMOVE LOGIC ===============================

template<class T>
typename AVLTree<T>::Node*
AVLTree<T>::rebalanceAfterDelete(Node* node) {
    // Time complexity:
    int balance = getBalance(node);

    //Lech trai
    if (balance > 1){
        if (getBalance(node->left) >= 0) return rebalanceLL(node);
        if (getBalance(node->left) < 0) return rebalanceLR(node);
    }

    //Lech phai
    if (balance < -1){
        if (getBalance(node->right) <= 0) return rebalanceRR(node);
        if (getBalance(node->right) > 0) return rebalanceRL(node);
    }
    return node;
}

template<class T>
typename AVLTree<T>::Node*
AVLTree<T>::removeAVL(Node* node, const T& value, bool& removed) {
    // Time complexity:
    if (node == nullptr) return nullptr;

    if (value < node->data) node->left = removeAVL(node->left, value, removed);
    else if (value > node->data) node->right = removeAVL(node->right, value, removed);
    else{
        // leaf
        removed = true;
        if (node->left == nullptr && node->right == nullptr){
            delete node;
            nodeCount--;
            return nullptr;
        }

        // one child
        if (node->left == nullptr){
            Node *child = node->right;
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
        Node *min = findMin(node->right);
        node->data = min->data;
        node->right = removeAVL(node->right, min->data, removed);
    }
    return rebalanceAfterDelete(node);
}

template<class T>
bool AVLTree<T>::remove(const T& value) {
    // Time complexity:
    bool removed = false;
    root = removeAVL(root, value, removed);
    return removed;
}



// ================= TRAVERSAL (PRIVATE) =======================

template<class T>
void AVLTree<T>::inorder(Node* node, stringstream& ss) const {
    // Time complexity:
    if (node == nullptr) return;
    inorder(node->left, ss);
    ss << node->data << " ";
    inorder(node->right, ss);
}

template<class T>
void AVLTree<T>::preorder(Node* node, stringstream& ss) const {
    // Time complexity:
    if (node == nullptr) return;
    ss << node->data << " ";
    preorder(node->left, ss);
    preorder(node->right, ss);
}

template<class T>
void AVLTree<T>::postorder(Node* node, stringstream& ss) const {
    // Time complexity:
    if (node == nullptr) return;
    postorder(node->left, ss);
    postorder(node->right, ss);
    ss << node->data << " ";
}

template<class T>
void AVLTree<T>::levelorder(Node* node, stringstream& ss) const {
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



// ================= TRAVERSAL (PUBLIC) ========================

template<class T>
string AVLTree<T>::inorder() const {
    // Time complexity:
    stringstream ss;
    inorder(root, ss);
    return ss.str();
}

template<class T>
string AVLTree<T>::preorder() const {
    // Time complexity:
    stringstream ss;
    preorder(root, ss);
    return ss.str();
}

template<class T>
string AVLTree<T>::postorder() const {
    // Time complexity:
    stringstream ss;
    postorder(root, ss);
    return ss.str();
}

template<class T>
string AVLTree<T>::levelorder() const {
    // Time complexity:
    stringstream ss;
    levelorder(root, ss);
    return ss.str();
}



// ================= TREE INFO ======================

template<class T>
bool AVLTree<T>::empty() const {
    // Time complexity:
    if (root == nullptr) return true;
    if (nodeCount == 0) return true;
    return false;
}

template<class T>
int AVLTree<T>::size() const {
    // Time complexity:
    return nodeCount;
}

template<class T>
const T& AVLTree<T>::rootNode() const {
    // Time complexity:
    if (root == nullptr) throw std::out_of_range("Tree is empty");

    return root->data;
}


// ================= DEBUG ==========================

template<class T>
string AVLTree<T>::toString() const {
    // Time complexity:
    return inorder();
}



// ================= INSTANTIATION ==============================

template class AVLTree<int>;
template class AVLTree<string>;
template class AVLTree<double>;
