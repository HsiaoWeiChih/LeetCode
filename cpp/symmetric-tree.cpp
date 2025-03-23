#include <iostream>

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
        bool isSymmetric(TreeNode* root) {
            
            int ans = 0;
            
            if(root->left == NULL && root->right != NULL){
                ans++;
            }
            else if(root->left != NULL && root->right == NULL){
                ans++;
            }
            else if(root->left == NULL && root->right == NULL){
                return true;
            }
            else{
                isLRSame(root->left, root->right, ans);
            }
            
            if(ans>0)
                return false;
            else
                return true;
        }
        void isLRSame(TreeNode* left, TreeNode* right, int &ans){
            if(left->val != right->val){
                ans++;
            }
            else{
                if(left->left == NULL && right->right != NULL){
                    ans++;
                }
                else if(left->left != NULL && right->right == NULL){
                    ans++;
                }
                else if(left->right == NULL && right->left != NULL){
                    ans++;
                }
                else if(left->right != NULL && right->left == NULL){
                    ans++;
                }
                else if(left->left != NULL && left->right != NULL){  //implies rr != NULL && rl != NULL
                    isLRSame(left->left, right->right, ans);
                    isLRSame(left->right, right->left, ans);
                }
                else if(left->left != NULL){
                    isLRSame(left->left, right->right, ans);
                }
                else if(left->right != NULL){
                    isLRSame(left->right, right->left, ans);
                }
            }
        }
    };