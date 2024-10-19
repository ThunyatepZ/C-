#include <iostream>
using namespace std;

class Queue{
    public:
    int arr[5];
    int size = 5;
    int rear = -1;
    int fornt = 0;

    bool full(){
        if(rear - fornt >= size-1){
            return 1;
        }
        else{
            return 0;
        }
    }

    bool empty(){
        if(fornt > rear){
            return 1;
        }
        else{
            return 0;
        }
    }

    void enqueue(int data){
        if(!full()){
            rear++;
            arr[rear % size] = data;
        }
    }

    void dequeue(){
        if(!empty()){
            fornt++;
        }
        
    }

    void print(){
        for(int i = fornt; i <= rear;i++){
            cout<<arr[i % size]<<" ";
        }
    }
};

int main(){
    Queue q;
    char c;
    int data;
    while(1){
        cin>>c;
        if(c=='e'){
            cin>>data;
            q.enqueue(data);
            q.print();
        }
        else if(c == 'd'){
            q.dequeue();
            q.print();
        }
    }
    
}