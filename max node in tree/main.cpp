#include <iostream>
#include<vector>
#include<queue>
#include"tree.cpp"
using namespace std;

TreeNode<int> *Input(){
    int data;
    cout<<"Enter data :"<<endl;
    cin>>data;
    TreeNode<int> *root = new TreeNode<int>(data);
    int n;
    cout<<"Enter childer of this node"<<endl;
    cin>>n;
    for(int i = 0;i<n;i++){
        TreeNode<int> *child =Input();
        root->children.push_back(child);
    }
    return root;
}

TreeNode<int> *InputLevelWise(){
    int rootdata;
    cout<<"Enter Data : "<<endl;
    cin>>rootdata;
    TreeNode<int> *root = new TreeNode<int>(rootdata);
    queue<TreeNode<int>*> q;
    q.push(root);
    while(q.size()!=0){
        TreeNode<int> *front = q.front();
        q.pop();
        cout<<"No. of childen of "<<front->data<<endl;
        int n;
        cin>>n;
        for(int i=0;i<n;i++){
            int childdata;
            cout<<i<<"th child of "<<front->data<<endl;
            cin>>childdata;
            TreeNode<int> *child = new TreeNode<int>(childdata);
            front->children.push_back(child);
            q.push(child);
        }
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
void printLevelWise(TreeNode<int> * root){

    queue<TreeNode<int>*> pendingNodes;
    pendingNodes.push(root);
    while(pendingNodes.size()!=0){
        TreeNode<int> *front = pendingNodes.front();
        pendingNodes.pop();
        cout<<front->data<<":";
        for(int i = 0;i<front->children.size();i++){
            if(i<front->children.size()){
            cout<<front->children[i]->data<<",";
            }
            else {
                 cout<<front->children[i]->data;
            }
            pendingNodes.push(front->children[i]);
        }
        cout<<endl;
    }
}
int countofNodes(TreeNode<int>* root){
    if(root == NULL){
        return 0;
    }
    int ans = 0;
    for(int i = 0;i<root->children.size();i++){
        ans = ans + countofNodes(root->children[i]);
    }

    return 1+ans;
}
TreeNode<int> *maxofallnodes(TreeNode<int> *root){
    if(root == NULL){
        return 0;
    }
   TreeNode<int> *max = root;

   for(int i = 0;i<root->children.size();i++){
       TreeNode<int> *maxofallchild = maxofallnodes(root->children[i]);
       if(maxofallchild->data>max->data){
           max = maxofallchild;
       }
   }
  return max;
}

int main()
{
  TreeNode<int> *root = new TreeNode<int>(1);
    TreeNode<int> *node1 = new TreeNode<int>(2);
    TreeNode<int> *node2 = new TreeNode<int>(3);
    root->children.push_back(node1);
    root->children.push_back(node2);



   printTree(root);
   cout<<(maxofallnodes(root))->data;

    return 0;
}
