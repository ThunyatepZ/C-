#include  <iostream>
#include <vector>
using namespace std;
class Graph{
    public:
    int edges[100][100];
    int size;

    Graph(int size){
        this->size = size;
        for(int i = 0;i < this->size;i++){
            for(int j = 0;j < this->size;j++){
                edges[i][j] = 0;
            }
        }
    }

    void add(int x,int y,int weight){
        edges[x][y] = weight;
    }

    void BFT(int start){
        bool visBFT[100];
        for(int i = 0 ; i < 100;i++){
            visBFT[i] = 0;
        }
        visBFT[start] = 1;
        vector<int> q;
        q.push_back(start);
        while(q.empty() == 0){
            start = q.front();
            cout<<start<< " ";
            q.erase(q.begin());
            for(int i = 0 ; i < size;i++){
                if(visBFT[i] == 0 && edges[start][i] > 0){
                    visBFT[i] = 1;
                    q.push_back(i);
                }
            }
        }
    }
    bool visDFT[100];
    void sub_DFT(int start){
        cout<<start<< " ";
        visDFT[start] = 1;
        for(int i = 0;i < size;i++){
            if(visDFT[i] == 0 && edges[start][i] > 0){
                sub_DFT(i);
            }
        }
    }
    void DFT(int start){
        for(int i =0;i < 100;i++){
            visDFT[i] = 0;
        }
        sub_DFT(start);
    }
};

int main(){
    Graph g(5);
    g.add(0,1,1);
    g.add(1,0,1);
    g.add(1,2,1);
    g.add(2,1,1);
    g.add(2,3,1);
    g.add(3,2,1);
    g.add(3,4,1);
    g.add(0,2,1);
    g.add(2,0,1);
    g.BFT(3);
    

}