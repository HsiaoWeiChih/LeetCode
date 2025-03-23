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
        TreeNode* sortedArrayToBST(vector<int>& nums) {        
            TreeNode* result = createTree(nums, 0, nums.size()-1);
            
            return result;
        }
        TreeNode* createTree(vector<int>& nums, int start, int end)
        {
            TreeNode* node;
            if(start > end)
                return nullptr;
            else
            {
                int mid = (start+end) / 2;
                node = new TreeNode(nums[mid]);
                node->left = createTree(nums, start, mid-1);
                node->right = createTree(nums, mid+1, end);
            }
            return node;
        }
    };