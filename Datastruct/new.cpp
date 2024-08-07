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
        /*else if(aaa->id == id){
            id = id % 17;
            Node *i = new Node(id,DATA);
            aaa->next = i;
            aaa = ptr;
        }*/
        
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
    
    /*void insertBetweenFornt(int id,string DATA){
            Node *btw = new Node(id,DATA);
            for(Node *check = ptr; check != NULL;check = check->next){

                if(check->next->id > id){
                    btw->next = check->next;
                    check->next = btw;
                    break;

            }
        }
        }*/

    
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

int main(){
    
    Linklist *l = new Linklist();
    int hash;
    char ch;
    string Array[17];
    int Arrayint[17];
    string DATA;
    for(int j = 0;j < 17;j++){
            Arrayint[j] = -1;
            Array[j] = "-";
        }
    int id;
    while(true){
        
        cin>>ch;
        if(ch == 'a'){
            cin>>id;
            cin>>DATA;
            hash = id % 17;
                l->insertFirst(id,DATA);

            
            Array[hash] = DATA;
            Arrayint[hash] = id;
            //l->print();
        }
        else if(ch == 'p'){
            for(int i = 0; i < 17;i++){
                    if(Arrayint[i] == -1){
                        cout<<"("<<Arrayint[i]<<","<<Array[i]<<")"<<endl;
                    }
                    else{
                        l->print1(i);
                    }



                
            }
        }
        else if(ch == 's'){
            cin>>id;
            l->serch(id);
                
           
            
        }
        else if(ch == 'e'){
            break;
        }
    }
    
    


}