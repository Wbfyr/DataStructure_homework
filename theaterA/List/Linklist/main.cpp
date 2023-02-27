
#include"linklist.cpp"

int main(){

    linklist<int> list1,list2;


    if(list1.isEmpty()) cout<<"list1 is empty"<<endl;
    if(!list2.isFull()) cout<<"list2 is not full"<<endl;


    freopen("test1.txt","r",stdin);
    int x;
    for(int i=0;;++i){
        cin>>x;
        list1.insert(1,x);
    }
    freopen("test2.txt","r",stdin);
    for(int i=0;;++i){
        cin>>x;
        list2.insert(1,x);
    }


    try{
        for(int i=1;;){
            if(!list2.find(list1.get(i))) list2.remove(i);
            else ++i;
        }
    }
    catch(throwerror ex){
        cout<<ex.whatError()<<endl;
        list2.reserve();
    }
    try{
        for(int i=1;;++i){
        cout<<list2.get(i)<<endl;
    }
    }
    catch(throwerror ex){
        cout<<"over"<<endl;
    }

    return 0;
}