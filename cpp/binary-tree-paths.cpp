#include <iostream>
#include <vector>
#include <string>

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
    vector<string> currentRoot(TreeNode* current, string path)
    {
        vector<string> result;
        path += "->" + to_string(current->val);
        if(current->left == nullptr && current->right == nullptr)
        {
            result.push_back(path);
        }
        else
        {
            if(current->left != nullptr)
            {
                vector<string> tmp = currentRoot(current->left, path);
                result.insert(result.end(), tmp.begin(), tmp.end());
            }
            if(current->right != nullptr)
            {
                vector<string> tmp = currentRoot(current->right, path);
                result.insert(result.end(), tmp.begin(), tmp.end());
            }
        }
        return result;
    }
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> result;
        string path = to_string(root->val);
        if(root->left == nullptr && root->right == nullptr)
        {
            result.push_back(path);
        }
        else
        {
            if(root->left != nullptr)
            {
                vector<string> tmp = currentRoot(root->left, path);
                result.insert(result.end(), tmp.begin(), tmp.end());
            }
            if(root->right != nullptr)
            {
                vector<string> tmp = currentRoot(root->right, path);
                result.insert(result.end(), tmp.begin(), tmp.end());
            }
        }
        return result;
    }
};