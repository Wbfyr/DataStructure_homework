#ifndef LINKQUEUE
#define LINKQUEUE

#include <iostream>
using namespace std;

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

#endif