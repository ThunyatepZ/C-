#include <iostream>
using namespace std;

class Node {
public:
    Node *next;
    int data;
    Node(int dataIn) {
        next = NULL;
        data = dataIn;
    }
};

class linklist {
public:
    int size = 0;
    Node *head;
    linklist() {
        head = NULL;
        size = 0;
    }

    void print() {
        for (Node *check = head; check != NULL; check = check->next) {
            cout << check->data << " ";
        }
        cout << endl; // เพิ่มการขึ้นบรรทัดใหม่หลังจากพิมพ์เสร็จ
    }

    void insert(int i, int value) {
        if (i >= 0) {
            if (i == 0) {
                Node *h = new Node(value);
                h->next = head;
                head = h;
                size++;
            } else {
                int ni = 1;
                Node *current = head;
                while (current != NULL && ni < i) {
                    current = current->next;
                    ni++;
                }
                if (current != NULL) {
                    Node *n = new Node(value);
                    n->next = current->next;
                    current->next = n;
                    size++;
                }
            }
        }
    }
};

int main() {
    linklist *l = new linklist();
    char ccc;
    int i,data;
    while(true){
        cin>>ccc;
        if(ccc == 'I'){
            cin>>i;
            cin>>data;
            l->insert(i,data);
            l->print();
        }
        

        }

    return 0;
}
