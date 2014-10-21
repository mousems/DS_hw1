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

//============MyString=========
class MyString{
    private:
        int length;
        char C[100];
    public:
        MyString(); 
        void debug();
        char* varC();
        void dump();
        void set(char *CC);
        void push(char CC);
        int getLength();
        char* getString();
        int find(MyString subject);

};
MyString::MyString(void){
    length=0;
}
void MyString::debug(){
    printf("length:%d\n" ,length);
    dump();
}
char* MyString::varC(){
    return C;
}
void MyString::dump(){
    for(int i=0; i<length; i++){
        printf("%c",C[i]);
    }
    printf("\n");
}

void MyString::push(char CC){
    C[length]=CC;
    length++;
}
int MyString::getLength(){
    return length;
}
char* MyString::getString(){
    char *tmp;
    tmp=C;
    tmp[length]='\n';
    return tmp;
}
int MyString::find(MyString subject) { // return found index , -1 means not found.
    int subi=0; //substring index 
    bool found=false;
    char *subjectC=subject.varC();
    for(int stri=0; stri< this->getLength(); stri++){
        //scan every entry of C;
        if(found==true && subi==subject.getLength()){
            return stri-subject.getLength();
        }else{
            if(C[stri]==subjectC[subi]){
                found=true;
                subi++;
            }else{
                found=false;
                subi=0;
            }
        }
    }



    return -1;
}
//==========MyString========
int main() { 
    MyString str;
    cout << "Hello! Please input string S first>>";
    char tmp;
    while(scanf("%c" , &tmp)){
        if(tmp=='\n'){
            break;
        }else{
            str.push(tmp);
        }
    }
    
    
    cout << "Please input string str which will find in S>>";    
    MyString tofind;
    while(scanf("%c" , &tmp)){
        if(tmp=='\n'){
            break;
        }else{
            tofind.push(tmp);
        }
    }
    printf("%d" , str.find(tofind));
    return 0; 
}
