#include <iostream>
#include <cstring>
using namespace std;
class Stack{
    public:
        string Array[10];
        int top = 0;
        Stack(){Array[0] = 9;}
        bool empty(){//มีไว้เช็คว่าว่างมั้ย
            if(top==0){
                return true;
            }
            else{
                return false;
            }
        }
        bool full(){
            if(top == 9){
                return true;
            }
            else{
                return false;
            }
        }
        void push(char data){
            if(!full()){
                top++;
                Array[top] = data;
            }
        }
        int pop(){
            if(!empty()){
                
                
                top--;
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
    int Error;
    Stack s;
    string awa;
    getline(cin,awa);
    for(int i = 0;i < 25;i++){
        if(awa[i] == '<'){
            s.push(awa[i]);
        }
        if(awa[i] == '>'){
            
            if(s.empty()){
                cout<<"Error";
                return 0;
            }
            s.pop();
        }
        else{
            
        }

    }
    if(s.empty()){
        cout<<"Pass";
    }
    else{
        cout<<"Error";
    }
}