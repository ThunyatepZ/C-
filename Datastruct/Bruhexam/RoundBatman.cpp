#include <iostream>
#include <queue>
using namespace std;

class Keepprocess{
    public:
    int id,processin,processout;
    Keepprocess(){}
    Keepprocess(int D,int I,int O){
        id = D;
        processin = I;
        processout = O;
    }
};

class Queue{
    public:
    Keepprocess *arr;
    int size;
    int rear = 0,fornt = 1;
    Queue(int s){
        this->arr = new Keepprocess[s];
        size = s;
    }

    bool full(){
        if(rear == size){
            return 1;
        }
        else{
            return 0;
        }
    }

    bool empty(){
        if(rear < fornt){
            return 1;
        }
        else{
            return 0;
        }
    }

    void enqueue(Keepprocess ProcessForm){
        if(!full()){
            arr[++rear] = ProcessForm;
        }
        
    }

    Keepprocess dequeue(){
        Keepprocess temp;
        if(!empty()){
            return arr[fornt++];
            

        }
        return Keepprocess();
    }
};

int main(){
    int SIZE;
    int Timecheck = 0,TimeALL = 0;
    cin>>SIZE;
    Keepprocess p[SIZE];
    Queue *q = new Queue(SIZE);
    int id,time,timeout;
    
    for(int i = 0;i < SIZE;i++){
        cin>>id;
        cin>>time;
        cin>>timeout;
        p[i] = Keepprocess(id,time,timeout);
        TimeALL+= timeout;
    }


    for(int i = 0;i < SIZE;i++){
        Keepprocess temp;
        for(int j = i; j > 0 ;j--){
            if(p[j].processin < p[j-1].processin){
                temp = p[j];
                p[j] = p[j-1];
                p[j-1] = temp;
            }
            
        }
    }
    
    int TIMEARR = 0;
    while(TIMEARR < TimeALL){
        for(int i = 0; i < SIZE;i++){
            if(p[i].processin <= TIMEARR && p[i].processin != -1){
                q->enqueue(p[i]);
                p[i].processin = -1;
            }
        }
        while(!q->empty()){
            Keepprocess temp = q->dequeue();
            for(int j = temp.processout; j > 0;j--){
                cout<<temp.id<<" : "<<temp.processout;
                temp.processout--;
                TIMEARR++;
            }
        }
    }
}

