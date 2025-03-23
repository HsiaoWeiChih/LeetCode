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
        int maxDepth(TreeNode* root) {
            TreeNode *temp = root;
            
            if(root == NULL)
                return 0;
            
            int dis = 1;
            int disleft = dis;
            int disright = dis;
            int max = 1;
            
            if(root->left != NULL){
                disleft++;
                max = maxnum(disleft, max);
                nextnode(root->left, root->right, disleft, max);
            }
            if(root->right != NULL){
                disright++;
                max = maxnum(dis, max);
                nextnode(root->left, root->right, disright, max);
            }
            return max; 
        }
        void nextnode(TreeNode* left, TreeNode* right, int dis, int &max)
        {
            int disleft = dis;
            int disright = dis;
            if(left != NULL){
                disleft++;
                max = maxnum(dis, max);
                nextnode(left->left, left->right, disleft, max);
            }
            if(right != NULL){
                disright++;
                max = maxnum(dis, max);
                nextnode(right->left, right->right, disright, max);
            }
                         
        }
        int maxnum(int a, int b){
            if(a >= b)
                return a;
            else
                return b;
        }
    };