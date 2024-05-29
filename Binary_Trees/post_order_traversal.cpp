#include<iostream>
#include<vector>
using namespace std;
class TreeNode{
    public:
    int data;
    TreeNode* left;
    TreeNode* right;

    public:
    TreeNode(int val){
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

void postorder(TreeNode* root, vector<int> &arr){
    if(root == NULL) return ;

    postorder(root->left, arr);
    postorder(root->right, arr);
    arr.push_back(root->data);

}

vector<int> PostOrderTraversal(TreeNode* root){
    vector<int>arr;
    postorder(root,arr);
    return arr;
}
int main(){
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(6);

    vector<int> result = PostOrderTraversal(root);
    for(int val : result){
        cout<<val<<" ";
    }
}