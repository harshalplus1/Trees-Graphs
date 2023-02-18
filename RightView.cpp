#include <iostream>
#include <queue>
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

void rightview(Node* node){
    if(node==NULL){
        return;
    }
    queue<Node*> q;
    q.push(node);
    while(!q.empty()){
        int n=q.size();
        for(int i=0;i<n;i++){
            Node* curr=q.front();
            q.pop();
            if(i==n-1){
                cout<<curr->data<<" ";
            }
            if(curr->left!=NULL){
                q.push(curr->left);
            }
            if(curr->right!=NULL){
                q.push(curr->right);
            }
        }
    }
}
int main() {
    Node* n=new Node(1);
    n->left=new Node(2);
    n->right=new Node(3);
    n->left->left=new Node(4);
    rightview(n);
}
