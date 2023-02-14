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
int height(Node* n){
    if(n==NULL){
        return 0;
    }
    int lh=height(n->left);
    int rh=height(n->right);
    return max(lh,rh)+1;
}
int diameter(Node* n){
    if(n==NULL){
        return 0;
    }
    int h=height(n);
    int ldia= diameter(n->left);
    int rdia= diameter(n->right);
    return max(h,max(ldia,rdia))+1;
}
int main() {
    Node* n= new Node(2);
    n->right=new Node(3);
    n->left=new Node(4);
    n->right->left=new Node(5);
    n->left->left=new Node(6);
    int h=height(n);
    cout<<h<<endl;
    int s=diameter(n);
    cout<<s;

}
