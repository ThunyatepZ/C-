#include <iostream>
#include <cstring>
#include <cstring>
using namespace std;
class stack{
	public:
	int array[10];
	int top = 0;
	stack(){array[0] = 9;}
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
	
	void push(char n){
		if(!full()){
			top++;
			array[top] = n;
		}
		

	}
	int pop(){
		if(!empty()){
			int remove = array[top];
			top--;

		}
		
		//cout<<top;

	}
	void show(){
		for(int i = 1;i<=top;i++){
			cout<<array[i]<<" ";
		}
	}
};

int main(){
    string str;
    cin>>str;
    for(int i = 0;i < 10;i++){
        cout<<i<<endl;
    }
}