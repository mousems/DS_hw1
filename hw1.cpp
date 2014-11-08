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
        void clean();
        char* varC();
        void dump();
        void set(char *CC);
        void push(char CC);
        int getLength();
        char* getString();
        int find(MyString subject , int Start);
        void removeAt(int index , int length);
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
void MyString::clean(){
    for (int i = 0; i < 100; ++i){
        C[i]='\0';
    }
    length=0;
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
int MyString::find(MyString subject ,int start) { // return found index , -1 means not found.
    int subi=0; //substring index 
    bool found=false;
    char *subjectC=subject.varC();

    for(int stri=start; stri< this->getLength(); stri++){
        //scan every entry of C;
        if(found==true && subi==subject.getLength()){
            return stri-subject.getLength();
            // intStack.push(stri-subject.getLength());
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
void MyString::removeAt(int index , int replength){
    char newS[100];
    int newLength;
    newLength = 0;
    for(int i=0 ; i<index ; i++){
        newS[newLength] = C[i];
        newLength ++;
    }
    for(int i=index+replength ; i<length ; i++){
        newS[newLength] = C[i];
        newLength ++;
    }
    this->clean();
    for (int i = 0; i < newLength; i++)
    {
        
        this->push(newS[i]);
    }
}  

//==========MyString========
int main() { 


    MyString S;
    cout << "Hello! Please input string S first>>";
    char tmp;
    while(scanf("%c" , &tmp)){
        if(tmp=='\n'){
            bre;
        }else{
            S.push(tmp);
        }
    }
    
    
    cout << "(1) Frequency , (2) CharacterDelete , (3) Replacement , (other) for Bre >>";

    char tmp2;
    scanf("%c" , &tmp);
    scanf("%c" , &tmp2);
    if (tmp=='1'){
        cout << "Please input string str which will find in S>>";    
        MyString str;
        while(scanf("%c" , &tmp)){
            if(tmp=='\n'){
                bre;
            }else{
                str.push(tmp);
            }
        }

        int start , retr , count;
        start = 0;
        count = -1;
        retr = 0;
        while(retr != -1){
            retr = S.find(str,start);
            start = retr+1;
            count++;
        }




        printf("Total occurrences : %d\n" , count);
    }else if(tmp=='2'){

        cout << "Please input string str which will find in S>>";    
        MyString str;
        while(scanf("%c" , &tmp)){
            if(tmp=='\n'){
                bre;
            }else{
                str.push(tmp);
            }
        }

        int start , retr , count;
        start = 0;
        retr = 0;
        count = 0;
        intStack intStack;
        while(retr != -1){
            retr = S.find(str,start);
            start = retr+1;
            if (retr != -1){
                intStack.push(retr);
                count++;
            }
        }

        for (int i = 0; i < count; i++){
            S.removeAt(intStack.pop() , str.getLength());
        }
        cout << S.getString();
        cout << "\n";
    }else if(tmp=='3'){


    }

    




    
    return 0; 
}



