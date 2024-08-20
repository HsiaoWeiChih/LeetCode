#include <iostream>
#include <math.h>

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
private:
    int getDept(TreeNode* root) {
        if(root == nullptr)
            return 0;
        
        int leftDept = getDept(root->left);
        int rightDept =  getDept(root->right);

        if(leftDept == -1 || rightDept == -1 || abs(leftDept - rightDept) > 1)
            return -1;

        return max(leftDept, rightDept) + 1;
    }
public:
    bool isBalanced(TreeNode* root) {
        if(root == nullptr)
            return true;
        
        if(getDept(root) == -1)
            return false;
        else
            return true;
    }
};