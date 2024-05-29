#include<iostream>
#include<vector>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;

    public:
    Node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }

};
// Function to perform preorder traversal of the tree and store values in 'arr'
void preorder(Node* root, vector<int> &arr){

    if(root == nullptr) return;

    arr.push_back(root->data);  // printing root
    preorder(root->left, arr);  // left
    preorder(root->right, arr); //right

}
// Function to initiate preorder traversal and return the resulting vector
vector<int> PreOrderTraversal(Node* root){
    // Create an empty vector to store preorder traversal values
    vector<int> arr;
    // Call the preorder traversal function
    preorder(root, arr);
    // Return the resulting vector containing preorder traversal values
    return arr;
} 

int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    // Getting preorder traversal
    vector<int> result = PreOrderTraversal(root);
    cout << "Preorder Traversal: ";

    // Output each value in the preorder traversal result
    for(int val : result ){
        cout<<val<<" ";
    }
    return 0;
}