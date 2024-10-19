#include <iostream>
using namespace std;
class heap{
    public:
    int heaptree[1000];
    void insert(int data){
        heaptree[0] += 1;
        heaptree[heaptree[0]] = data;
        int i = heaptree[i];
        while(i > 1 && heaptree[i/2] < heaptree[i]){
            int temp = heaptree[i/2];
            heaptree[i/2] = heaptree[i];
            heaptree[i] = temp;
            i /= 2;
        }
    }

    void deleteheap(){
        int temp = heaptree[1];
        heaptree[1] = heaptree[heaptree[0]];
        heaptree[0] = heaptree[0] - 1;
        int p = 1;
        while(p <= heaptree[0]){
            int l = p * 2;
            int r = (p*2) + 1;
            if(l <= heaptree[0] && heaptree[l] > heaptree[p] && heaptree[l] >= heaptree [r]){
                int temp1 = heaptree[l];
                heaptree[l] = heaptree[p];
                heaptree[p] = temp1;
                p = l;
            }
            else if(r <= heaptree[0] && heaptree[r] > heaptree[p] && heaptree[r] > heaptree[l]){
                int temp1 = heaptree[r];
                heaptree[r] = heaptree[p];
                heaptree[p] = temp1;
                p = r;
            }
            else{
                break;
            }
        }
        cout<<temp<<endl;
    }

    
};