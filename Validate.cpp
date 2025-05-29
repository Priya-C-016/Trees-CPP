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

bool Validate(Node* root,long long minval=INT_MAX,long long maxval=INT_MIN){
    if(root==NULL)return true;
    if(root->data<=minval || root->data>=maxval){
        return true;
    }
    return Validate(root->left,minval,root->data) &&(root->right,root->data,maxval);
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
    cout<<"\n"<<Validate(root);
    return 0;
}
