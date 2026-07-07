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
    TreeNode* helper(TreeNode* node){
        if(node->left == NULL && node->right == NULL){
            return NULL;
        }
        if(node->left == NULL){
            return node->right;
        }
        if(node->right == NULL){
            return node->left;
        }
        TreeNode* rightChild = node->right;
        TreeNode* leftKaLastRight = findRight(node->left);
        leftKaLastRight->right = rightChild;
        return node->left;
    }
    TreeNode* findRight(TreeNode* node){
        TreeNode* curr = node;
        while(curr->right != NULL){
            curr = curr->right;
        }
        return curr;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == NULL){
            return root;
        } 
        if(root->val == key){
            return helper(root);
        }
        TreeNode* curr = root;
        while(curr != NULL){
            if(curr->val < key){
                if(curr->right != NULL && curr->right->val == key){
                    curr->right = helper(curr->right);
                    break;
                }
                curr = curr->right;
            }
            else{
                if(curr->left != NULL && curr->left->val == key){
                    curr->left = helper(curr->left);
                    break;
                }
                curr = curr->left;
            }
        }
        return root;
    }
};