#include<iostream>
using namespace std;

class Node {
    bool isEnd;
    Node*alp[27]={NULL};
    friend class TrieTree;
public:
    Node() {
        isEnd=false;
    }
};

class TrieTree {
    Node*root;
public:
    TrieTree() {
        root=new Node();
    }

    void insert(string s) {
        int c;
        Node*q=root,*r=root;
        for(int i=0;s[i]!='\0';i++) {
            c=s[i]-'a';
            if(!q->alp[c]) {
                Node*p=new Node();
                q->alp[c]=p;
            }
            r=q;
            q=q->alp[c];
        }
        r->isEnd=true;
    }

    bool search(string s) {
        int c;
        Node*q=root,*p=root;
        for(int i=0;s[i]!='\0';i++) {
            c=s[i]-'a';
            if(!q->alp[c])
                return false;
            p=q;
            q=q->alp[c];
        }
        return p->isEnd;
    }

};

int main() {
    TrieTree t;
    t.insert(string("a"));
    t.insert(string("the"));
    t.insert(string("there"));
    t.insert(string("their"));
    t.insert(string("answer"));
    t.insert(string("any"));
    t.insert(string("by"));

    cout<<t.search(string("an"))<<endl;
    return 0;
}