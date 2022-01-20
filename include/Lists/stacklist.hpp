#ifndef STACK_HPP
#define STACK_HPP

// Stack
// FILO (First In, Last Out)
// Nodes pushed to the stack are pushed to the front, nodes taken out of the stack are taken from the front.

template<typename T>
struct Node
{
    Node()
    {
        this->data = nullptr;
        this->nextNode = nullptr;
    };

    Node(T data)
    {
        this->data = data;
        this->nextNode = nullptr;
    }

    T data;
    Node* nextNode;
};

template<typename T>
class StackList
{
public:
    StackList();

    void Push(T data)
    {
        Node<T>* newNode = new Node<T>(data);

        if(!head)
        {
            head = newNode;
            return;
        }

        newNode->nextNode = head;

        head = newNode;
    };

    T Pop()
    {
        T data = nullptr;
        Node<T>* temp = nullptr;

        if(!head)
        {
            return nullptr;
        }

        data = head->nextNode;
        temp = head;
        head = head->nextNode;

        // Free allocated memory.
        delete temp;
        return data;
    };

    T Peek()
    {
        return head->data;
    };

    void Empty()
    {

    };

private:
    Node<T>* head;
};

#endif