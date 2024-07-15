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
                cout<<top;
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

}