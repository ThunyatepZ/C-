#include <iostream>
#include <queue>
using namespace std;
class Node {
    public: 
    Node *left;
    Node *right;
    int data;
    Node(int data){
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

class BinaryTree {
    public:
    Node *top;
    BinaryTree(){
        top = NULL;
    }

    bool sc(int data){
        Node *n = top;
        while(n != NULL){
            if(n->data > data){
                n = n->left;
            }
            else if(n->data < data){
                n = n->right;
            }
            else{
                return true;
            }
        }
    }

    void adddata(int data){
        if(top == NULL){
            top = new Node(data);
        }
        else{
            Node *n = top;
            while(true){
                if(n->data > data && n->left != NULL){
                    n = n->left;
                }
                else if(n->data < data && n->right != NULL){
                    n = n->right;
                }
                else if(n->data > data && n->left == NULL){
                    n->left = new Node(data);
                    break;
                }
                else if(n->data < data && n->right == NULL){
                    n->right = new Node(data);
                    break;
                }
            }
        }
    }

void Breadth(Node* root){
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        int level = q.size();
        for(int i = 0; i < level; i++){
            Node* n = q.front();
            q.pop();
            cout << n->data << ',';
            if(n->left != nullptr){
                q.push(n->left);
            }
            if(n->right != nullptr){
                q.push(n->right);
            }
        }
        cout << " | ";
    }
}


    void preorder(Node *ptr){
        if(ptr != NULL){
            cout<<ptr->data<<",";
            preorder(ptr->left);
            preorder(ptr->right);
        }
    }
};

int main(){
    BinaryTree *b = new BinaryTree();
    b->adddata(19);
    b->adddata(20);
    b->adddata(41);
    b->adddata(1);
    b->adddata(4);
    b->adddata(100);
    // b->preorder(b->top);
    b->Breadth(b->top);
}
