#include <iostream>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
private:
    bool findLeaf(TreeNode *root, int pathLength, int& targetSum)
    {
        if(root->left == nullptr && root->right == nullptr)
        {
            return pathLength + root->val == targetSum;
        }
        else if(root->left != nullptr && root->right == nullptr)
        {
            return findLeaf(root->left, pathLength + root->val, targetSum);
        }
        else if(root->left == nullptr && root->right != nullptr)
        {
            return findLeaf(root->right, pathLength + root->val, targetSum);
        }
        else
        {
            bool bLeftResult = findLeaf(root->left, pathLength + root->val, targetSum);
            bool bRightResult = findLeaf(root->right, pathLength + root->val, targetSum);
            return bLeftResult || bRightResult;
        }
    }

public:
    bool hasPathSum(TreeNode *root, int targetSum)
    {
        bool bResult = false;
        if(root == nullptr)
            return false;
        else
            bResult = findLeaf(root, 0, targetSum);
        
        return bResult;
    }
};

int main()
{
    Solution test;

    return 0;
}