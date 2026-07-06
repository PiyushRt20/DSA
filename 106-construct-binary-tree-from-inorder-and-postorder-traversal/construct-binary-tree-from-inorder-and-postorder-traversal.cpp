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
    TreeNode* solve(vector<int>& postorder, vector<int>& inorder, int start, int end, int& idx, unordered_map<int, int>& inorderMap){
        if(start > end){
            return NULL;
        }
        int val = postorder[idx];
        idx--;
        int i = inorderMap[val];
        TreeNode* root = new TreeNode(val);
        root->right = solve(postorder, inorder, i+1, end, idx, inorderMap);
        root->left = solve(postorder, inorder, start, i-1, idx, inorderMap);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = postorder.size();
        unordered_map<int, int> inorderMap;
        for(int i =0; i<n; i++){
            inorderMap[inorder[i]] = i;
        }
        int idx = n-1;
        return solve(postorder, inorder, 0, n-1, idx, inorderMap);
    }
};