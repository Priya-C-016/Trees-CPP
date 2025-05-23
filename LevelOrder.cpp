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
vector<vector<int>> LevelOrder(Node* root){
    vector<vector<int>>ans;
    queue<Node*>q;
    q.push(root);
    while(!q.empty()){
        int n=q.size();
        vector<int>arr;
        for(int i=0;i<n;i++){
             Node* temp=q.front();q.pop();
        // cout<<temp->data<<" ";
        arr.push_back(temp->data);
        if(temp->left!=NULL)q.push(temp->left);
        if(temp->right!=NULL) q.push(temp->right);
        }
       ans.push_back(arr);
    }
    return ans;
}
int main(){
    Node* root=NULL;
    root=insert(root,4);
    insert(root,5);
    insert(root,2);
    insert(root,9);
    insert(root,8);
    insert(root,1);
    vector<vector<int>>ans=LevelOrder(root);
    for(auto level:ans){
        cout<<"[ ";
        for(int val:level){
            cout<<val<<" ";
        }
        cout<<"]";
    }
    return 0;
}
