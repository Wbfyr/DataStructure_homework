#ifndef THROWINFO
#define THROWINFO

class throwInfo
{
private:
   const char *message;
public:
    throwInfo():message("error index"){};
    const char* what(){return message;}
};

#endif