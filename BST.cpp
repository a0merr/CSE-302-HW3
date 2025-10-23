#include <iostream>
#include <algorithm>
#include "BST.h"
using namespace std;

// Constructor and Destructor //
BST::BST() {
  root = nullptr;
}

BST::~BST() {
  Destory(root);
}
// Recursively delete nodes
void BST::Destory(Node* node) {
  if (node != nullptr) {
    Destroy(node->left);
    Destroy(node->right);
    delete node;
  }
}
// Insert function //
void BST::Insert(int value) {
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
//if equal, ignore duplicates//
return node;
}
// Search function //
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
  rturn SearchHelper(node->right, value);
}
// Print Inorder (sorted order) //
void BST::PrintInOrder() const {
  PrintInOrderHelper(root);
  cout << endl;
}
void BST::PrintInOrderHelper(Node* node) const {
  if (node == nullptr)
    return;
  PrintInOrderhelper(node->left);
  cout << node->key << " ";
  PrintInOrderHelper(node->right);
}
// PART 1: GetHeight() Implementation //
int BST::GetHeight() const {
  return GetHeightHelper(root);
}
int BST::GetHeightHelper(Node* node) const {
  if (node == nullptr)
    return -1; // empty tree height = -1
  int leftHeight = GetHeightHelper(node->left);
  int rightHeight = GetHeightHelper(node->right);
  return 1 + std::max(leftHeight, rightHeight);
}
// Part 2: SplitBalance(0 Implementation //
void BST::SplitBalance() {
  const int MAX_SIZE = 10000;
  int arr[MAX_SIZE];
  int index = 0;
  //Step 1: Store elements in sorted order
  InOrderStore(root, arr, index);
  Destory(root);
  root = BuildBalancedTree(arr, 0, index - 1);
}
void BST::InOrderStore(Node* node, int arr[], int& index) {
  if (node == nullptr) return;
  InOrderStore(node->left, arr, index);
  arr[index++] = node->key;
  InOrderStore(node->right, arr, index);
}
BST::Node* BST::BuildBalancedTree(int arr[], int start, int end) {
  if (start > end)
    return nullptr;
  int mid = (start + end) / 2;
  Node* newNode = new Node;
  newNode->key = arr[mid];
  newNode->left = BuildBalancedTree(arr, start, mid - 1);
  newNode->right = BuildBalancedTree(arr, mid + 1, end);
  return newNode;
}
