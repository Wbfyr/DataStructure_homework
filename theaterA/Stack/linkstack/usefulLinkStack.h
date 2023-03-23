template <class elemType>
class linkstack
{
private:
    class node
    {
        friend class linkstack;

    private:
        elemType data;
        node *next;

    public:
        node() : next(nullptr){};
        node(const elemType &e, node *p = nullptr) : data(e), next(p){};
    };

    node *Top;
    int len;

public:
    linkstack()
    {
        Top = nullptr;
        len = 0;
    };
    bool isEmpty() { return !len; };
    int Length() { return len; }
    elemType top()
    {
        return Top->data;
    };
    void push(const elemType &e);
    elemType pop();
    ~linkstack();
};

template <class elemType>
void linkstack<elemType>::push(const elemType &e)
{
    Top = new node(e, Top);
    len++;
}

template <class elemType>
elemType linkstack<elemType>::pop()
{
    node *p = Top;
    elemType e = Top->data;
    Top = Top->next;
    delete p;
    len--;
    return e;
}

template <class elemType>
linkstack<elemType>::~linkstack()
{
    while (len)
    {
        pop();
    }
}