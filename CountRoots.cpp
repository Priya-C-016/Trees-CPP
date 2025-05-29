#include<bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    Node* left,*right;
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

int countRoots(Node* root){
    return (root != NULL) ? 1 : 0;
}

void print(Node* root){
    if(root==NULL)return;
    print(root->left);
    cout<<root->data<<" ";
    print(root->right);
}

int main(){
    Node* root=NULL;
    root=insert(root,3);
    root=insert(root,5);
    root=insert(root,2);
    root=insert(root,8);
    root=insert(root,6);
    root=insert(root,9);
    print(root);
    cout<<"\n"<<countRoots(root);
    return 0;
}
