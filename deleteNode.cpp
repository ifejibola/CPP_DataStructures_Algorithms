/**
 *
 * write a function to delete a node from a linked list in constant time
 *
 *
 */

class LinkedListNode
{
public:
    int intValue_;
    LinkedListNode *next_;

    LinkedListNode(int intValue) : intValue_(intValue), next_(nullptr){};
};

LinkedListNode *reverse(LinkedListNode *headOfList)
{

    LinkedListNode *currentNode = headOfList;
    LinkedListNode *prevNode = nullptr;
    LinkedListNode *nextNode = nullptr;

    while (currentNode)
    {
        /* code */
        // copy pointer to the next element
        nextNode = currentNode->next_;

        currentNode->next_ = prevNode;

        // step
        prevNode = nextNode;
        currentNode = prevNode;
    }
};

void deleteNode(LinkedListNode *nodeToDelete)
{
    LinkedListNode *nextNode = nodeToDelete->next_;

    if (nextNode)
    {
        nodeToDelete->intValue_ = nextNode->intValue_;
    }
}

int main()
{
    LinkedListNode *a = new LinkedListNode(1);
    LinkedListNode *b = new LinkedListNode(2);
    LinkedListNode *c = new LinkedListNode(3);

    a->next_ = b;
    b->next_ = c;
}