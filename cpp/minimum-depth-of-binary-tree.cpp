#include <iostream>
#include <cmath>

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
    int minDepthNotRoot(TreeNode *root)
    {
        if(root == nullptr)
            return -1;
        else if(root->left == nullptr && root->right == nullptr)
            return 1;
        else
        {
            int minNum = 1;
            int minLeft = minDepthNotRoot(root->left);
            int minRight = minDepthNotRoot(root->right);
            if(minLeft == -1 && minRight == -1)
                minNum = 1;
            else if(minLeft != -1 && minRight == -1)
                minNum = minLeft + 1;
            else if(minLeft == -1 && minRight != -1)
                minNum = minRight + 1;
            else
                minNum = min(minLeft, minRight) + 1;
            
            return minNum;
        }
    }
public:
    int minDepth(TreeNode *root)
    {
        if(root == nullptr)
            return 0;
        else
            return minDepthNotRoot(root);
    }
};

int main()
{
    Solution test;

    return 0;
}