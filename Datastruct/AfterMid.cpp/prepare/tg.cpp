#include <iostream>
#include <vector>
using namespace std;

class graph{
    public:
    int edges[100][100];
    int size;
    graph(int n){
        size = n;
        for(int i = 0;i < size;i++){
            for(int j = 0;j < size;j++){
                edges[i][j] = 0;
            }
        }
    }
    void addedges(int x,int y,int w){
        edges[x][y] = w;
    }

    void BFT(int start){
        bool visBFT[100];
        for(int i = 0;i < 100;i++){
            visBFT[i] = 0;
        }
        visBFT[start] = 1;
        vector<int> q;
        q.push_back(start);
        while(q.empty() == 0){
            start = q.front();
            cout<<start;
            q.erase(q.begin());
            for(int i = 0;i < size;i++){
                if(visBFT[i] == 0 && edges[start][i] > 0){
                    visBFT[i] = 1;
                    q.push_back(i);
                }
            }
        }
    }

};