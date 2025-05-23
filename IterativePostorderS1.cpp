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
    stack<Node*>st;
    Node* curr=root,*last=NULL;
    while(curr!=NULL || !st.empty()){
        if(curr!=NULL){
            st.push(curr);
            curr=curr->left;
        }else{
            Node* temp=st.top();
            if(last!=temp->right && temp->right!=NULL){
                curr=temp->right;
            }else{
                cout<<temp->data<<" ";
                 last=temp;
                st.pop();
               
            }
        }
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
