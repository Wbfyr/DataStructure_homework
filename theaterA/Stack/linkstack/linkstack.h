#ifndef LINKSTACK
#define LINKSTACK
#include <iostream>
#include "../../../throwerror.h"
using namespace std;

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
        if (!Top)
            throw throwerror("stack is empty, and top is null");
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
    if (isEmpty())
        throw throwerror("stack is empty, can not pop");
    node *p = Top;
    Top = Top->next;
    delete p;
}

template <class elemType>
linkstack<elemType>::~linkstack()
{
    try
    {
        while (Top)
        {
            pop();
        }
    }
    catch (throwerror ex)
    {
    }
}

#endif