#include<iostream>
using namespace std;
class queue{
    public:
    int Array[7];
    int rear = 0;
    int fornt = 0;
    int size = 5;
    bool queuefull(){
        if(rear >= size){
            return true;
        }
        else{
            return false;
        }
    }

    bool queueEmpty(){
        if(rear == 0 && fornt == 0){
            return true;
        }
        else{
            return false;
        }
    }
    
    void enqueue(int data){
        if(!queuefull()){
            
            Array[rear] = data;
            rear++;
        }
        else{
            rear = rear + 1;
            int temp = (rear-1) % size;
            
            //cout<<temp<<" ";
            Array[temp] = data;
        }
                
    }
    int dequeue(){
        if(!queueEmpty()){
            int temp = Array[fornt];
            fornt++;
            return temp;
        }
        return -1;
    }
    void printqueue(){
        if(rear < size){
            for(int i = fornt;i < rear;i++){
            cout<<Array[i]<<" ";
        }cout<<endl;
        }
        else{
            for(int i = fornt;i < size;i++){
            cout<<Array[i]<<" ";
        }cout<<endl;
        }
        
    }
};

int main(){
    queue q;
    int i;
    char c;
    while(true){
        
    
    cin>>c;
    if(c == 'e'){
        cin>>i;
        q.enqueue(i);
        q.printqueue();
    }
    }



}