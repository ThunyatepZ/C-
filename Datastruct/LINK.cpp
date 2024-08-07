#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node *next;
    
    Node(int id){
        data = id;
        next = NULL;
        
    }

};

class linklist{
    public:
    Node *ptr;
    int round = 0;
    linklist(){
        ptr = NULL;
    }

    void insertfornt(int data,int posit){
        
        if(round == 0){
            Node *A = new Node(data);
            ptr = A;
            round++;
        }
        
        else{
            Node *NEW = new Node(data);
            Node *p = ptr;
            while(p->next != NULL){
                p = p->next;
            }
            NEW->next = p->next;
            p->next = NEW;
        }
        }

        void insertBetweenFornt(int data,int posit){
            Node *btw = new Node(data);
            for(Node *check = ptr; check != NULL;check = check->next){
            if(check->data == posit){
                if(check->data == posit){
                    btw->next = check->next;
                    check->next = btw;
                    break;
                }
                
            }
        }
        }

    void insertback(int data1,int posit){
        Node *b = new Node(data1);
        b->next = ptr;
        
        ptr = b;
        



        
            
        /*(Node *p = ptr; p != NULL; p = p->next){
            b->next = p->next;
            p->next = b;
            break;
        }*/
 
        
        
    }

    void print(){
        for(Node *c = ptr;c != NULL; c = c->next){
            cout<<c->data<<" ";
        }
        cout<<endl;
    }
    //โค๊ด
    bool check(int position){
        for(Node *c = ptr;c != NULL; c = c->next){
            if(c->data == position){
                return true;
            }
            else{
                return false;
            }
            
        }
        
        return 0;
    }
    
};


int main(){
    linklist *a = new linklist();
    Node *ptr = ptr;
    char ch;
    int data,position;
    while(true){
        cin>>ch;
        if(ch == 'A'){
            cin>>data;
            cin>>position;
            if(a->check(position) == false){
                if(a->check(data) == false){
                    a->insertfornt(data,position);
                    a->print();
                }
                else{
                    a->print();
                }
   
            }
            else if(a->check(position) == true){
                if(a->check(data) == false){
                    a->insertBetweenFornt(data,position);
                    a->print();
                }
                else{
                    a->print();
                }

            }
  
        }
        else if(ch == 'I'){
            cin>>data;
            cin>>position;
            a->insertback(data,position);
            a->print();

    }
    }
    
    //a->insertfornt(2,2);
    //a->insertfornt(3,2);
    //a->insertfornt(4,2);
    //a->insertfornt(5,2);
    //a->insertfornt(6,2);
    //a->insertback(10,2);
    a->insertback(10,2);
    
    
}