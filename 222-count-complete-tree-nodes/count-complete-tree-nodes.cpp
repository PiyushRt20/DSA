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
            return 0;
        }
        int lh = getLeftHeight(root);
        int rh = getRightHeight(root);
        if(lh == rh){
            return (1<<lh) - 1;             //(1<<lh) 2 ki power lh  agr lh == rh 
        }
        return 1 + solve(root->left) + solve(root->right);          //lh != rh
    }
    int getLeftHeight(TreeNode* root){
        int ht = 0;
        while(root != NULL){
            ht++;
            root = root->left;
        }
        return ht;
    }
    int getRightHeight(TreeNode* root){
        int ht = 0;
        while(root != NULL){
            ht++;
            root = root->right;
        }
        return ht;
    }
    int countNodes(TreeNode* root) {
        // if(root == NULL){
        //     return 0;
        // }
        // int leftN = countNodes(root->left);
        // int rightN = countNodes(root->right);
        // return 1 + leftN + rightN;

        //Using the property of complete binary tree (O((log2n)2))
        if(root == NULL){
            return 0;
        }
        return solve(root);
    }
};