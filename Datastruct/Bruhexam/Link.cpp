#include <iostream>
using namespace std;
class Node{
    public:
    Node *next;
    int id;
    Node(int data){
        id = data;
        next = NULL;
    }
};

class linklist{
    public:
    Node *ptr;
    linklist(){
        ptr = NULL;
    }
    //Normal add
    void addData(int Resive){
        if(ptr == NULL){
            Node *n = new Node(Resive);
            ptr = n;
            
        }
        else{
            Node *c = ptr;
            Node *d = new Node(Resive);
            while(c->next != NULL){
                c = c->next;
            }
            d->next = c->next;
            c->next = d;
        }
    }
    //insert
    void insert(int d,int p){
        Node *check = ptr;
        Node *da = new Node(d);
        while(check->next->id != p){
            check = check->next;
        }
        da->next = check->next;
        check->next = da;
    }
    void print(){
        for(Node *prints = ptr;prints != NULL;prints = prints->next){
            cout<<prints->id<<" ";
        }
    }
};

int main(){
    linklist *l = new linklist();
    l->addData(10);
    l->addData(20);
    l->addData(30);
    l->addData(40);
    l->addData(50);
    l->addData(60);
    l->addData(70);
    
    l->addData(80);
    l->addData(90);
    
    l->insert(50,10);
    l->print();
}