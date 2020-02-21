#include<iostream>
using namespace std;

class Node {
    int x;
    Node*lc,*rc;
    friend class BinarySearchTree;
public:
    Node() {
        x=0;
        lc=NULL;
        rc=NULL;
    }
};

class BinarySearchTree {
public:
    Node*root;

    BinarySearchTree() {
        root=NULL;
    }

    void insert(int a) {
        if(!root) {
            root=new Node();
            root->x=a;
            return;
        }
        Node*t=new Node();
        t->x=a;
        Node*r=root;
        while(r) {
            if(r->x>a) {
                if(r->lc)
                    r=r->lc;
                else {
                    r->lc=t;
                    return;
                }
            }
            else {
                if(r->rc)
                    r=r->rc;
                else {
                    r->rc=t;
                    return;
                }
            }
        }
    }

    void deleteNode(int a) {
        Node*c=root;
        Node*p=root;
        while(p) {
            if(a<p->x) {
                if(a==p->lc->x) {
                    c=p->lc;
                    break;
                }
                p=p->lc;
            }
            else {
                if(a==p->rc->x) {
                    c=p->rc;
                    break;
                }
                p=p->rc;
            }
        }
        if(!c->lc && !c->rc) {
            if(p->lc==c)
                p->lc=NULL;
            else
                p->rc=NULL;
            delete c;
        }
        else if(!c->lc && c->rc) {
            if(p->lc==c)
                p->lc=c->rc;
            else
                p->rc=c->rc;
            delete c;
        }
        else if(c->lc && !c->rc) {
            if(p->lc==c)
                p->lc=c->lc;
            else
                p->rc=c->lc;
            delete c;
        }
        else {
            Node*s=c->rc;
            Node*ss=c;
            while(s->lc) {
                ss=s;
                s=s->lc;
            }
            ss->rc=s->rc;
            c->x=s->x;
            delete s;
        }
        
    }

    void inOrder(Node*r) {
        if(r) {
            inOrder(r->lc);
            cout<<r->x<<" ";
            inOrder(r->rc);
        }
    }

};

int main() {
    BinarySearchTree b;
    b.insert(5);
    b.insert(3);
    b.insert(2);
    b.insert(4);
    b.insert(7);
    b.insert(6);
    b.inOrder(b.root);
    cout<<endl;
    // b.deleteNode(3);
    // b.inOrder(b.root);
    // cout<<endl;
    // b.deleteNode(7);
    // b.inOrder(b.root);
    // cout<<endl;
    b.deleteNode(6);
    b.inOrder(b.root);
    cout<<endl;
    return 0;
}