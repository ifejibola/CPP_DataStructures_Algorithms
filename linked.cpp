

class LinkedListNode
{
public:
    int intValue_;
    LinkedListNode *next_;

    LinkedListNode(int intValue) : intValue_(intValue), next_(nullptr)
    {
    }
};

LinkedListNode *reverse(LinkedListNode *headOfList)
{
    LinkedListNode *currentNode = headOfList;
    LinkedListNode *prevNode = nullptr;
    LinkedListNode *nextNode = nullptr;

    while (currentNode)
    {
        /* code */

        // copy a pointer to the next element
        nextNode = currentNode->next_;

        // reverse the 'next' pointer
        currentNode->next_ = prevNode;

        // stepforward
        prevNode = currentNode;
        currentNode = nextNode;
    };

    while (currentNode)
    {
        // copy pointer to the next element
        nextNode = currentNode->next_;

        currentNode->next_ = prevNode;

        // step forwardd
        prevNode = currentNode;

        currentNode = nextNode;
    }

    return prevNode;
};