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

#include <queue>
#include <iostream>

template<typename T>
struct Node
{
    Node(T data)
    {
        this->left = nullptr;
        this->right = nullptr;

        this->data = data;
    };

    // Using this for now, while I understand overloading operators of templates.
    // It's something simple that I am overlooking obviously.
    // 0 if smaller than right side, 1 if great than right side.
    CompareTo(Node& right)
    {
        return(this->data > right.data);
    }

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
        // Local variables.
        Node<T>* newNode = new Node<T>(data);
        Node<T>* currNode;
        std::queue<Node<T>*> queue;

        // Edge case of root being a nullptr.
        if(!this->rootNode)
        {
            this->rootNode = newNode;
        }

        queue.push(this->rootNode);

        while(!queue.empty())
        {
            currNode = queue.front();
            queue.pop();


/*          The node is the same as our current node.
            Decide which methodo of handling duplicates I want to do.
            if(node == currNode)
            {

            }
*/
            // The node is smaller than the current node, so the node is propagated down the left side.
            if(!newNode->CompareTo(*currNode))
            {
                if(!currNode->left)
                {
                    currNode->left = newNode;
                    return;
                };

                queue.push(currNode->left);
                continue;
            }
            // The node is larger than the current node, so the node is propagated down the right side.    
            else
            {
                if(!currNode->right)
                {
                    currNode->right = newNode;
                    return;
                }

                queue.push(currNode->right);
            }
        }
    }

    std::string VisualizeTree()
    {
        // Find tree height for formatting.
        // Repeat until queue is empty.
        // Pop queue
        // Print node
        // If has children, print branches characters.
        // qeueu it's children
    }

    int GetTreeHeight()
    {
        return treeHeight;
    };

    Node<T>& Peek()
    {
        return *rootNode;
    };
private:
    Node<T>* rootNode;
    int treeHeight;
};

#endif