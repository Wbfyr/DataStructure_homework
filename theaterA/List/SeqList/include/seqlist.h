#ifndef SEQLIST
#define SEQLIST

#include<iostream>
#include "throwInfo.h"
using namespace std;

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
    //删除,i为删除的位置
    void _delete(int i);
    //查找，查找元素是否被包含，如果是，返回下标，若否，返回0
    int find(const elemType &e) const;
    int lenth(){return len;}
    

    elemType &operator[](int i){
        if(i<1||i>len) throw throwInfo();
        return elem[i];
    }
    friend ostream &operator << (ostream &os,const elemType &e){
         os<<e;
         return os;
    }

    ~seqlist(){
        delete[] elem;
    };
};


template<class elemType>
void seqlist<elemType>::doublespace(){
        size=size*2-1;
        maxSize*=2;
        elemType *temp=new elemType[size];
        for(int i=1;i<size;++i)
            temp[i]=elem[i];
            delete [] elem;
            elem=temp;
    }

template<class elemType>
void seqlist<elemType>::insert(int i,const elemType &e){
    if(i<1||i>size) throw "error index";
    if(len==maxSize) doublespace();
    for(int j=len;j>=i;j--){
        elem[j+1]=elem[j];
    }
    elem[i]=e;
    len++;
}

template<class elemType>
void seqlist<elemType>::_delete(int i){
    if(i<1||i>size) throw "error index";
    for(int j=i;j<len;++j) elem[j]=elem[j+1];
    len--;
}

template<class elemType>
int seqlist<elemType>::find(const elemType &e)const{
    elem[0]=e;
    for(int i=1;i<=len;++i){
        if(elem[0]==elem[i]) return i;
    }
    return 0;
}




#endif