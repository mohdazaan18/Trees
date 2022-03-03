#include <iostream>
#include "tree.cpp"
#include<queue>
using namespace std;


TreeNode<int> *Input(){
    int rootdata;
    cout<<"Enter data :"<<endl;
    cin>>rootdata;
    TreeNode<int> *root = new TreeNode<int>(rootdata);
    int n;
    cout<<"Enter children of this node : ";
    cin>>n;
    for(int i =0;i<n;i++){
        TreeNode<int> *child = Input();
        root->children.push_back(child);
    }


    return root;
}

TreeNode<int> *InputLevelwise(){
    int rootdata;
    cout<<"Enter rootdata : ";
    cin>>rootdata;
    TreeNode<int> *root = new TreeNode<int>(rootdata);
    queue<TreeNode<int>*> q;
    q.push(root);
    while(!q.empty()){
        TreeNode<int> *front = q.front();
        q.pop();
        cout<<"number of child of this node : "<<endl;
        int n;
        cin>>n;
        for(int i = 0;i<n;i++){
            int childdata;
            cout<<"Enter data of "<<i<<" node : ";
            cin>>childdata;
            TreeNode<int> *child = new TreeNode<int>(childdata);
            q.push(child);
            front->children.push_back(child);
        }

    }
    return root;
}
void printTreeLevelwise(TreeNode<int> *root){
    if(root == NULL){
        return;
    }
    queue<TreeNode<int>*> q;
    q.push(root);
    while(!q.empty()){
        TreeNode<int> *front = q.front();
        q.pop();
        cout<<front->data<<":";
        for(int i = 0;i<front->children.size();i++){
            cout<<front->children[i]->data<<",";
            q.push(front->children[i]);
        }
        cout<<endl;
    }

}

int leafnode(TreeNode<int> *root){
    if(root==NULL){
        return 0;
    }

    int count = 0;
    if(root->children.size() == 0){
        count++;
    }
    for(int i = 0;i<root->children.size();i++){
        count+= leafnode(root->children[i]);

    }
    return count;

}

void printTree(TreeNode<int> *root){
    if(root == NULL){
        return;
    }
    cout<<root->data<<":";
    for(int i = 0;i<root->children.size();i++){
        cout<<root->children[i]->data<<",";
    }
    cout<<endl;
    for(int i = 0;i<root->children.size();i++){
        printTree(root->children[i]);
    }



}

void preorder(TreeNode<int> *root){
    if(root == NULL){
        return;
    }
    cout<<root->data<<" ";
    for(int i =0;i<root->children.size();i++){
        preorder(root->children[i]);
    }

}
void postorder(TreeNode<int> *root){
    if(root == NULL){
        return;
    }
    for(int i=0;i<root->children.size();i++){
        postorder(root->children[i]);
    }
    cout<<root->data<<" ";

}
void deleteTree(TreeNode<int> *root){
    for(int i =0;i<root->children.size();i++){
        deleteTree(root->children[i]);

    }
    delete root;
}
bool containx(TreeNode<int> *root,int x){
    if(root==NULL){
        return false;
    }
    if(root->data == x){
        return true;
    }
    bool ans = false;
    for(int i = 0;i<root->children.size();i++){
        ans = containx(root->children[i],x);
        if(ans == true){
            return true;
        }
    }
    return ans;



}












int main()
{
  TreeNode<int> *root = InputLevelwise();
   printTreeLevelwise(root);
   int n;
   cout<<"Enter number : ";
   cin>>n;

   bool ans = containx(root,n);
   if(ans){
       cout<<"false"<<endl;
   }
   else{
       cout<<"true"<<endl;
   }
   //cout<<"Preorder : "<<endl;
   //preorder(root);
  // cout<<"\nPostorder : "<<endl;
 //  postorder(root);
  // delete root;

    //int leaf = leafnode(root);
    //cout<<"Leaf nodes : "<<leaf;
   return 0;
}
