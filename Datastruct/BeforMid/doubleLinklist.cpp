#include <iostream>
using namespace std;
class Node{
    public:
    int data;
    Node *next;
    Node *back;
    Node(int data){
        this->data = data;
        this->next = NULL;
        this->back = NULL;
    }
};

class linklist{
    public:
    Node *ptr;
    void add(int D){
        
        if(ptr == NULL){
            Node *n = new Node(D);
            ptr = n;
        }
        else{
            Node *temp = ptr;
            Node *d = new Node(D);
            while(ptr->next != NULL){
                temp = temp->next;
            }
                d->next = temp->next;
                
                temp->next = d;
                d->back = temp;
        }
    }

    void insert(int d1,int post){
        Node *m = new Node(d1);
        Node *t = ptr;
        while(t->next->data != post){
            t = t->next;
        }
            m->next = t->next;
            t->next->back = m;
            t->next = m;
            m->back = t;


    }

    void print(){
        Node *temp;
        for(Node *p = ptr; p != NULL; p = p->next){
            temp = p;
            
        }
        for(Node *k = temp;k != NULL;k = k->back){
            cout<<k->data<<" ";
        }
    }
};

int main(){
    linklist l;
    l.add(11);

    l.add(13);
    l.insert(12,13);
    l.print();
}