#include "include/seqlist.h"
#include <iostream>

using namespace std;

int main(){
    seqlist<int> list1(20);
    for(int i=1;i<3;++i){
        int x;
        cin>>x;
        list1.insert(i,x);
    }
    try
    {
        for(int i=1;i<5;++i){

        cout<<list1[i]<<endl;
    }
    }
    catch(throwInfo ex)
    {
        cout<<ex.what()<<endl;
    }
    return 0;
}