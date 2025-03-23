#include <iostream>
#include <stack>

using namespace std;


//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
    public:
        bool isValidBST(TreeNode* root) {
            
            stack<int> myStack;
            
            storeToStack(root, myStack);
            
            int temp = myStack.top();
            myStack.pop();
            while(!myStack.empty()){
                if(temp <= myStack.top()){
                    return false;
                }
                else{
                    temp = myStack.top();
                    myStack.pop();
                }
            }
            return true;
           
        }
        void storeToStack(TreeNode* root, stack<int> &myStack){
            
            TreeNode* node = root;
            /*
            if(node->left == NULL && node->right == NULL){
                myStack.push(node->val);
            }
            else if(node->left == NULL){
                myStack.push(node->val);
                storeToStack(node->right, myStack);
            }
            else if(node->right == NULL){
                storeToStack(node->left, myStack);
            }*/
            if(node != NULL){
            storeToStack(node->left, myStack);
            myStack.push(node->val);
            storeToStack(node->right, myStack);
            }
            
            
        }
    };