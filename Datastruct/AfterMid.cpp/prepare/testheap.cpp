#include <iostream>
using namespace std;

class Heap{
    public:
    int heaptree[1000];
    Heap(){
        heaptree[0] = 0;
    }

    void insert(int data){
        heaptree[0] += 1;
        heaptree[heaptree[0]] = data;
        int i = heaptree[0];
        while(i > 1 && heaptree[i/2] < heaptree[i]){
            int temp = heaptree[i/2];
            heaptree[i/2] = heaptree[i];
            heaptree[i] = temp;
            i = i/2;
        }
    }

    void deleteheap(){
        int temp = heaptree[1];
        heaptree[1] = heaptree[heaptree[0]];
        heaptree[heaptree[0]] = temp;
        int ptr = 1;
        while(ptr <= heaptree[0]){
            int l = ptr * 2;
            int r = (ptr*2) + 1;
            if(l <= heaptree[0] && heaptree[l] > heaptree[ptr] && heaptree[l] >= heaptree[r]){
                int keep = heaptree[l];
                heaptree[l] = heaptree[ptr];
                heaptree[ptr] = temp;
                ptr = l;
            }
            else if(r <= heaptree[0] && heaptree[r] > heaptree[ptr] && heaptree[r] > heaptree[l]){
                int keep = heaptree[r];
                heaptree[r] = heaptree[ptr];
                heaptree[ptr] = keep;
                ptr = r;
            }
            else{
                break;
            }
        }
    }

    void print(){
        for(int i = 1;i <= heaptree[0];i++){
            cout<<heaptree[i]<<" ";
        }
        cout<<endl;
    }
};


int main(){
    Heap h;
    h.insert(19);
    h.print();
    h.insert(20);
    h.print();
    h.insert(18);
    h.print();
}