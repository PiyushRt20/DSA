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
    void solve(vector<string>& ans, TreeNode* root, string ds){
        if(root == NULL) return;
        if(root->left == NULL && root->right == NULL){
            ds += to_string(root->val);
            ans.push_back(ds);
            return;
        }
        ds += to_string(root->val);
        ds += "->";
        solve(ans, root->left, ds);
        solve(ans, root->right, ds);
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        solve(ans, root, "");
        return ans;
    }
};