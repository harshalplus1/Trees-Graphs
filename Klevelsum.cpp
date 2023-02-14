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
    int sum=0;
    if(l==1){
        sum=sum+n->val;
        return sum;
    }
    else{
        return sum+ levelorder(n->left,l-1)+ levelorder(n->right,l-1);
    }
}
int main() {
    Node* n= new Node(2);
    n->right=new Node(3);
    n->left=new Node(4);
    int s=levelorder(n,2);
    cout<<s;

}
