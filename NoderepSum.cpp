#include <iostream>
using namespace std;
struct Node{
    int val;
    Node* right;
    Node* left;
    Node(int val){
        this->val=val;
        this->right=NULL;
        this->left=NULL;
    }
};
void sumrepNode(Node* n){
    if(n==NULL){
        return;
    }
    sumrepNode(n->left);
    sumrepNode(n->right);
    if(n->left!=NULL){
        n->val+= n->left->val;
    }
    if(n->right!=NULL){
        n->val+=n->right->val;
    }
}
void preorder(Node* n){
    if(n==NULL){
        return;
    }
    cout<<n->val<<" ";
    preorder(n->left);
    preorder(n->right);
}
int main() {
    Node* n= new Node(2);
    n->right=new Node(3);
    n->left=new Node(4);
    n->right->left=new Node(5);
    n->left->left=new Node(6);
    sumrepNode(n);
    preorder(n);
}