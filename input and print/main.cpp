#include <iostream>
#include<vector>
#include"tree.cpp"
using namespace std;

TreeNode<int> *Input(){
    int rootdata;
    cout<<"Enter data : "<<endl;
    cin>>rootdata;
    TreeNode<int> *root = new TreeNode<int>(rootdata);
    int n;
    cout<<"Enter Number of child"<<endl;
    cin>>n;
    for(int i = 0;i<n;i++){
        TreeNode<int> *child = Input();
        root->children.push_back(child);
    }
    return root;
}

void printTree(TreeNode<int> *root){
    if(root == NULL){
        return;
    }
    cout<<root->data<< ":";
    for(int  i = 0;i<root->children.size();i++){
        cout<<root->children[i]->data<<",";

    }
    cout<<endl;
    for(int i = 0;i<root->children.size();i++){
        printTree(root->children[i]);
    }


}


int main()
{
   /* TreeNode<int> *root = new TreeNode<int>(1);
    TreeNode<int> *node1 = new TreeNode<int>(2);
    TreeNode<int> *node2 = new TreeNode<int>(3);
    root->children.push_back(node1);
    root->children.push_back(node2);
    */
    TreeNode<int> *root = Input();

   printTree(root);

    return 0;
}
