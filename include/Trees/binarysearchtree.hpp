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


// TODO:
/*
- Handle duplicate nodes.
- Handle node deletion
- Handle sorting
- Handle Inorder, Preorder, Postorder traversal
*/

#include <queue>
#include <iostream>
#include <sstream>
#include <iomanip>

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
    LessThan(Node& right)
    {
        return (this->data < right.data);
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

        this->dirtyTreeHeight = false;
    };

    BinarySearchTree(T data)
    {
        Node<T>* node = new Node<T>(data);

        this->rootNode = node;

        this->dirtyTreeHeight = false;
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
            return;
        }

        // Set the tree height as dirty.
        this->dirtyTreeHeight = true;

        // Push the root node to the queue.
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
            if(newNode->LessThan(*currNode))
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

    // Still needs work but works decently for most types.
    std::string VisualizeTree()
    {
        std::ostringstream s;
        PrintTree("", s, this->rootNode, false);

        return s.str();
    }

    int GetTreeHeight()
    {
        if(dirtyTreeHeight)
        {
            this->treeHeight = TreeHeightRecursive(this->rootNode)-1;
        };

        return this->treeHeight;
    };

    Node<T>& Peek()
    {
        return *rootNode;
    };
private:
    int TreeHeightRecursive(Node<T>* node)
    {
        int heightLeft = 0;
        int heightRight = 0;

        if(!node)
        {
            return 0;
        }
        else
        {
            heightLeft = TreeHeightRecursive(node->left);
            heightRight = TreeHeightRecursive(node->right);

            if(heightLeft > heightRight)
            {
                return ++heightLeft;
            }

            return ++heightRight;
        }
    };

    void PrintTree(std::string s, std::ostringstream& sstrm, Node<T>* rootNode, bool isLeftNode)
    {
        if(rootNode)
        {
            // Push front string
            sstrm << s;

            // Decide what character to prefix the node with.
            if(isLeftNode)
            {
                sstrm << "|-";
            }
            else
            {
                sstrm << "|_";
            }

            // Display node data and push to the new line.
            sstrm << rootNode->data << std::endl;

            // Create temp string for seperating left and right node strings.
            // which basically allows us to return to the previous string state.
            // of before going into the left node.
            std::string sl = s;
            if(isLeftNode)
            {
                PrintTree(sl+="|  ", sstrm, rootNode->left, true);
                PrintTree(s+="|  ", sstrm, rootNode->right, false);
            }
            else
            {
                
                PrintTree(sl+="   ", sstrm, rootNode->left, true);
                PrintTree(s+="   ", sstrm, rootNode->right, false);
            }
        }
        else
        {   
            sstrm << s;

            if(isLeftNode)
            {
                sstrm << "|-";
            }
            else
            {
                sstrm << "|_";
            }

            sstrm << "X" << std::endl;
        }
    }

    Node<T>* rootNode;
    int treeHeight;

    bool dirtyTreeHeight;
};

#endif