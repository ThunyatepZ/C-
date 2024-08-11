#include <iostream>
using namespace std;

class Node{
    public:
    string data = "-";
    int id = -1;
    int keep;
    Node *next;
    Node(int b,string d,int a){
        data = d;
        id = b;
        keep = a;
        next = NULL;
    }
};

class Linklist{
    public:
    Node *ptr;
    Linklist(){

    }

    void insertFirst(int id,string DATA){

        Node *aaa = ptr;

        
        if(ptr == NULL){
            int a = id;
            int k = id % 17;
            Node *p = new Node(k,DATA,a);
            ptr = p;
        }

        else{
            int a = id;
            int k = id % 17;
            Node *NEW = new Node(k,DATA,a);
            Node *p = ptr;
            
            while(p->next != NULL){
                p = p->next;
            }
            NEW->next = p->next;
            p->next = NEW;
        }
    }
    
    void print1(int ad){
        
        for(Node *c = ptr;c != NULL; c = c->next){
            if(ad == c->id){
                int a = (c->keep / 17);
                int newc = c->id + (17 * a);
                cout<<"("<<newc<<","<<c->data<<") ";
            }
            
        }
        cout<<endl;
        
    }

    void serch(int dataserch){
        Node *wee = ptr;
        for(Node *serch = ptr;serch != NULL;serch = serch->next){
            if(serch->keep == dataserch){
                cout<<serch->data<<endl;
                break;
            }
            else if(serch->next == NULL){
                cout<<"-"<<endl;
        }
        }
        

    }
};

class data1{
    public:
    int hash;
    string Array[17];
    int Arrayint[17];
    string DATA;
    char ch;
};

int main(){
    data1 d;
    Linklist *l = new Linklist();
    
    for(int j = 0;j < 17;j++){
            d.Arrayint[j] = -1;
            d.Array[j] = "-";
        }
    int id;
    while(true){
        
        cin>>d.ch;
        if(d.ch == 'a'){
            cin>>id;
            cin>>d.DATA;
            d.hash = id % 17;
                l->insertFirst(id,d.DATA);
            d.Array[d.hash] = d.DATA;
            d.Arrayint[d.hash] = id;
        }
        else if(d.ch == 'p'){
            for(int i = 0; i < 17;i++){
                    if(d.Arrayint[i] == -1){
                        cout<<"("<<d.Arrayint[i]<<","<<d.Array[i]<<")"<<endl;
                    }
                    else{
                        l->print1(i);
                    }



                
            }
        }
        else if(d.ch == 's'){
            cin>>id;
            l->serch(id);
        }
        else if(d.ch == 'e'){
            break;
        }
    }
}