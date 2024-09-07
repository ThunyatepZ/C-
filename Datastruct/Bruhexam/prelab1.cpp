#include <iostream>
using namespace std;
class stack{
    public:
    string arr[10];
    int top = 0;

    void push(char data){
        if(top <= 9){
            arr[++top] = data;
        }
    }

    void pop(){
        if(top > 0){
            top--;
        }
    }
};

int main(){
    int countmath = 0;
    int ERROR = 0;
    stack s;
    string equation;
    getline(cin,equation);
    for(int i = 0; equation[i] != '\0';i++){
        if(equation[i] == '('){
            s.push(equation[i]);
        }
        else if(equation[0] == ')'){
                cout<<"Not matched"<<endl;
                cout<<"0 matched";
                return 1;
        }
        else if(equation[i] == ')'){
            if(s.arr[s.top] != "("){
                ERROR++;
            }

            else{
                s.pop();
                countmath++;
            }
            
        }
        else{

        }

        if(equation[i] == '['){
            s.push(equation[i]);
        }

        else if(equation[0] == ']'){
                cout<<"Not matched"<<endl;
                cout<<"0 matched";
                return 1;
        }

        else if(equation[i] == ']'){
            if(s.arr[s.top] != "["){
                ERROR++;
            }
            else{
                s.pop();
                countmath++;
            }
        }
        else{

        }

        if(equation[i] == '{'){
            s.push(equation[i]);
        }

        else if(equation[0] == '}'){
                cout<<"Not matched"<<endl;
                cout<<"0 matched";
                return 1;
        }

        else if(equation[i] == '}'){
            if(s.arr[s.top] != "{"){
                ERROR++;
            }
            else{
                s.pop();
                countmath++;
            }
        }
        else{

        }

        if(equation[i] == '<' && equation[i+1] != '<'){
            s.push(equation[i]);
        }
        else if(equation[0] == '>' && equation[i+1] != '>'){
            cout<<"ERROR";
            return 1;
        }
        else if(equation[i] == '>' && equation[i+1] != '>'){
            if(s.arr[s.top] != "<"){
                ERROR++;
            }
            else{
                s.pop();
                countmath++;
            }
        }

        if(equation[i] == '<' && equation[i+1] == '<'){
            i++;
            s.push('*');
        }
        else if(equation[i] == '>' && equation[i+1] == '>'){
            i++;
            if(s.arr[s.top] != "*"){
                ERROR++;
            }
            else{
                s.pop();
                countmath++;
            }
        }

    

    }
    
    if(countmath > 0 && ERROR <= 0 && s.top == 0){
        cout<<countmath<<" Matched";
    }
    else{
        cout<<"Not match "<<endl;
        cout<<countmath<<" Matched";
    }
}