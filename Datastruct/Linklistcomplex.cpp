#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node *next;
    
    Node(int V){
        data = V;
        next = NULL;
    }
};

class Linklist{
    public:
    Node *ptr;
    Linklist(){
        ptr = NULL;
    }

    void insert(int data,int position){
        
        if(ptr == NULL){
            Node *a = new Node(data);
            ptr = a;
        }
        
        else if(ptr->data == position){
            Node *s = new Node(data);
            s->next = ptr;
            ptr = s;
        }
        else if(ptr->data != position){
            Node *p = ptr;
            while(p != NULL && p->data != position){
                if(p->next->data == position){
                    Node *tt = new Node(data);
                    tt->next = p->next;
                    p->next = tt;
                    break;
                }
                else{
                    p = p->next;
                }
                
            }
        }

    }
    
    void putlast(int data, int posit){
        Node *nm = new Node(data);
        Node *pp = ptr;
        while(pp != NULL){
            pp = pp->next;
        }
        nm->next = pp->next;
        pp->next = nm;
    }

    bool checkdata(int c){
        Node *o = ptr;
        while(o != NULL){
            if(o->data == c){
                return true;
            }
            else{
                o = o->next;
            }
        }
    }

    void deletedata(int data){
        Node *p101 = ptr;
        while(p101 != NULL){
            if(p101->data == data){
                ptr = ptr->next;
                break;
            }
            else if(p101->next->data == data){
                p101->next = p101->next->next;
                break;
            }
            p101 = p101->next;
        }
    }

    void print(){
        for(Node *c = ptr;c != NULL; c = c->next){
            cout<<c->data<<" ";
        }cout<<endl;
        return;
    }
};

int main(){
    Linklist *l = new Linklist();
    int data,pot;
    char a;
    while(true){
        cin>>a;
        if(a == 'I'){
            cin>>data;
            cin>>pot;
            l->insert(data,pot);
            l->print();
        }

    }

    
    //l->insert(3,1);
    //l->insert(4,11);
    
    //l->insertback(10,3);
    //l->deletedata(1);
    //l->deletedata(10);
    
}