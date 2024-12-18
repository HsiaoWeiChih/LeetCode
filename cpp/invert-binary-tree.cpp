#include <iostream>

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
private:
    void invertTreeLoop(TreeNode* root)
    {
        if(root != nullptr)
        {
            TreeNode* tmp = root->left;
            root->left = root->right;
            root->right = tmp;
            invertTreeLoop(root->left);
            invertTreeLoop(root->right);
        }
    }
public:
    TreeNode* invertTree(TreeNode* root) {
        if(root == nullptr || (root->left == nullptr && root->right == nullptr))
            return root;

        TreeNode* tmp = root;

        invertTreeLoop(tmp);

        return root;
    }
};