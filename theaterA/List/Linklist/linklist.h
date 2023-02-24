//队列之链式表的头文件
#ifndef LINKLIST
#define LINKLIST

#include<iostream>
#include"throwerror.h"
using namespace std;

template<class elemType>
class linklist
{
private:
    class node
    {
        friend class linklist<elemType>;
    private:
        elemType data;
        node *next;
    public:
        node():next(nullptr){};
        node(const elemType &e,node *p=nullptr):data(e),next(p){};
    };

    node *head;
    
public:
    linklist(){head=new node;};

    bool isEmpty(){return head->next;}const;//是否是空表
    bool isFull(){return false;}const;//是否空间已满
    int length()const;//获取长度
    elemType &get(int i)const;//获取元素
    int find(const elemType &e)const;//查找
    void insert(int i,const elemType &e);//插入
    void remove(int i);//删除
    void reserve();//元素就地逆置
    void clear();//清空
    ~linklist(){
    if(head->next) 
    {clear();delete head;}
    else 
        delete head;
    };
};

#endif