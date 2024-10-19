#include <iostream>
using namespace std;

class Node {
public:
    Node *left;
    Node *right;
    int id;

    Node(int id) {
        this->id = id;
        left = NULL;
        right = NULL;
    }
};

class BNT {
public:
    Node *r;
    
    BNT() {
        r = NULL;
    }

    bool search(int id) {
        Node *n = r;
        while (n != NULL) {
            if (n->id > id) {
                n = n->left;
            } else if (n->id < id) {
                n = n->right;
            } else {
                return true;
            }
        }
        return false;
    }

    void add(int id) {
        if (r == NULL) {
            r = new Node(id);
        } else {
            Node *n = r;
            while (true) {
                if (n->id > id && n->left != NULL) {
                    n = n->left;
                } else if (n->id <= id && n->right != NULL) {
                    n = n->right;
                } else if (n->id > id && n->left == NULL) {
                    n->left = new Node(id);
                    break;
                } else if (n->id <= id && n->right == NULL) {
                    n->right = new Node(id);
                    break;
                }
            }
        }
    }

    int h = 0, t_h = -1;

    void h_high(Node *b) {
        if (b != NULL) {
            t_h++;
            h_high(b->left);
            h_high(b->right);
            if (t_h > h) {
                h = t_h;
            }
            t_h--;
        }
    }

    int height(int v) {
        Node *a = r;
        while (a != NULL) {
            if (a->id > v) {
                a = a->left;
            } else if (a->id < v) {
                a = a->right;
            } else {
                h = 0;
                t_h = -1;
                h_high(a);
                return h;
            }
        }
        return -1;
    }

    void level(Node *l, int lv) {
        if (l == NULL) return;
        if (lv == 0) {
            cout << l->id << ",";
        } else {
            level(l->left, lv - 1);
            level(l->right, lv - 1);
        }
    }

    void Breadth() {
        for (int i = 0; i <= height(r->id); i++) {
            level(r, i);
            cout << "|";
        }
        cout << endl;
    }

    void preorder(Node *ptr) {
        if (ptr != NULL) {
            cout << ptr->id << ",";
            preorder(ptr->left);
            preorder(ptr->right);
        }
    }

    void postorder(Node *ptr) {
        if (ptr != NULL) {
            postorder(ptr->left);
            postorder(ptr->right);
            cout << ptr->id << ",";
        }
    }

    void inorder(Node *ptr) {
        if (ptr != NULL) {
            inorder(ptr->left);
            cout << ptr->id << ",";
            inorder(ptr->right);
        }
    }

    void deleteB(int d) {
        if (!search(d)) {
            return;
        }

        Node *p = r;
        Node *parent = NULL;


        while (p != NULL && p->id != d) {
            parent = p;
            if (p->id > d) {
                p = p->left;
            } else {
                p = p->right;
            }
        }

        if (p == NULL){
            return;
        }


        if (p->left == NULL && p->right == NULL) {
            if (p == r) {
                r = NULL;
            } else if (parent->left == p) {
                parent->left = NULL;
            } else {
                parent->right = NULL;
            }
            delete p;
        }

        else if (p->left == NULL || p->right == NULL) {
            Node *c = (p->left != NULL) ? p->left : p->right;
            if (p == r) {
                r = c;
            } else if (parent->left == p) {
                parent->left = c;
            } else {
                parent->right = c;
            }
            delete p;
        }

        else {
            Node *sc = p;
            Node *s = p->right;


            while (s->left != NULL) {
                sc = s;
                s = s->left;
            }

            p->id = s->id;

            if (sc->left == s) {
                sc->left = s->right;
            } else {
                sc->right = s->right;
            }
            delete s;
        }
    }
};

int main() {
    BNT *b = new BNT();
    char c;
    while (true) {
        cin >> c;
        if (c == 'a') {
            int data;
            cin >> data;
            b->add(data);
        } else if (c == 'd') {
            int data;
            cin >> data;
            b->deleteB(data);
        } else if (c == 'b') {
            b->Breadth();
        } else if (c == 'i') {
            b->inorder(b->r);
            cout << endl;
        } else if (c == 'p') {
            b->preorder(b->r);
            cout << endl;
        } else if (c == 't') {
            b->postorder(b->r);
            cout << endl;
        } else if (c == 'x') {
            break;
        }
    }
}
