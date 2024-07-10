#include <iostream>
using namespace std;
class stack{
    
public:
    int array[10];
    int top = 0;
    stack(){array[0] = 9;}
    bool checkempty(){
        if(top==0){
            return true;
        }
        else{
            return false;
        }
    }
    bool checkfull(){
        if(array[0] == top){
            return true;
        }
        else{return false;}
    }
    void push(int number){
        if(!checkfull()){
            top++;
            array[top] = number;
        }
    }
    int pop(){
        if(!checkempty()){
            int putout = array[top];
            top--;
            return putout;
        }
        return -1;
    }
    void print(){
        cout<<"stack :";
        for(int i = 1;i<=top;i++){
            cout<<array[i]<<" ";
        }
        cout<<endl;
    }

};

int main(){
    stack s1;
    int num;
    cout<<"input number u wanna put in: ";
    cin>>num;
    s1.push(num);
    s1.push(4);
    s1.print();
    s1.pop();
    s1.print();
}