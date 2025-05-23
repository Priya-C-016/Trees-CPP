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
bool search(Node* root,int val){
    if(root==nullptr)return false;
    if(root->data==val)return true;
    if(val<root->data){
        return search(root->left,val);
    }else{
        return search(root->right,val);
    }
}
int main(){
    Node* root=NULL;
    root=insert(root,4);
    insert(root,5);
    insert(root,2);
    insert(root,8);
    insert(root,7);
    cout<<search(root,6);
    
    
    
    return 0;
}
