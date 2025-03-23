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
        vector<vector<int>> levelOrder(TreeNode* root) {
            vector<vector<int>> result;
            
            vector<TreeNode*> nodes;
            
            if(root != nullptr)
                nodes.push_back(root);
            
            while(nodes.size() != 0)
            {
                vector<int> nums = getChildValue(nodes);
                result.push_back(nums);
                
                vector<TreeNode*> tmp;
                for(int i=0; i<nodes.size(); i++)
                {
                    if(nodes[i]->left != nullptr)
                        tmp.push_back(nodes[i]->left);
                    if(nodes[i]->right)
                        tmp.push_back(nodes[i]->right);
                }
                
                nodes.clear();
                
                nodes = tmp;
            }
            
            return result;
            
        }
        
        vector<int> getChildValue(vector<TreeNode*> nodes)
        {
            vector<int> nums;
            for(int i=0; i<nodes.size(); i++)
            {
                nums.push_back(nodes[i]->val);
            }
            return nums;
        }
    };