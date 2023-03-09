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
    char str = ch[i];
    while (str != '\0')
    {
        if (str == '(' || str == '{' || str == '[')
            s1.push(str);
        else if (str == ')' || str == '}' || str == ']')
        {
            switch (str)
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
        str = ch[i + 1];
    }
    if (s1.isEmpty())
        cout << "everything is fine!";
    else
        cout << "something goes wrong";
    return 0;
}