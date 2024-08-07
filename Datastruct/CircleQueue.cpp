#include <iostream>
using namespace std;

class Queue{
    public:
    int array[15];
    int full = 13;
    int fornt = 1;
    int rear = 0;

    void enqueue(int data){
        rear++;
        array[rear] = data;
        
    }
    int dequeue(){
        fornt++;
        
        return array[fornt];
    }
    void print(){
        for(int i = fornt;i <= rear;i++){
            cout<<array[i]<<" ";
        }
    }
};

int main(){
    Queue A;
    A.enqueue(10);
    A.enqueue(20);
    A.enqueue(30);
    A.enqueue(40);
    A.print();

}