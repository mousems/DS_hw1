#include <iostream> 
using namespace std; 

//============implete a int Stack.==========
class intStack{
    private:
        int num[100];
        int length;
    public:
        void push(int i);
        int pop();
        intStack();
};

intStack::intStack(void){
    length=0;
}

void intStack::push(int i){
    if(length==100){
        cout << "intStack is full.\n";
    }else{
        num[length]=i;
        length++;
    }
}
int intStack::pop (){
    if(length==0){
        cout << "intStack is empty.\n";
        return -1;
    }
    return num[--length];
}
//============implete a int Stack.==========

/*
   class MyString{
   private:
   char C[100];
   int length=0;

   public:
   int getLength(){
   return length;
   }
   char getString(){
   char tmp[101];
   tmp=C;
   tmp[length]='\n';
   return tmp;
   }
   int find(char *subject) {// return found index , -1 means not found.

   }
   }

*/
int main() { 
    /*
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
       */
    return 0; 
}
