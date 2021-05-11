#ifndef BINARYTREE_HPP
#define BINARYTREE_HPP

#include <queue>
#include <iostream>

// Naive Binary Tree.
// No real value in using this structure as it performs worse than any other tree structure
// and has no real benefits over an array.

// Nodes may have a maximum of two children.
// Nodes are always pushed to the farthest left possible.
// Nodes are added arbitrarily


// Push - Pushes a new node to the tree
// Pop - Pops the furthest right node, unless given an index/val.
//       Given an index pop the node of that index, the left most node is always the successor.

// Tree Height - Can be found by simply traversing down the left most side of the tree.

// Index - Node's index within the tree.

struct Node
{
    Node(int val, int depth)
    {
        this->val = val;
        this->depth = depth;
        this->left = nullptr;
        this->right = nullptr;
    }

    Node* left;
    Node* right;

    int val;
    int depth;
};

class BinaryTree
{
public:
    BinaryTree();
    BinaryTree(int rootVal);
    ~BinaryTree();

    int GetTreeHeight();

    void Push(int nodeVal);
    void Pop();
    void Remove(int key);

    Node& Find(int key);
    Node& RecursiveFind(Node* node, int key);
    Node& Peek();
    Node& GetDeepestNode();
private:
    Node* rootNode;
    int treeHeight;
};

#endif