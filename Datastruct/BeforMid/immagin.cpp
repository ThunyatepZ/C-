#include <iostream>
#include <stack>
using namespace std;

int checkop(char a){
    if(a == '+' || a == '-'){
        return 1;
    }
    if(a == '*' || a == '/'){
        return 2;
    }
}


int main(){
    string text;
    string ans;
    stack<char> s;
    getline(cin,text);
    for(int i = 0;i < text.length();i++){
        if(text[i] == '('){
            s.push(text[i]);
        }
        else if(text[i] ==')'){
            while(!s.empty()){
                if(s.top() != '('){
                    ans+=s.top();
                    s.pop();
                }
                else{
                    s.pop();
                    break;
                }
            }
        }
        else if(text[i] == '+' ||text[i] == '-' ||text[i] == '*' ||text[i] == '/'){
            while(!s.empty() && checkop(text[i]) <= checkop(s.top())){
                ans+=s.top();
                s.pop();
            }
            s.push(text[i]);

        }
        else{
            ans+= text[i];
        }
    }

    while(!s.empty()){
        ans+=s.top();
        s.pop();
    }

    cout<<ans;
}
