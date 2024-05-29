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

void in_order(TreeNode* root, vector<int> &arr){
    if(root == NULL) return ;
    
    in_order(root->left, arr);
    arr.push_back(root->data);
    in_order(root->right, arr);
}

vector<int> InOrderTraversal(TreeNode* root){
    vector<int>arr;
    in_order(root, arr);
    return arr;
}
int main(){
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(6);

    vector<int> result = InOrderTraversal(root);
    for(int val : result){
        cout<<val<<" ";
    }
    cout<<endl;



    return 0;
}    