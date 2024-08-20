#include <iostream>
using namespace std;

class Stack{
    public:
    string Array[10];
    int top = 0;
    bool full(){
        if(top == 0){
            return 1;
        }
        else{
            return 0;
        }
    }
    bool empty(){
        if(top == 9){
            return 1;
        }
        else{
            return 0;
        }
    }
    void push(char a){
        if(!full()){
            top++;
            Array[top] = a;
        }
        
    }
    void pop(){
        if(!empty()){
            top--;
        }
        
    }

    void printstack(){
        for(int i = 1;i<=top;i++){
            cout<<Array[i]<<" ";
        }
    }

};

int main(){
    Stack s;
    string a;
    getline(cin,a);
    s.push(a[0]);
}