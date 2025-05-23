#include<bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    Node* left ,*right;
    Node(int val){
        data=val;
        left=right=NULL;
    }
};
Node* insert(Node* root,int val){
    if(root==nullptr){
      return new Node(val);  
    }
    if(val<root->data){
        root->left=insert(root->left,val);
    }else{
        root->right=insert(root->right,val);
    }
    return root;
}
void interativepreorder(Node* root){
    if(root==NULL)return;
    stack<Node*>st;
    st.push(root);
    while(!st.empty()){
        Node* curr=st.top();st.pop();
        cout<<curr->data<<" ";
        if(curr->left)st.push(curr->left);
        if(curr->right)st.push(curr->right);
    }
}
int main(){
    Node* root=NULL;
    root=insert(root,4);
    insert(root,5);
    insert(root,2);
    insert(root,9);
    insert(root,8);
    insert(root,1);
    interativepreorder(root);
    return 0;
}
