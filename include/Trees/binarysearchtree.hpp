#ifndef BINARYSEARCHTREE_HPP
#define BINARYSEARCHTREE_HPP

// Binary Search Tree.
// Left node contains a key smaller than its parent.
// Right node contains a key larger than its parent.
// Each sub-tree must follow the above properties.
//
// Performs well in search, insertion and deletion, performing at O(logn)
// Compared to an Array at O(n).
// Out performed by an Array in accessing an object *ASSUMING* the object you are looking for is at your start index OR you know the exact position of object within the Array 
// otherwise you degrade to O(n) for searching within the Array.
//
// Handling duplicates:
// Three options for duplicates. 
// Allow duplicates and arbitrarily pick left or right for where the duplicate node will be stored.
// Not allow duplicates at all
// Allow duplicates and have Nodes store a count of how many are present at that position.

template<typename T>
struct Node
{
    Node(T data)
    {
        this->left = nullptr;
        this->right = nullptr;

        this->data = data;
    };

    Node* left;
    Node* right;

    T data;
};

template<typename T>
class BinarySearchTree
{
public:
    BinarySearchTree()
    {
        this->rootNode = nullptr;
    };

    BinarySearchTree(T data)
    {
        Node<T>* node = new Node<T>(data);

        this->rootNode = node;
    };

    void Insert(T data)
    {
        
    }

    Node<T>& Peek()
    {
        return *rootNode;
    };
private:
    Node<T>* rootNode;
};

#endif