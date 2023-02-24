//队列之顺序表的头文件
#ifndef SEQLIST
#define SEQLIST
#include<string>
#include "throwInfo.h"

template<class elemType>
class seqlist
{
private:
    int size,maxSize,len;
    elemType* elem;
public:
    seqlist(int a):size(a+1),maxSize(size-1),len(0){
        elem=new elemType[size];
    };


    //拓展空间为双倍
    void doublespace();
    //插入,i为插入的位置，e是插入的元素
    void insert(int i,const elemType &e);
    //删除,i为删除的位置，e是删除的元素
    void _delete(int i,const elemType &e);
    //查找，查找元素是否被包含，如果是，返回下标，若否，返回0
    int find(const elemType &e) const;
    int lenth(){return len;}
    

    elemType &operator[](int i){
        if(i<1||i>len) throw throwInfo();
        return elem[i];
    }
    // ostream &operator << (ostream &os,cons)

    ~seqlist(){
        delete[] elem;
    };
};





#endif