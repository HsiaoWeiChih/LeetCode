#include <iostream>
#include <vector>

using namespace std;

// Definition for a binary tree node.
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
public:
    vector<int> preorderTraversal(TreeNode *root)
    {
        vector<int> result;
        if(root == nullptr)
            return result;
        else
        {
            vector<int> leftVec = preorderTraversal(root->left);
            vector<int> rightVec = preorderTraversal(root->right);

            result.push_back(root->val);

            if(leftVec.size() > 0)
                result.insert(result.end(), leftVec.begin(), leftVec.end());

            if(rightVec.size() > 0)
                result.insert(result.end(), rightVec.begin(), rightVec.end());

            return result;
        }
    }
};