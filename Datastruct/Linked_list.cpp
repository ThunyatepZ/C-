#include <iostream>
using namespace std;
class Node{
    Node *next;
    int value;
    Node(int value){
        this->value = value;
    }
};
class Linklist{
    public:
        Node *Head;
        int size = 0;
        Linklist(int value){
            
        }
};