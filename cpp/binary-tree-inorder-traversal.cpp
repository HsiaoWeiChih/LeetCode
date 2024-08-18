#include <iostream>
#include <vector>

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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> v;
        if(root == nullptr)
            return v;
        
        if(root->left != nullptr)
        {
            vector<int> tmpV = inorderTraversal(root->left);
            v.insert(v.end(), tmpV.begin(), tmpV.end());
        }
        if(root != nullptr)
            v.push_back(root->val);
        if(root->right != nullptr)
        {
            vector<int> tmpV = inorderTraversal(root->right);
            v.insert(v.end(), tmpV.begin(), tmpV.end());
        }
        return v;
    }
};