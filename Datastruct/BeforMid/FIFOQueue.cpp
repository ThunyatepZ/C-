#include <iostream>
using namespace std;

class Queue{
    public:
    string Array[20];
    int rear = 0;
    int fornt = 1;
    int size = 18;
    void enqueue(char a){
        rear++;
        Array[rear] = a;
    }
    void dequeue(){
        fornt++;
    }
    void print(){
        for(int i = fornt; i <= rear;i++){
            cout<<Array[i]<<" ";
        }
    }
};

int main(){
    Queue q;
    char ch;
    int round;
    cin>>ch>>round;
    for(int i = 0;i<round;i++){
        q.enqueue(ch);
    }
    q.print();
}