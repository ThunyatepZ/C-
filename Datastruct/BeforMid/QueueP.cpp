#include <iostream>
using namespace std;

class Queue{
    public:
    
        int arr[3];
        int tail = -1;
        int head = 0;
        int size = 3;
    bool full(){
        if(tail == size){
            return 1;
        }
        else{
            return 0;
        }
            
    }

    void push(int n){

        if(tail-head < size-1){
            arr[++tail] = n;
        }
        else{
            arr[++tail % size] = n;     
        }

        
    }  
    
    void pop(){

            (++head) % size;

        
    }
    void print(){
        for(int i = head; i <= tail;i++){
            cout<<arr[i]<<" ";
        }
    }
};

int main(){
    Queue a;
    char c;
    int d;
    while(true){
        cin>>c;
        if(c=='e'){
            cin>>d;
            a.push(d);
            a.print();
        }
        else if(c == 'd'){
            a.pop();
            a.print();
        }
    }
}