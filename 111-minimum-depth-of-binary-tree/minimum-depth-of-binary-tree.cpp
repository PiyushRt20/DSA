/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int solve(TreeNode* root){
        if(root == NULL){
            return 1e9;
        }
        if(root->left == NULL && root->right == NULL){
            return 1;
        }
        int leftH = solve(root->left);
        int rightH = solve(root->right);
        return 1 + min(leftH, rightH);
    }
    int minDepth(TreeNode* root) {
        if(root == NULL){
            return 0;
        }
        return solve(root);
    }
};