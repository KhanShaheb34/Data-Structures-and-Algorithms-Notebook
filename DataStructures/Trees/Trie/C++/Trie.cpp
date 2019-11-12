#include<bits/stdc++.h>
using namespace std;

#define ALPHASIZE 26

struct node {
    bool endmark;
    node* next[ALPHASIZE + 1];
    node() {
        endmark = false;
        for(int i=0; i<ALPHASIZE; i++)
            next[i] = NULL;
    }
} *root;

void insertNode(string a){
    node* curr = root;
    for(int i=0; i<a.size(); i++) {
        int id = a[i] - 'a';
        if(curr->next[id] == NULL)
            curr->next[id] = new node();
        curr = curr->next[id];
    }
    curr -> endmark = true;
}

bool query(string a) {
    node* curr = root;
    for(int i=0; i<a.size(); i++) {
        int id = a[i] - 'a';
        if(curr->next[id] == NULL)
            return false;
        curr = curr->next[id];
    }
    return curr -> endmark;
}

int main() {
    root = new node();
    insertNode("hello");
    insertNode("world");
    insertNode("hell");
    insertNode("love");
    insertNode("lover");
    while(1){
        string q;
        cin>>q;
        if(query(q)) printf("Found");
        else printf("Not Found");
    }
    return 0;
}
