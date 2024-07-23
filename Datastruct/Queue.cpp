#include <iostream>
using namespace std;
/*class Stack{
    public:
        int array[10];
        int top = 0;
        Stack(){array[0] == 9;}
        void push(int x){
            top++;
            array[top] == x;
        }
        int pop(){
            int temp = array[top];
            top--;
            return temp;
        }
}*/
class Queue{
    public:
        int array[10];
        int size = 8;
        int rear = 0;
        int fornt = 1;
        bool full(){
            if(rear == size){
                return 1;
            }
            else{return 0;}
        }
        bool empty(){
            if(rear < fornt){
                return 1;
            }
            else{
                return 0;
            }
        }
        void enqueue(int n){
            if(!full()){
            rear++;
            array[rear] = n;
            }
        }
        void dequeue(){
            if(!empty()){
            int temp = array[fornt];
            fornt++;
            cout<<temp<<endl;
            }
        }
        void showQueue(){
            for(int i=fornt;i<=rear;i++){
                cout<<array[i]<<" ";
            }
            cout<<endl;
        }
};
int main(){
    Queue Q;
    while(true){
        char text;
        int num;
        cin>>text;
        if(text == 'e'){
            cin>>num;
            Q.enqueue(num);
        }
        else if(text == 'd'){
            Q.dequeue();
        }
        else if(text == 'p'){
            Q.showQueue();
        }
        else if(text == 'n'){
            cout<<Q.rear<<endl;
        }
        else if(text == 's'){
            cout<<Q.array[Q.fornt]<<" "<<Q.array[Q.rear]<<endl;
        }
        else if(text == 'x'){
            break;
        }
    }
    

}