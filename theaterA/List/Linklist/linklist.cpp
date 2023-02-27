#include "linklist.h"

template <class elemType>
int linklist<elemType>::length() const
{
    int i = 0;
    node *p = head;
    while (p->next)
        ++i;
    return i;
}

template <class elemType>
int linklist<elemType>::find(const elemType &e) const
{
    node *p = head;
    int i = 0;
    while (p->next)
    {
        ++i;
        p = p->next;
        if (e == p->data)
            return i;
    }
}

template <class elemType>
elemType &linklist<elemType>::get(int i) const
{
    if (i < 1)
        throw throwerror("index is too small!");
    int j = 0;
    node *p = head;
    while (j < i && p)
    {
        j++;
        p = p->next;
    }
    if (!p)
        throw throwerror("index is too large!");
    return p->data;
}

template <class elemType>
void linklist<elemType>::insert(int i, const elemType &e)
{
    if (i < 1)
        throw throwerror("index is too small!");
    int j = 1;
    node *p = head;
    while (j < i && p)
    {
        j++;
        p = p->next;
    }
    if (!p->next)
    {
        if (j == i)
        {
            p->next = new node(e);
            return;
        }
        else
            throw throwerror("index is too large!");
    }
    p->next = new node(e, p->next);
}

template <class elemType>
void linklist<elemType>::remove(int i)
{
    if (i < 1)
        throw throwerror("index is too small!");
    int j = 0;
    node *p = head;
    while (j < i && p)
    {
        j++;
        p = p->next;
    }
    if (!p)
        throw throwerror("index is too large!");
    node *q = p;
    p = p->next;
    delete q;
}

template <class elemType>
void linklist<elemType>::reserve()
{
    if (!head->next || !head->next->next)
        return;
    node *p = head->next, *q = p->next;
    while (!q)
    {
        p->next = q->next;
        q->next = head->next;
        head->next = q;
        q = p->next;
    }
}

template <class elemType>
void linklist<elemType>::clear()
{
    if (!head->next)
        return;
    node *p = head->next;
    if (!p->next)
    {
        delete p;
        return;
    }
    node *q = p->next;
    while (!q)
    {
        delete p;
        p = q;
        q = p->next;
    }
    delete p;
    return;
}