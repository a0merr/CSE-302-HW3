#include <iostream>
#include <algorithm>
#include "BST.h"
using namespace std;

// =============================================================
// Constructor / Destructor
// =============================================================
BST::BST() {
    root = nullptr;
}

BST::~BST() {
    MakeEmpty();
}

// =============================================================
// MakeEmpty — clears the entire tree
// =============================================================
void BST::MakeEmpty() {
    Destroy(root);
    root = nullptr;
}

// Recursive node deletion
void BST::Destroy(Node* node) {
    if (node != nullptr) {
        Destroy(node->left);
        Destroy(node->right);
        delete node;
    }
}

// =============================================================
// PutItem — inserts a value into the BST
// =============================================================
void BST::PutItem(int value) {
    root = InsertHelper(root, value);
}

BST::Node* BST::InsertHelper(Node* node, int value) {
    if (node == nullptr) {
        Node* newNode = new Node;
        newNode->key = value;
        newNode->left = nullptr;
        newNode->right = nullptr;
        return newNode;
    }
    if (value < node->key)
        node->left = InsertHelper(node->left, value);
    else if (value > node->key)
        node->right = InsertHelper(node->right, value);
    return node;
}

// =============================================================
// Search — returns true if value is in the tree
// =============================================================
bool BST::Search(int value) const {
    return SearchHelper(root, value);
}

bool BST::SearchHelper(Node* node, int value) const {
    if (node == nullptr)
        return false;
    else if (value == node->key)
        return true;
    else if (value < node->key)
        return SearchHelper(node->left, value);
    else
        return SearchHelper(node->right, value);
}

// =============================================================
// PrintInOrder — outputs sorted contents
// =============================================================
void BST::PrintInOrder() const {
    PrintInOrderHelper(root);
    cout << endl;
}

void BST::PrintInOrderHelper(Node* node) const {
    if (node == nullptr)
        return;
    PrintInOrderHelper(node->left);
    cout << node->key << " ";
    PrintInOrderHelper(node->right);
}

// =============================================================
// GetHeight — returns height of the tree
// =============================================================
int BST::GetHeight() const {
    return GetHeightHelper(root);
}

int BST::GetHeightHelper(Node* node) const {
    if (node == nullptr)
        return -1; // Empty tree height convention
    int left = GetHeightHelper(node->left);
    int right = GetHeightHelper(node->right);
    return 1 + std::max(left, right);
}

// =============================================================
// SplitBalance — rebuilds tree to be height-balanced
// =============================================================
void BST::SplitBalance() {
    const int MAX_SIZE = 10000;
    int arr[MAX_SIZE];
    int index = 0;

    // Store elements in sorted order
    InOrderStore(root, arr, index);

    // Delete current tree to avoid memory leaks
    MakeEmpty();

    // Rebuild as balanced tree
    root = BuildBalancedTree(arr, 0, index - 1);
}

void BST::InOrderStore(Node* node, int arr[], int& index) {
    if (node == nullptr) return;
    InOrderStore(node->left, arr, index);
    arr[index++] = node->key;
    InOrderStore(node->right, arr, index);
}

BST::Node* BST::BuildBalancedTree(int arr[], int start, int end) {
    if (start > end) return nullptr;
    int mid = (start + end) / 2;
    Node* node = new Node;
    node->key = arr[mid];
    node->left = BuildBalancedTree(arr, start, mid - 1);
    node->right = BuildBalancedTree(arr, mid + 1, end);
    return node;
}

