#ifndef BST_H
#define BST_H

class BST {
private:
  struct Node {
    int key;
    Node* left;
    Node* right;
};

Node* root;
//Helper functions//
Node8 InsertHelper(Node* node, int value);
bool SearchHelper(Node8 node, int value) const;
void PrintInOrderHelper(Node8 node) const;
void Destory(Node* node);
// GetHeight helpers//
int GetHeightHelper(Node8 node) const;
//splitBalance helpers//
void InOrderStore(Node* node, int arr[], int& index);
Node* BuildBalancedTree(int arr[], int start, int end);

public:
BST();
~BST();

void Insert(int value);
bool Search(int value) const;
void PrintInorder() const;
// Required new functions//
int GetHeight() const;
void SplitBalance();
};

#endif
