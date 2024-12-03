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
    int countNodes(TreeNode* root) {
        if(root == nullptr)
            return 0;
        else if(root->left == nullptr && root->right == nullptr)
            return 1;

        int count = 1;
        if(root->left != nullptr)
            count += countNodes(root->left);
        
        if(root->right != nullptr)
            count += countNodes(root->right);

        return count;
    }
};

int main()
{
    Solution test;
    return 0;
}