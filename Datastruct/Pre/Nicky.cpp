#include <iostream>
#include <stack>
using namespace std;

bool balance(string l){
    stack<char> s;
    
    for(int i=0;i<l.size();i++){
        if(l[i] == '('){
            s.push(l[i]);
        }
        else if(l[i] == ')'){
            if(!s.empty()){
                s.pop();
        }
        else{
            s.push(l[i]);
        }
    }
    }
    
    if(s.empty()) return true;
    else return false;
};

int main(){
    string l;
    cin>>l;
    
    if(balance(l)) cout<<"pass"<<endl;
    else cout<<"error"<<endl;
    
    return 0;
}