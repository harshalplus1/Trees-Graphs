#include <iostream>
using namespace std;
struct Node{
    int data;
    Node* right;
    Node* left;
    Node(int data) {
        this->data = data;
        right = NULL;
        left = NULL;
    }
};

Node* LCA(Node* root, int l, int r){
    Node* curr=root;
    if(curr==NULL || curr->data==l || curr->data==r){
        return curr;
    }
    Node* left= LCA(curr->left, l,r);
    Node* right= LCA(curr->right,l,r);
    if(left==NULL){
        return right;
    }
    else if(right==NULL){
        return left;
    }
    else{
        return root;
    }
}
int findlevel(Node* n, int num,int l){
    if(n==NULL){
        return -1;
    }
    if(n->data==num){
        return l;
    }
    int ls= findlevel(n->left,num,l+1);
    int rs= findlevel(n->right,num,l+1);
    return max(ls,rs);

}
int spath(Node* n,int l,int r) {
    int ll=findlevel(n,l,0);
    int rl=findlevel(n,r,0);
    return ll+rl;

}
int inorder(Node* n){
    if(n==NULL){
        return -1 ;
    }
    inorder(n->left);
    cout<<n->data<<" ";
    inorder(n->right);
}
int main() {
    Node* n= new Node(1);
    n->left= new Node(2);
    n->left->right= new Node(3);
    n->right= new Node(4);
    n->left->left=new Node(5);
    n->right->left=new Node(6);
    Node* lca= LCA(n,3,6);
    inorder(n);
    cout<<lca->data;
    int d=spath(lca,3,6);
    cout<<d;

}
