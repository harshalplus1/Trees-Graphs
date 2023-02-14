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
int levelorder(Node* n,int l){
    if(n==NULL){
        return 0;
    }
    if(l==1){
        return n->val;
    }
    else{
        return levelorder(n->left,l-1)+ levelorder(n->right,l-1);
    }
}
int main() {
    Node* n= new Node(2);
    n->right=new Node(3);
    n->left=new Node(4);
    n->right->left=new Node(5);
    n->left->left=new Node(6);
    int s=levelorder(n,3);
    cout<<s;

}
