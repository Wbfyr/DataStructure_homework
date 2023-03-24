#ifndef SEQQUEUE
#define SEQQUEUE

#include <iostream>
using namespace std;

template <class elemType>
class seqQueue
{
private:
    elemType *queue;
    int front, rear;
    int maxSize, len;
    void doubleSpace();

public:
    seqQueue(int x = 100);
    bool isEmpty() { return (front == rear) ? true : false; };
    bool isFull()
    {
        if ((front % maxSize) == ((rear + 1) % maxSize))
            return true;
        else
            return false;
    };
    int Length() { return len; }
    elemType &Front() { return queue[front]; }
    void enQueue(const elemType &e);
    void deQueue();
    ~seqQueue() { delete[] queue; };
};

template <class elemType>
seqQueue<elemType>::seqQueue(int x)
{
    maxSize = x;
    len = 0;
    front = 0;
    rear = 0;
    queue = new elemType[maxSize];
}

template <class elemType>
void seqQueue<elemType>::doubleSpace()
{
    elemType *tmp = new elemType[2 * maxSize];
    int i = front, j = i;
    for (; j < rear; ++i, j = i % maxSize)
    {
        tmp[i] = queue[j];
    }
    rear = i;
    delete[] queue;
    queue = tmp;
    maxSize *= 2;
}

template <class elemType>
void seqQueue<elemType>::enQueue(const elemType &e)
{
    if (isFull())
        doubleSpace();
    queue[rear] = e;
    rear = (rear + 1) % maxSize;
    len++;
}

template <class elemType>
void seqQueue<elemType>::deQueue()
{
    if (isEmpty())
    {
        cout << "the queue is empty" << endl;
        return;
    }
    front = (front + 1) % maxSize;
    len--;
}

#endif