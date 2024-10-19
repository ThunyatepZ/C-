#include <iostream>
#include <vector>

using namespace std;
class Graph{
    public:
    int edges[100][100];
    int S;
    Graph(int n){
        S = n;
        for(int i = 0; i < S;i++){
            for(int j = 0; j < S;j++){
                edges[i][j] = 0;
            }
        }
    }
    void add_edges(int x,int y,int z){
        edges[x][y] = z;
    }
    void print(){
        for(int i = 0 ; i <S;i++){
            cout<<i<<" : ";
            for(int j = 0;j < S;j++){
                if(edges[i][j] > 0){
                    cout<<j<<","<<edges[i][j]<<" ";
                }
            }
            cout<<endl;
        }
    }

    void BFT(int s){
        bool visBFT[100];
        for(int i = 0; i < 100;i++){
            visBFT[i] = 0;
        }
        visBFT[s] = 1;
        vector<int> q;
        q.push_back(s);
        while(q.empty() == 0){
            s = q.front();
            cout<< s << " ";
            q.erase(q.begin());
            for(int y = 0; y < S;y++){
                if(visBFT[y] == 0 && edges[s][y] > 0){
                    visBFT[y] = 1;
                    q.push_back(y);
                }
            }
        }
    }


    bool visDFT[100];
    void sub_diff(int start){
        cout<<start<<" ";
        visDFT[start] = 1;
        for(int i = 0;i < S;i++){
            if(visDFT[i] == 0 && edges[start][i] > 0){
                sub_diff(i);
            }
        }
    }

    void DFT(int start){
        for(int i = 0; i < 100;i++){
            visDFT[i] = 0;
        }
        sub_diff(start);
    }
};

int main(){
    Graph g(5);
    g.add_edges(0,1,1);
    g.add_edges(1,0,1);
    g.add_edges(1,2,1);
    g.add_edges(2,1,1);
    g.add_edges(2,3,1);
    g.add_edges(3,2,1);
    g.add_edges(3,4,1);
    g.add_edges(0,2,1);
    g.add_edges(2,0,1);
    g.print();
    g.BFT(2);
}
