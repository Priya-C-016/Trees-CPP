#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node*right;
    Node(int val){
        data=val;
        left=right=NULL;
    }
};

Node* insert(Node* root,int val){
    if(root==NULL){
        return new Node(val);
    }
    if(val<root->data){
        root->left=insert(root->left,val);
    }else{
        root->right=insert(root->right,val);
    }
    return root;
}
void print(Node* root){
    if(root==NULL)return;
    print(root->left);
    cout<<root->data<<" ";
    print(root->right);
}
int main(){
    Node* root=NULL;
    root=insert(root,4);
    insert(root,5);
    insert(root,2);
    insert(root,8);
    insert(root,7);
    print(root);
    
    return 0;
}
