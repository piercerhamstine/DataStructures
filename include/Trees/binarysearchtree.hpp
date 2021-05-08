#ifndef BINARYSEARCHTREE_HPP
#define BINARYSEARCHTREE_HPP

template<typename T>
struct Node
{
    Node* left;
    Node* right;

    T data;
};

template<typename T>
class BinarySearchTree
{
public:
    BinarySearchTree();
    BinarySearchTree(T dat);

    Insert(T data);
private:

};

#endif