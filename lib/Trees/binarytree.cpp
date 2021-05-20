#include "../../include/Trees/binarytree.hpp"

/*
TODO:
    Implement RecursiveFind();
    Implement Deconstructor
        Fix Memory Leaks.
    
*/

BinaryTree::BinaryTree()
{
    this->rootNode = nullptr;
    this->treeHeight = 0;
}

BinaryTree::BinaryTree(int val)
{
    this->rootNode = new Node(val, 0);
};

BinaryTree::~BinaryTree()
{
    // Clean up tree.
};

// Creates a new node with the given value.
// Stores the node at the most left position possible in the binary tree.
void BinaryTree::Push(int nodeVal)
{
    // Create new node for insertion.
    Node* newNode = new Node(nodeVal, 0);

    if(!this->rootNode)
    {
        this->rootNode = newNode;
        return;
    }
        
    // Check root children.
    if(!this->rootNode->left)
    {
        this->rootNode->left = newNode;
        newNode->depth = 1;
        return;
    }
    else if(!this->rootNode->right)
    {
        this->rootNode->right = newNode;
        newNode->depth = 1;
        return;
    }

    // Queue for storing nodes to be searched.
    std::queue<Node*> queue;

    Node* tempNode = this->rootNode;

    queue.push(tempNode);

    while(!queue.empty())
    {
        // Move to the next node in the queue
        tempNode = queue.front();
        queue.pop();

        newNode->depth = tempNode->depth+1;

        // Check left node, if it isn't empty then push it to the queue.
        if(!tempNode->left)
        {
            tempNode->left = newNode;
            return;
        }
        else
        {
            queue.push(tempNode->left);
        }

        // Check right node, if it isn't empty then push it to the queue.
        if(!tempNode->right)
        {
            tempNode->right = newNode;
            return;
        }
        else
        {
            queue.push(tempNode->right);
        }
    }
};

// Removes the deepest, right most node from the tree.
void BinaryTree::Pop()
{
    if(!this->rootNode->left)
        delete this->rootNode;

    std::queue<Node*> queue;

    Node* tempNode = this->rootNode;

    queue.push(tempNode);
    
    int maxDepth = this->GetTreeHeight();

    while(!queue.empty())
    {
        tempNode = queue.front();
        queue.pop();

        if(tempNode->right)
        {
            if(tempNode->right->depth == maxDepth)
            {
                delete tempNode->right;
                tempNode->right = nullptr;
                return;
            }

            queue.push(tempNode->right);
        }

        if(tempNode->left)
        {
            if(tempNode->left->depth == maxDepth)
            {
                delete tempNode->left;
                tempNode->left = nullptr;
                return;
            }

            queue.push(tempNode->left);
        }
    }
};

// Returns a reference to the deepest node in the tree.
Node& BinaryTree::GetDeepestNode()
{
    if(!this->rootNode->left)
        return *this->rootNode;

    std::queue<Node*> queue;

    Node* tempNode = this->rootNode;

    queue.push(tempNode);

    int maxHeight = this->GetTreeHeight();

    while(!queue.empty())
    {
        tempNode = queue.front();
        queue.pop();

        if(tempNode->right)
        {
            if(tempNode->right->depth == maxHeight)
                return *tempNode->right;
            
            queue.push(tempNode->right);
        }

        if(tempNode->left)
        {
            if(tempNode->left->depth == maxHeight)
                return *tempNode->left;

            queue.push(tempNode->left);
        }
    }

    tempNode = nullptr;
    return *tempNode;
}

// Removes node of a specified value.
void BinaryTree::Remove(int key)
{
    std::queue<Node*> queue;
    
    Node* tempNode = this->rootNode;
    
    queue.push(tempNode);
}

// Returns a reference to the first instance of the specified key.
Node& BinaryTree::Find(int key)
{
    Node* tempNode = this->rootNode;

    std::queue<Node*> queue;

    queue.push(tempNode);

    while(!queue.empty())
    {
        tempNode = queue.front();
        queue.pop();

        if(tempNode->val == key)
        {
            return *tempNode;
        }

        if(tempNode->left)
            queue.push(tempNode->left);

        if(tempNode->right)
            queue.push(tempNode->right);
    }

    tempNode = nullptr;
    return *tempNode;
};

// Returns a reference to the first instance of the specified key, recursively.
Node& BinaryTree::RecursiveFind(Node* node, int key)
{

};

// Returns a reference to the root node.
Node& BinaryTree::Peek()
{
    return *rootNode;
}

// Because of the way insert works for this implementation of a binary tree
// it is known that the farthest left side of the tree will always contain the max depth/height of the tree.

// Returns the max height of the tree.
int BinaryTree::GetTreeHeight()
{
    int height = 0;

    Node* temp = this->rootNode;

    while(temp->left)
    {
        height++;
        temp = temp->left;
    }

    return height;
}