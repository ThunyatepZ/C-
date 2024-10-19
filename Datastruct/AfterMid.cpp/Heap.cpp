#include <iostream>
using namespace std;
class heap{
    public:
    int heaptree[1000];
    heap(){
        heaptree[0] = 0;
    }
    void insert(int data){
        if(heaptree[0] < 999){
            heaptree[0] = heaptree[0]+1;
            heaptree[heaptree[0]] = data;
            int i = heaptree[0];
            while(i > 1 && heaptree[i/2] < heaptree[i]){
                int t = heaptree[i/2];
                heaptree[i/2] = heaptree[i];
                heaptree[i] = t;
                i = i/2;
            }
        }
    }

    void deleteHeap(){
        if(heaptree[0] > 0){
            int temp = heaptree[1];
            heaptree[1] = heaptree[heaptree[0]];
            heaptree[0]= heaptree[0] - 1;
            int p = 1;
            while(p <= heaptree[0]){
                int l = p*2;
                int r = (p*2)+1;
                if(l <= heaptree[0] && heaptree[l] > heaptree[p] && heaptree[l] >= heaptree[r]){
                    int t = heaptree[l];
                    heaptree[l] = heaptree[p];
                    heaptree[p] = t;
                    p = l;
                }
                else if(r <= heaptree[0] && heaptree[r] > heaptree[p] && heaptree[r] > heaptree[l]){
                    int t = heaptree[r];
                    heaptree[r] = heaptree[p];
                    heaptree[p] = t;
                    p = r;
                }
                else{
                    break;
                }
            }
            cout<<temp<<endl;
        }
        else{
        }
        
        
    }


    void print(){
        for(int i = 1;i <= heaptree[0];i++){
            cout<<heaptree[i]<< " ";
        }
        cout<<endl;
    }
};

int main(){
    heap h;
    char c;
    while(true){
        cin>>c;
        if(c == 'a'){
            int data;
            cin>>data;
            h.insert(data);
        }
        else if(c == 'p'){
            h.print();
        }
        else if(c == 'd'){
            h.deleteHeap();
        }
        else if(c == 'e'){
            break;
        }
    }
}