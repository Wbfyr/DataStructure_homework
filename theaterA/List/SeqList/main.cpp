#include "include/seqlist.h"
#include <iostream>

using namespace std;

int main(){
    seqlist<int> list1(20),list2(20),list3(20);
    freopen("test.txt","r",stdin);
    for(int i=1;i<25;++i){
        int x;
        cin>>x;
        list1.insert(i,x);
    }
    for(int i=1;i<5;++i){
        int x;
        cin>>x;
        list2.insert(i,x);
    }
    if(list2.find(165)){
        list2._delete(list2.find(165));
    }
    try
    {
        for(int i=1;i<15;++i){

        cout<<list1[i]<<endl;
    }
    cout<<endl;
    }
    catch(throwInfo ex)
    {
        cout<<ex.what()<<endl;
    }
    try
    {
        for(int i=1;i<20;++i){

        cout<<list2[i]<<endl;
    }
    }
    catch(throwInfo ex)
    {
        cout<<ex.what()<<endl;
    }
    return 0;
}