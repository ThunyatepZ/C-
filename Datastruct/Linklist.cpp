#include <iostream>
using namespace std;

class Node{
    public:
        Node *next;
        int value;
        Node(int Val){
            value = Val;
            next = NULL;
        }
};

int main(){
    Node *a = new Node(10);
    a->next = new Node(20);
    a->next->next = new Node(30);
    for(Node *check = a;check != NULL;check = check->next){
        cout<<check->value<<" ";
    }

    
}