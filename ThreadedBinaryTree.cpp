#include<iostream>
using namespace std;

class Node {
    int x;
    Node*lc,*rc;
    bool lb,rb;
    friend class ThreadedBinaryTree;
public:
    Node() {
        x=0;
        lc=NULL;
        rc=NULL;
        lb=false;
        rb=false;
    }
};

class ThreadedBinaryTree {
    Node*root,*head;
public:
    ThreadedBinaryTree() {
        head=new Node();
        head->rb=true;
        head->lb=false;
        head->rc=head;
        head->lc=NULL;
        root=NULL;
    }

    int insert(Node*r,Node*p) {
        int c;
        if(!r->lb) {
            cout<<"At lc of "<<r->x<<"?";
            cin>>c;
            if(c) {
                p->lc=r->lc;
                r->lc=p;
                r->lb=true;
                p->rc=r;
                return 1;
            }
        }
        else {
            if(insert(r->lc,p))
                return 1;
        }
        if(!r->rb) {
            cout<<"At rc of "<<r->x<<"?";
            cin>>c;
            if(c) {
                p->rc=r->rc;
                r->rc=p;
                r->rb=true;
                p->lc=r;
                return 1;
            }
        }
        else {
            if(insert(r->rc,p))
                return 1;
        }
        return 0;
    }

    void insert(int a) {
        if(!head->lc) {
            root=new Node();
            root->x=a;
            root->lc=head;
            root->lb=false;
            root->rc=head;
            root->rb=false;
            head->lc=root;
            head->lb=true;
            cout<<"Inserted "<<a<<endl;
            return;
        }
        Node*r=root;
        Node*p=new Node();
        p->x=a;
        if(insert(r,p))
            cout<<"Inserted "<<a<<endl;
        else
            cout<<"Did not insert "<<a<<endl;
    }

    void inOrder() {
        Node*r=root;
        while(r->lb)
            r=r->lc;
        while(r!=head) {
            cout<<r->x<<" ";
            if(r->rb) {
                r=r->rc;
                while(r->lb)
                    r=r->lc;
            }
            else
                r=r->rc;
        }
        cout<<endl;
    }

    void preOrder() {
        Node*r=root;
        while(r->lb) {
            cout<<r->x<<" ";
            r=r->lc;
        }
        cout<<r->x<<" ";
        while(r!=head) {
            if(r->rb) {
                r=r->rc;
                while(r->lb) {
                    cout<<r->x<<" ";
                    r=r->lc;
                }
                cout<<r->x<<" ";
            }
            else {
                while(!r->rb)
                    r=r->rc;
            }
        }
        cout<<endl;
    }
};

int main() {
    ThreadedBinaryTree t;
    t.insert(1);
    t.insert(2);
    t.insert(3);
    t.insert(4);
    t.insert(5);
    t.insert(6);
    t.inOrder();
    t.preOrder();
    return 0;
}