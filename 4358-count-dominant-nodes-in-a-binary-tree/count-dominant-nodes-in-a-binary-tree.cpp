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
    int solve(TreeNode* root, int& cnt){
        if(root == NULL){
            return 0;
        }
        int leftMax = solve(root->left, cnt);
        int rightMax = solve(root->right, cnt);
        int maxi = max(leftMax , rightMax);
        if(root->val >=  maxi){
            cnt++;
        }
        return max({root->val, leftMax, rightMax});
        
    }
    int countDominantNodes(TreeNode* root) {
        int cnt = 0;
        solve(root, cnt);
        return cnt;
    }
};