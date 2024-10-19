#include <iostream>
using namespace std;

class Node
{
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

class BinaryTree{
    public:
    Node *root;
    BinaryTree(){
        root = NULL;
    }

    bool serch(int data){
        Node *n = root;
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
        return false;
    }
    void adddata(int data){
        if(root == NULL){
            root = new Node(data);
        }
        else{
            Node *n = root;
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
    void preorder(Node *ptr){
        if(ptr != NULL){
            cout<< ptr->data << ",";
            preorder(ptr->left);
            preorder(ptr->right);
        }
    }
};

int main(){
    BinaryTree B;
    B.adddata(10);
    B.adddata(20);
    B.adddata(450);
    B.adddata(12);
    B.adddata(2);
    B.adddata(52);
    B.adddata(112);
    B.preorder(B.root);
}