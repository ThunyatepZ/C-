#include<iostream>
using namespace std;
class queue{
    public:
    int Array[5];
    int rear = -1;
    int fornt = 0;
    int size = 5;
    void push(int i){
        if(rear-fornt <= size-1){
            Array[++rear % size] = i;
        }
        else{
            Array[++rear % size] = i;
        }
    }
    
    void pop(){
        if(fornt<=rear){
            fornt++;
            Array[fornt];
            
        }
    }
    
    void print(){
        for(int i = fornt;i < size;i++){
            cout<<Array[i]<<" ";
        }
        
    }
    
};

int main(){
    queue q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    q.push(6);
    q.push(7);
    q.push(8);
    q.push(9);
    q.push(10);
    q.pop();
    q.push(11);
    q.print();
}

