#include <iostream>
#include <vector>
using namespace std;
class Graph{
	public:
		int edges[100][100];
		int s_v;
		Graph(int n){
			s_v = n;
			for(int i = 0;i < s_v;i++){
				for(int j = 0;j < s_v;j++){
					edges[i][j] = 0;
				}
			}
		}
		void add_edges(int x,int y,int w){
			edges[x][y] = w;
		}
		void print(){
			for(int i = 0; i < s_v;i++){
				cout<<i<<" : ";
				for(int j = 0;j < s_v;j++){
					if(edges[i][j] > 0){
						cout<<j<<","<<edges[i][j]<<" ";
					}
				}
				cout<<endl;
			}
		}
		
		void BTF(int st){
			bool visited_BTF[100];
			for(int i = 0;i < 100;i++){
				visited_BTF[i] = 0;
			}
			visited_BTF[st] = 1;
			vector<int> q;
			q.push_back(st);
			while(q.empty() == 0){
				st = q.front();
				cout<< st << " ";
				q.erase(q.begin());
				for(int y = 0; y < s_v;y++){
					if(visited_BTF[y] == 0 && edges[st][y] > 0){
						visited_BTF[y] = 1;
						q.push_back(y);
					}
				}
			}
		}
		bool visited_DFT[100];
		void sub_dft(int start){
			cout<<start<<" ";
			visited_DFT[start] = 1;
			for(int y = 0;y < s_v;y++){
				if(visited_DFT[y] == 0 && edges[start][y] > 0){
					sub_dft(y);
				}
			}
		}
		
		void dft(int start){
			for(int i = 0;i < 100;i++){
				visited_DFT[i] = 0;
			}
			sub_dft(start);
		}
};

int main(){
	int n;
	cin >> n;
    Graph g(n);
    char text;
    while(text != 'q'){
    	cin>>text;
        if(text == 'e'){
    	int row,col,we;
			cin>>row>>col>>we;
			g.add_edges(row,col,we);
		}
		else if(text == 'd'){
			int data;
			cin >> data;
			g.dft(data);
			cout<<endl;
		}
		else if(text == 'b'){
			int data;
			cin >> data;
			g.BTF(data);
			cout<<endl;
		}
		else if(text == 'q'){
			break;
		}
	}

}
