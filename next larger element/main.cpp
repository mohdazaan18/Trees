#include <iostream>
#include <queue>
#include "TreeNode.cpp"
using namespace std;

TreeNode<int>* takeInputLevelWise() {
	int rootData;
	cout << "Enter root data" << endl;
	cin >> rootData;
	TreeNode<int>* root = new TreeNode<int>(rootData);

	queue<TreeNode<int>*> pendingNodes;

	pendingNodes.push(root);
	while (pendingNodes.size() != 0) {
		TreeNode<int>* front = pendingNodes.front();
		pendingNodes.pop();
		cout << "Enter num of children of " << front->data << endl;
		int numChild;
		cin >> numChild;
		for (int i = 0; i < numChild; i++) {
			int childData;
			cout << "Enter " << i << "th child of " << front->data << endl;
			cin >> childData;
			TreeNode<int>* child = new TreeNode<int>(childData);
			front->children.push_back(child);
			pendingNodes.push(child);
		}
	}
	return root;
}

TreeNode<int>* takeInput() {
	int rootData;
	cout << "Enter data" << endl;
	cin >> rootData;
	TreeNode<int>* root = new TreeNode<int>(rootData);

	int n;
	cout << "Enter num of children of " << rootData << endl;
	cin >> n;
	for (int i = 0; i < n; i++) {
		TreeNode<int>* child = takeInput();
		root->children.push_back(child);
	}
	return root;
}

void printTree(TreeNode<int>* root) {
	if (root == NULL) {
		return;
	}

	cout << root->data << ":";
	for (int i = 0; i < root->children.size(); i++) {
		cout << root->children[i]->data << ",";
	}
	cout << endl;
	for (int i = 0; i < root->children.size() ; i++) {
		printTree(root->children[i]);
	}
}

TreeNode<int> *getNextLargerElement(TreeNode<int> *root,int x){
if(root == NULL){
        return root;
    }
   TreeNode<int> *ans = NULL;
   if(root->data > x){
       ans = root;
   }
   for(int i = 0;i<root->children.size();i++){
       TreeNode<int> *smallans = getNextLargerElement(root->children[i],x);

       if(ans == NULL){
           ans = smallans;
       }

          else if(ans->data> smallans->data){
               ans = smallans;
           }

   }
   return ans;

}

void printTreeLevelwise(TreeNode<int> *root){
    if(root == NULL){
        return;
    }
    queue<TreeNode<int>*> q;

    q.push(root);
    while(!q.empty()){
        TreeNode<int> *front = q.front();
        cout<<front->data<<":";
        q.pop();
        for(int i=0;i<front->children.size();i++){
            cout<<front->children[i]->data<<",";
            q.push(front->children[i]);

        }
        cout<<endl;
    }

}


int main() {
	/*TreeNode<int>* root = new TreeNode<int>(1);
	TreeNode<int>* node1 = new TreeNode<int>(2);
	TreeNode<int>* node2 = new TreeNode<int>(3);
	root->children.push_back(node1);
	root->children.push_back(node2);
	*/
	TreeNode<int>* root = takeInputLevelWise();
	printTreeLevelwise(root);
	cin>>n;
	TreeNode<int> *ans = getNextLargerElement(root,n);
	cout<<ans->data<<endl;


}

