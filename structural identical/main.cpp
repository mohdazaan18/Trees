#include <iostream>
#include "tree.cpp"
#include<queue>
using namespace std;
//Approach 2
template <typename T>
class Pair{
    public :
  T sum;
  TreeNode<T>* node;
};

Pair<int> *maxChildSumhelper(TreeNode<int> *root){
    if(root == NULL){
        Pair<int> *newn = new Pair<int>();
        newn->sum = 0;
        newn->node = NULL;
        return newn;
    }
    Pair<int> *nodePair = new Pair<int>();

int maxsum = root->data;

for(int i = 0;i<root->children.size();i++){
    maxsum+=root->children[i]->data;
}

nodePair->sum = maxsum;
nodePair->node = root;
for(int i = 0;i<root->children.size();i++){
    Pair<int> *ans = maxChildSumhelper(root->children[i]);
    if(ans->sum>nodePair->sum){
        nodePair->sum = ans->sum;
        nodePair->node = ans->node;
    }
}
return nodePair;
}

TreeNode<int> *maxChildSum(TreeNode<int> *root){
 Pair<int> *answer = maxChildSumhelper(root);
 return answer->node;

}

bool areIdentical(TreeNode<int> *root1, TreeNode<int> *root2) {
if(root1 == NULL && root2 == NULL){
    return true;
}
if(root1->children.size()!=root2->children.size()){
    return false;
}
bool ans = false;
if(root1->data == root2->data){
    ans = true;
}
    for(int i = 0;i<root1->children.size();i++){
        bool child = areIdentical(root1->children[i],root2->children[i]);
        if(ans == true && child == true){
        ans = true;
         }
        else {
            ans = false;
            break;
        }
    }

return ans;
}




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



//Approach 1
/*
int sumofnodes(TreeNode<int> *root){
    if(root == NULL){
        return 0;
    }
   int sum = root->data;
   for(int i = 0;i<root->children.size();i++){
       sum += sumofnodes(root->children[i]);

   }
   return sum;
}
TreeNode<int> *maxChildSum(TreeNode<int> *root){
TreeNode<int> *maxx = root;
int maxsum = root->data;

for(int i = 0;i<root->children.size();i++){
    maxsum+=root->children[i]->data;
}
for(int i = 0;i<root->children.size();i++){
    TreeNode<int> *ans = maxChildSum(root->children[i]);
    int anssum = sumofnodes(ans);
    if(anssum>maxsum){
        maxx = ans;
    }

}
return maxx;

}
*/

int main()
{
  TreeNode<int> *root = InputLevelwise();
   printTreeLevelwise(root);
   TreeNode<int> *maxCh = maxChildSum(root);
   cout<<"Node with max child sum : "<<maxCh->data;
   /*int n;
   cout<<"Enter number : ";
   cin>>n;

   cout<<"Total nodes greater than "<<n<<": "<<countNodegreaterthanX(root,n)<<endl;
   */
   //cout<<"Preorder : "<<endl;
   //preorder(root);
  // cout<<"\nPostorder : "<<endl;
 //  postorder(root);
  // delete root;

    //int leaf = leafnode(root);
    //cout<<"Leaf nodes : "<<leaf;
   return 0;
}
