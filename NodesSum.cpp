#include <iostream>
using namespace std;
int add=0;
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
int sum(Node* n){
    if(n==NULL) {
        return 0;
    }
    else{
        return sum(n->right)+sum(n->left)+n->val;
    }
}
int main() {
    Node* n= new Node(2);
    n->right=new Node(3);
    n->left=new Node(4);
    n->right->left=new Node(5);
    n->left->left=new Node(6);
    int s=sum(n);
    cout<<s;

}
