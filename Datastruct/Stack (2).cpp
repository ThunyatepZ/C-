#include <iostream>
using namespace std;
class Stack{
    public:
        int Array[5];
        int top = 0;
        Stack(){Array[0] = 4;}
        bool empty(){//มีไว้เช็คว่าว่างมั้ย
            if(top==0){
                return true;
            }
            else{
                return false;
            }
        }
        bool full(){
            if(top == Array[0]){
                return true;
            }
            else{
                return false;
            }
        }
        void push(int data){
            if(!full()){
                top++;

                Array[top] = data;
            }
        }
        int pop(){
            if(!empty()){
                int temp = Array[top];
                top--;
                return temp;
            }
            return -1;
        }
        void print(){
            cout<<"Stack: ";
            for(int i =1;i <=top;i++){
                cout<<Array[i]<<" ";
            }
            cout<<endl;
        }
};
int main(){
    Stack s1;
    string str;
    cin>>str;
    for(int i = 0;i<100;i++){

        if(str[i] == '('){
            s1.push(str[i]);
        }
        else if(str[i] == ')'){
            if(s1.empty()){
                cout<<"Error";
                return 0;
            }
            if (s1.empty() == false){
                s1.pop();
                continue;
            }
        }

 
    }
    if(s1.empty()){
        cout<<"Pass";
  
    }
    else if(s1.empty() == false){
        cout<<"Error";
    
    }
    
}