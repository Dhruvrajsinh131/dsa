template <typename T>

class Node
{

public:
    Node *next;
    T data;
    Node(T data)
    {
        this->next = nullptr;
        this->data = data;
    }
};