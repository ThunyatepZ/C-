#include <iostream>
using namespace std;
class keepprocess{
    public:
    int id,processin,processout;
    keepprocess(){}
    keepprocess(int data,int IN,int OUT){
        this->id = data;
        this->processin = IN;
        this->processout = OUT;
    }
};

class queue{
    public:
    int fornt = 1,rear = 0;
    keepprocess *arr;
    int sizeOF;
    queue(int size){
        this->sizeOF = size;
        arr = new keepprocess[size];
    }

    void enqueue(keepprocess data1){
        if(rear != sizeOF){
            arr[++rear] = data1;
        }
    }

    keepprocess dequeue(){
        if(!empty()){
            return arr[fornt++];
        }
        return keepprocess();
    }

    bool empty(){
        if(rear < fornt){
            return 1;
        }
        else{
            return 0;
        }
    }
};

int main(){
    int timeAll = 0;
    int size101;
    cin>>size101;
    keepprocess p[size101];
    queue *q = new queue(size101);
    int d,in,o;
    for(int i = 0; i < size101;i++){
        cin>>d;
        cin>>in;
        cin>>o;
        p[i] = keepprocess(d,in,o);
        timeAll+=o;
    }

for(int i=0; i < size101 ;i++){
		keepprocess temp;
		for(int j=i;j>0;j--){
			if (p[j].processin < p[j-1].processin){
				temp = p[j];
			    p[j] = p[j-1];
				p[j-1] = temp;
			}
		}

	}
	
	int timeReal = 0;
	while(timeReal < timeAll){
        for(int i = 0 ;i < size101;i++){
            if(p[i].processin <= timeReal && p[i].processin != -1){
                q->enqueue(p[i]);
                p[i].processin = -1;
            }
        }

        while(!q->empty()){
            keepprocess temp = q->dequeue();
            for(int i = temp.processout;i > 0;i--){
                cout<<temp.id<<" "<<temp.processout<<endl;
                temp.processout--;
                timeReal++;
            }
        }
    }

	
}