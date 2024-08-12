#include <iostream>
#include <cstring>
using namespace std;
class stack{
  public:
    int array[20];
    int top = 0;
    stack(){array[0] = 19;}
    bool empty(){
        if(top == 0){
            return true;
        }
        else{
            return false;
        }
    }
    bool full(){
        if(top == array[0]){
            return true;
        }
        else{
            return false;
        }
    }

    
    void push(int n){
        if(!full()){
        top++;
        array[top] = n;
        }
    }
    
    int pop(){
        if(!empty()){
        int temp = array[top];
        top--;
        return temp;
        }
        return 0;
    }
    
    void show(){
        for(int i = 1;i<=top;i++){
            cout<<array[i]<<" ";
        }cout<<endl;

    }
    int size(){
        return top+1;
    }
    
};

int main(){
    stack s1;
    int number;
    char character;
    
    while(true){
        cin>>character;
        if(character == 'U'){
            cin>>number;
            s1.push(number);
        }
    else if(character == 'O'){
        cout<<s1.pop()<<endl;
    }
    else if(character == 'T'){
        cout<<s1.array[s1.top]<<endl;
    }
    else if(character == 'P'){
        s1.show();
    }
    else if(character == 'N'){
        cout<<s1.top<<endl;
    }
    else if(character == 'X'){
        break;
    }
    }
}
