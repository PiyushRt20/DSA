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
    TreeNode* solve(vector<int>& preorder, vector<int>& inorder, int start, int end, int& idx, unordered_map<int, int>& inorderMap){
        if(start > end){
            return NULL;
        }
        int val = preorder[idx];
        idx++;
        int i = inorderMap[val];
        TreeNode* root = new TreeNode(val);
        root->left = solve(preorder, inorder, start, i-1, idx, inorderMap);
        root->right = solve(preorder, inorder, i+1, end, idx, inorderMap);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        unordered_map<int, int> inorderMap;
        for(int i =0; i<n; i++){
            inorderMap[inorder[i]] = i;
        }
        int idx = 0;
        return solve(preorder, inorder, 0, n-1, idx, inorderMap);
    }
};