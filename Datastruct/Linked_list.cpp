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
        
        if(ptr == NULL){
            Node *A = new Node(data);
            ptr = A;
        }
        else if(ptr->data == posit){
            Node *N = new Node(data);
            N->next = ptr;
            ptr = N;
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

        if(ptr->data == posit){
            Node* newNode = new Node(data1);
            newNode->next = ptr;
            ptr = newNode;
            return;
        }
        else{
            Node *b = new Node(data1);
            Node *pt = ptr;
            if(pt->data != posit){
                while(pt->data != posit){
                if(pt->next->data == posit){
                    b->next = pt->next;
                    pt->next = b;
                    break;
            }
            pt = pt->next;
        }
        }
        }

    }
    void ADDBACK(int data ,int position){
        Node * nwnode = new Node(data);
        Node *ptr = ptr;
        nwnode->next = ptr;
        
    }

    void deletedata(int posit){
        Node *p1 = ptr;
        while(p1 != NULL){
            
            if(p1->data == posit && p1 != NULL){
                ptr = ptr->next;
                break;
            }
            else if(p1->next->data == posit){
                p1->next = p1->next->next;
                break;
                
            }
            p1 = p1->next;
        }

    }
    
    void print(){
        for(Node *c = ptr;c != NULL; c = c->next){
            cout<<c->data<<" ";
        }
        cout<<endl;
    }

    bool check(int position){
        for(Node *c = ptr;c != NULL;){
            if(c->data == position){
                return true;
            }
            else if(c->data != position){
                c = c->next;
                
            }
            
        }
        
        return 0;
    }
    
    bool checkFirst(int position){
        Node *first = ptr;
        if(ptr->data == position){
            return true;
        }
        else{
            return false;
        }
        return 0;
    }
    
    /*bool checkDelete(int position){
        Node *DELETE = ptr;

        while(DELETE->data != position){
            if(DELETE->data == position){
                return true;
            }
            else{
                
            }
            DELETE = DELETE->next;
        }
        return 0;
    }
    */

    

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
                    //a->print();
                }
            }
            else if(a->check(position) == true){
                if(a->check(data) == false){
                    a->insertBetweenFornt(data,position);
                    a->print();
                }
                else{
                    //a->print();
                }

            }
  
        }
        else if(ch == 'I'){
            cin>>data;
            cin>>position;
            if(a->check(position) == false){
                if(a->check(data) == false){
                    a->insertfornt(data,position);
                    a->print();
                }
                else{
                    //a->print();
                }
                
            }
            else if(a->check(position) == true){
                if(a->check(data) == false){
                    a->insertback(data,position);
                    a->print();
                }
                else{
                    //a->print();
                }
            }
            
            

    }
        else if(ch == 'D'){
            cin>>data;
            
                a->deletedata(data);
                a->print();
            
            
            
        }
        else if(ch == 'E'){
            break;
        }

    }

}