// 计算表达式(仅转换的部分)
#include <cstring>
#include "linkstack.h"

int main()
{
    void inToSufForm(char *);
    char str[80];
    freopen("stacktest2.txt", "r", stdin);
    int i = 0, j = 0;
    while (cin >> str[i])
    {
        i++;
    }
    inToSufForm(str);
    i = 0;
    while (str[i] != '\0')
    {
        cout << str[i];
        i++;
    }
    return 0;
}

// 中缀转后缀
void inToSufForm(char *str)
{
    char *strc = new char[strlen(str)];
    int i = 0, j = 0;
    linkstack<char> stack;
    stack.push('#');
    char ch = str[j];
    while (ch != '\0')
    {
        if (ch <= '9' && ch >= '0')
        {
            strc[i] = ch;
            ++i;
            ++j;
            ch = str[j];
            continue;
        }
        switch (ch)
        {
        case '(':
            stack.push('(');
            break;
        case ')':
            while (stack.top() != '(')
            {
                strc[i] = stack.top();
                stack.pop();
                i++;
            }
            stack.pop();
            break;
        case '*':
        case '/':
            while (stack.top() == '*' || stack.top() == '/')
            {
                strc[i] = stack.top();
                stack.pop();
                i++;
            }
            stack.push(ch);
            break;
        case '+':
        case '-':
            while (stack.top() != '#' && stack.top() != '(')
            {
                strc[i] = stack.top();
                stack.pop();
                i++;
            }
            stack.push(ch);
            break;
        }
        j++;
        ch = str[j];
    }
    while (stack.top() != '#')
    {
        strc[i] = stack.top();
        stack.pop();
        i++;
    }
    strc[i + 1] = '\0';
    strcpy(str, strc);
}