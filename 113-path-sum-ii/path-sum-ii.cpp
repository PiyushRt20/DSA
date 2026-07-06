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
    void solve(TreeNode* root, int sum, vector<int>ds, vector<vector<int>>&ans, int targetSum){
        if(root == NULL ){
            return;
        }
        sum += root->val;
        ds.push_back(root->val);
        if(sum == targetSum && root->left == NULL && root->right == NULL){
            ans.push_back(ds);
            return;
        }
        solve(root->left, sum, ds, ans, targetSum);
        solve(root->right, sum, ds, ans, targetSum);
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        int sum = 0;
        vector<vector<int>>ans;
        vector<int>ds;
        solve(root, sum, ds, ans, targetSum);
        return ans;
    }
};