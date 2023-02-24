//队列之顺序表的实现
#include"seqlist.h"

template<class elemType>
void seqlist<elemType>::doublespace(){
        size=size*2-1;
        maxSize*=2;
        elemType *temp=new elemType[size];
        for(int i=1;i<size;++i){
            temp[i]=elem[i];
            delete [] elem;
            elem=temp;
        }
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
void seqlist<elemType>::_delete(int i,const elemType &e){
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