#include <iostream>
using namespace std;
struct Node{
    int data;
    Node* left;
    Node* right;
    Node(int data){
        this->data=data;
        left=NULL;
        right=NULL;
    }
};
int height(Node* root){
    if(root==NULL){
        return 0;
    }
    int lh=height(root->left);
    int rh=height(root->right);
    return max(lh,rh)+1;
}

bool isBalanced(Node* root){
    if(root==NULL){
        return true;
    }
    if(!isBalanced(root->left)){
        return false;
    }
    if(!isBalanced(root->right)){
        return false;
    }

    int lh=height(root->left);
    int rh=height(root->right);
    if(abs(lh-rh)<=1){
        return true;
    }
    else{
        return false;
    }
}
int check(int sum){
    if(sum==10){
        return 0;
    }
    sum+=1;
    cout<<sum<<" ";
    check(sum);
}
int main() {
    Node* n=new Node(2);
    n->left=new Node(3);
    n->right=new Node(4);
    n->left->left=new Node(5);
    n->left->right=new Node(6);
    int sum=0;
    bool w=isBalanced(n);
    check(sum);
    cout<<w;
}
