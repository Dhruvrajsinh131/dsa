class DNode
{

public:
    int data;
    DNode *next;
    DNode *prev;

    DNode(int data)
    {
        this->data = data;
        this->next = nullptr;
        this->prev = nullptr;
    }
};