#ifndef LINKEDLIST_HPP
#define LINKEDLIST_HPP

// Linked list, 
// Nodes hold a pointer to the next node in the list, forming a chain.
// Nodes connections cannot go backwards.
//

/* TODO:
 - Sort list
 - InsertAt node
 - Deconstructor
 - Copy Constructor
*/

#include <sstream>

template<typename T>
struct Node
{
    Node(T data)
    {
        nextNode = nullptr;
        this->data = data;
    };

    Node* nextNode;
    T data;
};

template<typename T>
class LinkedList
{
public:
    LinkedList()
    {
        head = nullptr;
    };

    LinkedList(T data)
    {
        head = new Node<T>(data);
    };

    void Insert(T data)
    {
        // Allocate memory in heap for new node.
        Node<T>* newNode = new Node<T>(data);
        // Keep a temp so we can traverse the linked list.
        Node<T>* temp;

        // Check for valid root.
        if(!head)
        {
            head = newNode;
            return;
        }

        temp = head;

        while(temp)
        {
            // Once the end is found, assign our new node to that end. 
            if(!temp->nextNode)
            {
                temp->nextNode = newNode;
                return;
            }

            temp = temp->nextNode;
        }
    };

    void Delete(T data)
    {
        Node<T>* currentNode;
        Node<T>* prevNode;
        
        currentNode = head;

        // Handle head removal case.
        if(currentNode->data == data)
        {
            head = head->nextNode;
            delete currentNode;
            return;
        };

        while(currentNode)
        {
            if(currentNode->data == data)
            {
                // Remove the current node from the chain and relink the previous node to the current node's next node.
                prevNode->nextNode = currentNode->nextNode;

                delete currentNode;

                return;
            };

            prevNode = currentNode;
            currentNode = currentNode->nextNode;
        };
    };

    void DeleteAt(int ndx)
    {
        Node<T>* currentNode = nullptr;
        Node<T>* prevNode = nullptr;
        int currentIndex = 0;

        // Handle index at head case.
        if(ndx == 0)
        {
            currentNode = head;
            head = head->nextNode;
            delete currentNode;
            return;
        };

        currentNode = head;

        while(currentNode)
        {
            if(currentIndex == ndx)
            {
                prevNode->nextNode = currentNode->nextNode;
                delete currentNode;
                return;
            };

            prevNode = currentNode;
            currentNode = currentNode->nextNode;
            ++currentIndex;
        };
    }

    Node<T>& GetAt(int ndx)
    {
        Node<T>* currNode = nullptr;
        int currIndex = 0;

        // Handle index larger than list length.
        if(ndx > GetLength() || ndx < 0)
        {
            return *currNode;
        };

        currNode = head;

        while(currNode)
        {
            if(currIndex == ndx)
            {
                return *currNode;
            };

            currNode = currNode->nextNode;
            ++currIndex;
        };

        return *currNode;
    };

    int GetLength()
    {
        Node<T>* temp = head;
        int count = 0;

        while(temp)
        {
            temp = temp->nextNode;
            count++;
        };

        return count;
    };

    std::string ToString()
    {
        std::ostringstream oss;

        Node<T>* temp = head;
        
        while(temp)
        {
            oss << temp->data << " ";

            temp = temp->nextNode;
        };

        return oss.str();
    };
private:
    Node<T>* head;
};

#endif