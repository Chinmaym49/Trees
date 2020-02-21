#include<iostream>
using namespace std;

class Node {
    int x;
    Node*lc,*rc;
    friend class AVLTree;
public:
    Node() {
        x=0;
        lc=NULL;
        rc=NULL;
    }
};

class AVLTree {
public:
    Node*root;

    AVLTree() {
        root=NULL;
    }

    void insert(int d) {
        if(!root) {
            root=new Node();
            root->x=d;
            return;
        }
        Node*p=new Node();
        p->x=d;
        Node*r=root;
        while(true) {
            if(r->x>d) {
                if(!r->lc) {
                    r->lc=p;
                    break;
                }
                r=r->lc;
            }
            else {
                if(!r->rc) {
                    r->rc=p;
                    break;
                }
                r=r->rc;
            }
        }
        Node*w=root,*x,*y,*z;
        r=root;
        int f,ff=0;
        while(r) {
            f=0;
            if(abs(height(r->lc)-height(r->rc))>1) {
                ff=1;
                f=1;
                x=r;
                if(r->x>p->x)
                    y=r->lc;
                else
                    y=r->rc;
                if(y->x>p->x)
                    z=y->lc;
                else
                    z=y->rc;
                if(z->x==p->x)
                    break;
            }
            if(!f)
                w=r;
            if(r->x>p->x) 
                r=r->lc;
            else
                r=r->rc;
        }
        if(ff) {
            if(x->lc==y && y->lc==z)
                ll(w,x,y,z);
            else if(x->rc==y && y->rc==z)
                rr(w,x,y,z);
            else if(x->lc==y && y->rc==z)
                lr(w,x,y,z);
            else
                rl(w,x,y,z);
        }
    }

    void ll(Node*w,Node*x,Node*y,Node*z) {
        if(x==root) {
            root=y;
            root->rc=x;
            root->lc=z;
            x->lc=NULL;
            x->rc=NULL;
            z->lc=NULL;
            z->rc=NULL;
            return;
        }
        if(w->lc==x)
            w->lc=y;
        else
            w->rc=y;
        x->lc=y->rc;
        y->rc=x;
    }

    void rr(Node*w,Node*x,Node*y,Node*z) {
        if(x==root) {
            root=y;
            root->lc=x;
            root->rc=z;
            x->lc=NULL;
            x->rc=NULL;
            z->lc=NULL;
            z->rc=NULL;
            return;
        }
        if(w->rc==x)
            w->rc=y;
        else
            w->lc=y;
        x->rc=y->lc;
        y->lc=x;
    }

    void lr(Node*w,Node*x,Node*y,Node*z) {
        if(x==root) {
            root=z;
            root->rc=x;
            root->lc=y;
            x->lc=NULL;
            x->rc=NULL;
            y->lc=NULL;
            y->rc=NULL;
            return;
        }
        if(w->lc==x)
            w->lc=z;
        else
            w->rc=z;
        y->rc=z->lc;
        x->lc=z->rc;
        z->lc=y;
        z->rc=x;
    }

    void rl(Node*w,Node*x,Node*y,Node*z) {
        if(x==root) {
            root=z;
            root->lc=x;
            root->rc=y;
            x->lc=NULL;
            x->rc=NULL;
            y->lc=NULL;
            y->rc=NULL;
            return;
        }
        if(w->lc==x)
            w->lc=z;
        else
            w->rc=z;
        y->lc=z->rc;
        x->rc=z->lc;
        z->rc=y;
        z->lc=x;
    }

    int height(Node*r) {
        if(!r)
            return 0;
        return 1+max(height(r->lc),height(r->rc));
    }

    void preOrder(Node*r) {
        if(r) {
            cout<<r->x<<" ";
            preOrder(r->lc);
            preOrder(r->rc);
        }
    }

};

int main() {
    AVLTree *a=new AVLTree();
    // a->insert(1);           // LL
    // a->insert(2);
    // a->insert(3);

    // a->insert(3);        // RR
    // a->insert(2);
    // a->insert(1);

    // a->insert(1);        // RL
    // a->insert(3);
    // a->insert(2);

    a->insert(3);        // LR
    a->insert(1);
    a->insert(2);

    a->preOrder(a->root);
    cout<<endl;
    

    return 0;
}