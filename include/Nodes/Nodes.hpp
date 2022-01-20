// Singly linked node. 
template<typename T>
struct ListNode
{
    ListNode(): T(nullptr), nextNode(nullptr)
    {};

    ListNode(T& data) : T(data), nextNode(nullptr)
    {};

    ListNode<T>* nextNode;
    T data;
};

// Doubly linked node.
template<typename T>
struct ListNodeD
{
    ListNodeD(): T(nullptr), nextNode(nullptr), prevNode(nullptr)
    {};

    ListNodeD(T& data) : T(data), nextNode(nullptr), prevNode(nullptr)
    {};

    ListNodeD<T>* nextNode;
    ListNodeD<T>* prevNode;
    T data;
};
