#include<iostream>
#include<queue>
using namespace std;

class Node {
    int x;
    Node*lc,*rc;
    friend class BinaryTree;
    friend class queue;
public:
    Node() {
        x=0;
        lc=NULL;
        rc=NULL;
    }
};

class BinaryTree {
public:
    Node*root;
    BinaryTree() {
        root=NULL;
    }

    int insert(Node*r,Node*p) {
        int c;
        if(!r->lc) {
            cout<<"As lc of "<<r->x<<"?";
            cin>>c;
            if(c) {
                r->lc=p;
                return 1;
            }
        }
        else {
            if(insert(r->lc,p))
                return 1;
        }
        if(!r->rc) {
            cout<<"As rc of "<<r->x<<"?";
            cin>>c;
            if(c) {
                r->rc=p;
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
        if(!root) {
            root=new Node();
            root->x=a;
            cout<<"Inserted "<<a<<endl;
            return;
        }
        Node*r;
        r=root;
        Node*p=new Node();
        p->x=a;
        if(insert(r,p))
            cout<<"Inserted "<<a<<endl;
        else
            cout<<"Did not insert "<<a<<endl;
    }

    void preOrder(Node*r) {
        if(r) {
            cout<<r->x<<" ";
            preOrder(r->lc);
            preOrder(r->rc);
        }
    }

    void inOrder(Node*r) {
        if(r) {
            inOrder(r->lc);
            cout<<r->x<<" ";
            inOrder(r->rc);
        }
    }

    void postOrder(Node*r) {
        if(r) {
            postOrder(r->lc);
            postOrder(r->rc);
            cout<<r->x<<" ";
        }
    }

    void levelOrder() {
        queue<Node*>q;
        Node*t=root;
        q.push(t);
        while(!q.empty()) {
            t=q.front();
            q.pop();
            cout<<t->x<<" ";
            if(t->lc)
                q.push(t->lc);
            if(t->rc)
                q.push(t->rc);
        }
        cout<<endl;
    }

    void deleteNode(int a) {
        queue<Node*>q;
        Node*t,*p,*s,*r;                //p-node to delete, s-parent of p, t-last node, r-parent of t
        q.push(root);
        while(!q.empty()) {
            t=q.front();
            q.pop();
            if(t->lc) {
                r=t;
                if(t->lc->x==a) {
                    p=t->lc;
                    s=t;
                }
                q.push(t->lc);
            }
            if(t->rc) {
                r=t;
                if(t->rc->x==a) {
                    p=t->rc;
                    s=t;
                }
                q.push(t->rc);
            }
        }
        if(r->lc==t)
            r->lc=NULL;
        else
            r->rc=NULL;
        t->lc=p->lc;
        t->rc=p->rc;
        if(s->lc==p) 
            s->lc=t;
        else
            s->rc=t;
        delete p;
        levelOrder();
    }

    int height(Node*r) {
        if(!r)
            return 0;
        return 1+max(height(r->lc),height(r->rc));
    }

    int countLeaf(Node*r) {
        if(!r)
            return 0;
        if(!r->lc && !r->rc)
            return 1;
        return countLeaf(r->lc)+countLeaf(r->rc);
    }

    int countInt(Node*r) {
        if(!r)
            return 0;
        if(!r->lc || !r->rc)
            return 1;
        return countInt(r->lc)+countInt(r->rc);
    }

    Node*copy(Node*r) {
        if(r) {
            Node*p=new Node();
            p->x=r->x;
            if(r->lc)
                p->lc=copy(r->lc);
            if(r->rc)
                p->rc=copy(r->rc);
            return p;
        }
    }

    Node*mirror(Node*r) {
        if(r) {
            Node*p=new Node();
            p->x=r->x;
            if(r->lc)
                p->rc=mirror(r->lc);
            if(r->rc)
                p->lc=mirror(r->rc);
            return p;
        }
    }

};

int main() {
    BinaryTree *b=new BinaryTree();
    b->insert(1);
    b->insert(2);
    b->insert(3);
    b->insert(4);
    b->insert(5);
    b->insert(6);
    b->preOrder(b->root);
    cout<<endl;
    b->inOrder(b->root);
    cout<<endl;
    b->postOrder(b->root);
    cout<<endl;
    b->levelOrder();
    // b->deleteNode(2);
    cout<<b->height(b->root)+1<<endl;
    cout<<b->countLeaf(b->root)<<endl;
    cout<<b->countInt(b->root)<<endl;
    b->preOrder(b->copy(b->root));
    cout<<endl;
    b->preOrder(b->mirror(b->root));
    cout<<endl;
    
    return 0;
}