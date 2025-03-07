template <typename T>
class BtreeNode
{

public:
    T data;
    BtreeNode *left;
    BtreeNode *right;

    BtreeNode(T data)
    {
        this->data = data;
        this->left = nullptr;
        this->right = nullptr;
    }
    ~BtreeNode()
    {
        delete left;
        delete right;
    }
};
