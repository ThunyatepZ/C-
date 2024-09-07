#include <iostream>
#include <queue>
#include <algorithm>
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

bool compartsort(Keepprocess a,Keepprocess b){
    if(a.processin < b.processin){
        return 1;
    }
    else{
        return 0;
    }
    
}

int main(){
    int SIZE;
    int qq;
    int Timecheck = 0,TimeALL = 0;
    cin>>SIZE;
    cin>>qq;
    Keepprocess p[SIZE];
    queue<Keepprocess> q;
    int id,time,timeout;
    
    for(int i = 0;i < SIZE;i++){
        cin>>id;
        cin>>time;
        cin>>timeout;
        p[i] = Keepprocess(id,time,timeout);
        TimeALL+= timeout;
    }
    sort(p,p+SIZE,compartsort);
    
    int i = 0;
    q.push(p[i]);
    i++;

    while(Timecheck < TimeALL){
        if(!q.empty()){
            Keepprocess temp = q.front();
            q.pop();
            for(int j = 0;j < qq;j++){
                cout<<temp.id<<" : "<<temp.processout<<endl;
                temp.processout--;
                Timecheck++;
            }

            while(i < SIZE && p[i].processin <= Timecheck){
                q.push(p[i]);
                i++;
            }

            if(temp.processout > 0){
                q.push(temp);
            }
        }
    }
}

