#include <iostream>
#include <string>
using namespace std;

class Node{
    public:
    int value;
    Node * next;
    Node(int i){
        value = i;
        next = NULL;
    }
};

class linklist{
    public:
        Node *Head;
        int size = 0;
        linklist(int value){
            Head = new Node(value);
            Head->next = NULL;
            size = 1;
        }

        void print(){
            for(Node *check = Head;check != NULL;check = check->next){
                cout<<check->value<<" ";
            }
        }
        void insert(int i,int value){
            if(0<=i){
                if(i==0){
                    Node *h = new Node(value);
                    Head->next = h;

                    size++;
                }
                else{
                    int ni = 1;
                    for(Node *h = Head->next; h != NULL; h = h->next){
                        if(ni == i){
                            Node *n = new Node(value);
                            n->next = h->next;
                            h->next = n;
                            size++;
                            break;
                        }
                        ni++;
                    }
                }
            }
        }
};

int main(){
    linklist * l = new linklist(NULL);
    l->insert(0,20);
    l->insert(4,30);
    l->insert(2,40);
    l->insert(3,50);
    l->insert(1,60);
    l->print();
    
}