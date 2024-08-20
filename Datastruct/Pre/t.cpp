#include <iostream>
#include <cstring>
using namespace std;
class Stack{
    public:
        char Array[10];
        int top = 0;
        Stack(){Array[0] = 9;}
        bool empty(){//มีไว้เช็คว่าว่างมั้ย
            if(top==0){
                return true;
            }
            else{
                return false;
            }
        }
        bool full(){
            if(top == 9){
                return true;
            }
            else{
                return false;
            }
        }
        void push(char data){
            if(!full()){
                top++;
                Array[top] = data;
            }
        }
        int pop(){
            if(!empty()){
                
                
                top--;
            }
            return -1;
        }
        void print(){
            cout<<"Stack: ";
            for(int i =1;i <=top;i++){
                cout<<Array[i]<<" ";
            }
            cout<<endl;
        }
};
int main(){
    Stack s;
    string awa;
    int count = 0;
    int config = 0;
    getline(cin,awa);
    for(int i = 0;i <= awa.length();i++){
        if(awa[i] == '<'){
            s.push(awa[i]);
            //s.print();
        }
        else if(awa[i] == '>'){
            
            if(s.empty()){
                cout<<"Not matched"<<endl;
                cout<<count<<" Matched"<<endl;
                return 0;
            }
            else if(s.Array[s.top] != '<'){
                config++;
            }
            else if(s.Array[s.top] == '<'){
                s.pop();
                count++;
                //s.print();
            }
            else{
                
            }
        }

        if(awa[i] == '('){
            s.push(awa[i]);
            //s.print();
            
        }
        else if(awa[i] == ')'){
            
            if(s.empty()){
                cout<<"Not matched"<<endl;
                cout<<count<<" Matched"<<endl;
                return 0;
            }
            else if(s.Array[s.top] != '('){
                config++;
            }
            else if(s.Array[s.top] == '('){
                s.pop();
                count++;
                //s.print();
            }
            else{

            }
            
        }

        if(awa[i] == '{'){
            s.push(awa[i]);
            //s.print();
        }
        else if(awa[i] == '}'){
            
            if(s.empty()){
                cout<<"Not matched"<<endl;
                cout<<count<<" Matched"<<endl;
                return 0;
            }
            else if(s.Array[s.top] != '{'){
                config++;
            }
            else if(s.Array[s.top] == '{'){
                s.pop();
                count++;
                //s.print();
            }
            else{
                
            }
        }

        if(awa[i] == '['){
            s.push(awa[i]);
            //s.print();
        }
        else if(awa[i] == ']'){
            
            if(s.empty()){
                cout<<"Not matched"<<endl;
                cout<<count<<" Matched"<<endl;
                return 0;
            }
            else if(s.Array[s.top] != '['){
                config++;
            }
            else if(s.Array[s.top] == '['){
                s.pop();
                count++;
                //s.print();
            }
            else{
                
            }
        }


    }
    if(s.empty() && config == 0){
        cout<<count<<" matched";
    }
    else{
        cout<<"Not matched"<<endl;
        cout<<count<<" matched";
    }
   

}