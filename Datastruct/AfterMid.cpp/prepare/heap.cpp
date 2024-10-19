#include <iostream>
using namespace std;
class heap{
    public:
    int heaptree[1000];
    heap(){
        heaptree[0] = 0;
    }
    void addheap(int data){
        if(heaptree[0] < 999){
            heaptree[0] += 1;
            heaptree[heaptree[0]] = data;
            int sizeHEAP = heaptree[0];
            while(sizeHEAP > 1 && heaptree[sizeHEAP/2] < heaptree[sizeHEAP]){
                int t = heaptree[sizeHEAP/2];
                heaptree[sizeHEAP/2] = heaptree[sizeHEAP];
                heaptree[sizeHEAP] = t;
                sizeHEAP /= 2;
            }
        }
    }

    void deleteheap(){
        if(heaptree[0] > 0){
            int temp = heaptree[1];
            heaptree[1] = heaptree[heaptree[0]];
            heaptree[0] = heaptree[0] - 1;
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
                    int temp = heaptree[r];
                    heaptree[r] = heaptree[p];
                    heaptree[p] = temp;
                    p = r;
                }
                else{
                    break;
                }
            }
            cout<<temp<<endl;
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
    heap *h = new heap;
    char c;
    while(true){
        cin>>c;
        if(c == 'a'){
            int data;
            cin>>data;
            h->addheap(data);
        }
        else if(c == 'd'){
            h->deleteheap();
        }
        else if( c == 's'){
            h->print();
        }
    }
}