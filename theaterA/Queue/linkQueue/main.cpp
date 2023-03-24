#include "linkQueue.h"

int main()
{
    linkQueue<int> q;
    if (q.isEmpty())
        cout << "linkQueue is empty" << endl;
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