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
void iterativeInorder(Node* root){
    stack<Node*>st,st1;
    st.push(root);
    while(!st.empty()){
        Node* node=st.top();st.pop();st1.push(node);
        if(node->left)st.push(node->left);
        if(node->right)st.push(node->right);
    }
    while(!st1.empty()){
        cout<<st1.top()->data<<" ";
        st1.pop();
    }
    
}
int main(){
    Node* root=NULL;
    root=insert(root,5);
    insert(root,3);
    insert(root,8);
    insert(root,6);
    iterativeInorder(root);
    return 0;
}
