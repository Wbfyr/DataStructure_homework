#ifndef THROWERROR
#define THROEERROR

#include<string>
using namespace std;

class throwerror
{
private:
    string massege;
public:
    throwerror(string s):massege(s){};
    string whatError(){return massege;};
};

#endif