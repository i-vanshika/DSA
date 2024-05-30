#include <iostream>
#include <vector>
#include <queue> 
using namespace std;

class TreeNode {
    public:
    int val; 
    TreeNode* left; 
    TreeNode* right;

    // Default constructor for TreeNode
    TreeNode(){
        val = 0;
        left = nullptr;
        right = nullptr;
    }

    TreeNode(int x){
        val = x;
        left = nullptr;
        right = nullptr;
    }

    // Constructor with value, left child, and right child
    TreeNode(int x, TreeNode* left, TreeNode* right){
        val = x;
        left = left;
        right = right;
    }
};

    // Function to perform level-order traversal of a binary tree
    vector<vector<int>> levelOrder(TreeNode* root) {

    queue<TreeNode*> q;
        vector<vector<int>> ans;

        if(root == NULL) return ans;
        q.push(root);

        while(!q.empty()){
            int size = q.size();
            vector<int> level;
            for(int i=0; i<size; i++){
                
                TreeNode* node = q.front();
                q.pop();
                level.push_back(node->val);

                if(node->left != nullptr){
                    q.push(node->left);
                }
                if(node->right != nullptr){
                    q.push(node->right);
                }

            }
            ans.push_back(level);
        }
        return ans;
    }

 


int main() {
    
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    return 0;
}