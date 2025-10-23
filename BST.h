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

    // Helper functions
    Node* InsertHelper(Node* node, int value);
    bool SearchHelper(Node* node, int value) const;
    void PrintInOrderHelper(Node* node) const;
    void Destroy(Node* node);
    int GetHeightHelper(Node* node) const;
    void InOrderStore(Node* node, int arr[], int& index);
    Node* BuildBalancedTree(int arr[], int start, int end);

public:
    BST();
    ~BST();

    // Match assignment/test names
    void MakeEmpty();          // clears the tree
    void PutItem(int value);   // insert item
    bool Search(int value) const;
    void PrintInOrder() const;

    // Assignment-required functions
    int GetHeight() const;
    void SplitBalance();
};

#endif
