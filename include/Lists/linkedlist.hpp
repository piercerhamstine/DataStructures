#ifndef LINKEDLIST_HPP
#define LINKEDLIST_HPP

// Linked list, 
//
//
//

/* TODO:
 - Find specified node
 - Sort list
 - Delete node
 - InsertAt node
 - GetAt node
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

        // Check for valid root.
        if(!head)
        {
            head = newNode;
            return;
        }

        // Keep a temp so we can traverse the linked list.
        Node<T>* temp = head;

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