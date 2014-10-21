#include <iostream> 
using namespace std; 

struct MyString{
    char chars[100];
    int length;
};


int main() { 
    MyString str;
    str.length=0;
    cout << "Hello! Please input string S first>>";
    char tmp;
    bool jump=false;
    while(scanf("%c" , &tmp) && !jump){
        if(tmp=='\n'){
            str.chars[str.length]='\0';
            jump=true;
        }else{
            str.chars[str.length] = tmp;
            str.length++;
        }
    }
    cout << str.chars;
    return 0; 
}
