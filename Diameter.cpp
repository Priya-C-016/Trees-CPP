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
Node* insert(Node* root, int val){
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

int maxdia=0;
int height(Node* root){
    if(root==NULL)return 0;
    int left=height(root->left);
    int right=height(root->right);
    maxdia=max(maxdia,left+right);
    return 1+max(left,right);
}
int diameter(Node* root){
    maxdia=0;
    height(root);
    return maxdia;
}
int main(){
    Node* root=NULL;
    root=insert(root,5);
    insert(root,3);
    insert(root,8);
    insert(root,6);
    cout<<diameter(root);
    return 0;
}
