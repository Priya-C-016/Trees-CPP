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

Node* finmin(Node* root){
    while(root->left!=NULL){
        root=root->left;
    }
    return root;
}

Node* deleteNode(Node* root,int val){
    if (root == NULL) return NULL;

    if (val < root->data) {
        root->left = deleteNode(root->left, val);
    } else if (val > root->data) {
        root->right = deleteNode(root->right, val);
    } else{//if node has zero childer
        if(root->left==NULL && root->right==NULL){
            delete root;
            return NULL;
        }//It node has only one child
        else if(root->left==NULL){
            Node* temp=root->right;
            delete root;
            return temp;
        }
        else if(root->right==NULL){
            Node* temp=root->left;
            delete root;
            return temp;
        }
        else{// if node has two childs
            Node* temp=finmin(root->left);
            root->data=temp->data;
            root->right=deleteNode(root->right,temp->data);
        }
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
    cout<<"\n";
    deleteNode(root,2);
    print(root);
    
    
    
    return 0;
}
