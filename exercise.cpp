#include <iostream>
using namespace std;

// 链式队列
template <class elemType>
class linkQueue
{
private:
    class node
    {
        friend class linkQueue;

    private:
        elemType data;
        node *next;

    public:
        node() : next(nullptr){};
        node(const elemType &e, node *p = nullptr) : data(e), next(p){};
    };

    node *head, *rear;
    int len;

public:
    linkQueue() : len(0)
    {
        head = new node;
        rear = head;
    };
    bool isEmpty() { return !head->next; };
    bool isFull() { return false; };
    int Length() { return len; };
    elemType &Front() { return head->next->data; }
    void enQueue(const elemType &e);
    void deQueue();
    ~linkQueue();
};

template <class elemType>
void linkQueue<elemType>::enQueue(const elemType &e)
{
    rear->next = new node(e);
    rear = rear->next;
    len++;
}

template <class elemType>
void linkQueue<elemType>::deQueue()
{
    if (!len)
    {
        cout << "the queue is empty" << endl;
        return;
    }
    node *p = head->next;
    head->next = p->next;
    delete p;
    len--;
}

template <class elemType>
linkQueue<elemType>::~linkQueue()
{
    while (len)
    {
        node *p = head->next;
        head->next = p->next;
        delete p;
        len--;
    }
    delete head;
}

// 链式栈
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

public:
    linkstack() { Top = nullptr; };
    bool isEmpty() { return !Top; };
    elemType top()
    {
        return Top->data;
    };
    void push(const elemType &e);
    void pop();
    ~linkstack();
};

template <class elemType>
void linkstack<elemType>::push(const elemType &e)
{
    Top = new node(e, Top);
}

template <class elemType>
void linkstack<elemType>::pop()
{
    node *p = Top;
    Top = Top->next;
    delete p;
}

template <class elemType>
linkstack<elemType>::~linkstack()
{
    while (Top)
    {
        pop();
    }
}

// 二叉树的节点
struct treeUnit
{
    treeUnit *left, *right;
    int num;
    bool inRight;

    treeUnit(int x) : num(x)
    {
        left = nullptr;
        right = nullptr;
        inRight = false;
    }
};

// 还原二叉树
treeUnit *createTree(linkQueue<int> *tieGroup)
{
    linkstack<treeUnit *> tieNumber;
    treeUnit *root = new treeUnit(tieGroup->Front());
    treeUnit *p = root;
    tieGroup->deQueue();
    tieNumber.push(root);
    while (!tieGroup->isEmpty())
    {
        if (tieGroup->Front() != 0)
        {
            if (p->inRight)
            {
                p->right = new treeUnit(tieGroup->Front());
                tieNumber.push(p->right);
                p = p->right;
                tieGroup->deQueue();
            }
            else
            {
                p->left = new treeUnit(tieGroup->Front());
                tieNumber.push(p->left);
                p = p->left;
                tieGroup->deQueue();
            }
        }
        else
        {
            while (p->inRight && p != root)
            {
                tieNumber.pop();
                p = tieNumber.top();
            }
            p->inRight = true;
            tieGroup->deQueue();
        }
    }
    return root;
}

// 中序遍历
void midRound(treeUnit *root)
{
    linkstack<treeUnit *> stack1;
    linkstack<int> stack2;
    treeUnit *p = root;
    stack1.push(root);
    stack2.push(1);
    while (p->left)
    {
        p = p->left;
        stack1.push(p);
        stack2.push(1);
    }
    while (1)
    {
        if (stack2.top() == 0)
        {
            stack2.pop();
            stack2.push(1);
            while (p->left)
            {
                p = p->left;
                stack1.push(p);
                stack2.push(1);
            }
        }
        else if (stack2.top() == 1)
        {
            cout << stack1.top()->num << ' ';
            stack2.pop();
            stack2.push(2);
            if (p->right)
            {
                p = p->right;
                stack1.push(p);
                stack2.push(0);
            }
        }
        else
        {
            stack1.pop();
            stack2.pop();
            if (!stack1.isEmpty())
            {
                p = stack1.top();
            }
            else
                break;
        }
    }
    cout << endl;
}

// 后序遍历
void rearRound(treeUnit *root)
{
    linkstack<treeUnit *> stack1;
    linkstack<int> stack2;
    treeUnit *p = root;
    stack1.push(root);
    stack2.push(1);
    while (p->left)
    {
        p = p->left;
        stack1.push(p);
        stack2.push(1);
    }
    while (1)
    {
        if (stack2.top() == 0)
        {
            stack2.pop();
            stack2.push(1);
            while (p->left)
            {
                p = p->left;
                stack1.push(p);
                stack2.push(1);
            }
        }
        else if (stack2.top() == 1)
        {
            if (p->right)
            {
                stack2.pop();
                stack2.push(2);
                p = p->right;
                stack1.push(p);
                stack2.push(0);
            }
            else
            {
                stack2.pop();
                stack2.push(2);
            }
        }
        else
        {
            cout << stack1.top()->num << ' ';
            stack1.pop();
            stack2.pop();
            if (!stack1.isEmpty())
            {
                p = stack1.top();
            }
            else
                break;
        }
    }
}

int main()
{
    char x;
    int num = 0;
    linkQueue<int> tieGroup;

    // 存储输入
    while ((x = cin.get()) != '\n')
    {

        if (x == ' ')
        {
            tieGroup.enQueue(num);
            num = 0;
        }
        else if (x != '.')
        {
            num = num * 10 + x - '0';
        }
    }
    treeUnit *root = createTree(&tieGroup);
    midRound(root);
    rearRound(root);
}