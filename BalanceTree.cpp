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

int dfs(Node* root){
    if(root==NULL)return 0;
    int left=dfs(root->left);
    if(left==-1)return -1;
    int right=dfs(root->right);
    if(right==-1)return -1;
    if(abs(left-right)>1)return -1;
    return max(left,right)+1;
}
bool balancetree(Node* root){
    return dfs(root)!=1;
}
int main(){
    Node* root=NULL;
    root=insert(root,5);
    insert(root,3);
    insert(root,8);
    insert(root,6);
    cout<<balancetree(root);
    return 0;
}
