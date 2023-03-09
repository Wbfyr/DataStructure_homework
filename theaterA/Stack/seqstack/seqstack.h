#ifndef SEQSTACK
#define SEQSTACK

template <class elemType>
class seqstack
{
private:
    elemType *array;
    int Top;
    int maxSize;
    void doubleSpace();

public:
    seqstack(int initSize = 10);
    bool isEmpty();
    bool isFull();
    elemType top() { return array[Top]; };
    void push(const elemType &e);
    void pop();
    ~seqstack();
};

template <class elemType>
seqstack<elemType>::seqstack(int initSize)
{
    maxSize = initSize;
    array = new elemType[initSize];
    Top = -1;
}

template <class elemType>
bool seqstack<elemType>::isEmpty()
{
    if (Top == -1)
        return true;
    else
        return false;
}

template <class elemType>
bool seqstack<elemType>::isFull()
{
    if (Top == maxSize - 1)
        return true;
    else
        return false;
}

template <class elemType>
void seqstack<elemType>::doubleSpace()
{
    elemType *p = new elemType[2 * maxSize];
    while (Top >= 0)
    {
        p[Top] = array[Top];
        Top--;
    }
    Top = maxSize - 1;
    maxSize = 2 * maxSize;
    delete[] array;
    array = p;
}

template <class elemType>
void seqstack<elemType>::push(const elemType &e)
{
    if (isFull())
        doubleSpace();
    Top++;
    array[Top] = e;
}

template <class elemType>
void seqstack<elemType>::pop()
{
    // if (isEmpty)
    //     throw popEmpty();
    Top--;
}

template <class elemType>
seqstack<elemType>::~seqstack()
{
    delete[] array;
}

#endif