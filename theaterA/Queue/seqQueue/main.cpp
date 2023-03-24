#include "seqQueue.h"

int main()
{
    seqQueue<int> q(4);
    if (q.isEmpty())
        cout << "seqQueue is empty" << endl;
    int n = 5, input;
    while (n)
    {
        cin >> input;
        q.enQueue(input);
        n--;
    }
    while (!q.isEmpty())
    {
        cout << q.Front() << endl;
        q.deQueue();
    }
    q.deQueue();

    return 0;
}