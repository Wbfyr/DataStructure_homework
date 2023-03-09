// 检索括号是否匹配
#include <iostream>
#include "seqstack.h"

using namespace std;

int main()
{
    char ch[80];
    freopen("stacktest.txt", "r", stdin);
    cin.getline(ch, 80);

    seqstack<char> s1(20);
    int i = 0;
    while (ch[i] != '\0')
    {
        if (ch[i] == '(' || ch[i] == '{' || ch[i] == '[')
            s1.push(ch[i]);
        else if (ch[i] == ')' || ch[i] == '}' || ch[i] == ']')
        {
            switch (ch[i])
            {
            case ')':
                if (s1.top() == '(')
                    s1.pop();
                else
                {
                    cout << "incorrect about ()";
                    return 0;
                }
                break;
            case '}':
                if (s1.top() == '{')
                    s1.pop();
                else
                {
                    cout << "incorrect about {}";
                    return 0;
                }
                break;
            case ']':
                if (s1.top() == '[')
                    s1.pop();
                else
                {
                    cout << "incorrect about []";
                    return 0;
                }
                break;
            }
        }
        i++;
    }
    if (s1.isEmpty())
        cout << "everything is fine!";
    else
        cout << "something goes wrong";
    return 0;
}