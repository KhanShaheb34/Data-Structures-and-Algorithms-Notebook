#include<iostream>
using namespace std;

struct node {
    int element;
    node *next;
};

node *root = NULL;

void append(int elem) {
    if(root==NULL){
        root = new node();
        root -> element = elem;
        root -> next = NULL;
    }
    else{
        node *current_node = root;
        while(current_node->next != NULL){
            current_node = current_node->next;
        }
        node *newnode = new node();
        newnode -> element = elem;
        newnode -> next = NULL;

        current_node -> next = newnode;
    }
}

void printNodes() {
    node *current_node = root;
    while(current_node != NULL){
        printf("%d\n", current_node->element);
        current_node = current_node->next;
    }
}

int main() {
    append(4);
    append(1);
    append(5);
    append(2);
    append(3);
    printNodes();
    return 0;
}
