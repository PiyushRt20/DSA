/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<int, vector<int>> mpp;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int n = q.size();
            for(int i =0; i<n; i++){
                auto node = q.front();
                q.pop();
                if(node->left != NULL){
                    mpp[node->val].push_back(node->left->val);
                    mpp[node->left->val].push_back(node->val);
                    q.push(node->left);
                }
                if(node->right != NULL){
                    mpp[node->val].push_back(node->right->val);
                    mpp[node->right->val].push_back(node->val);
                    q.push(node->right);
                }
            }
        }
        // for(auto it : mpp){
        //     cout<<it.first<<"->";
        //     for(auto i : it.second){
        //         cout<<i<<" ";
        //     }
        //     cout<<endl;
        // }
        vector<int> ans;
        unordered_set<int> vis;
        queue<pair<int , int>> qu;
        qu.push({target->val, 0});
        vis.insert(target->val);
        while(!qu.empty()){
            auto [node, cnt] = qu.front();
            qu.pop();
            if(cnt == k){
                ans.push_back(node);
                continue;
            }
            for(auto it : mpp[node]){
                if(!vis.count(it)){
                    qu.push({it, cnt+1});
                    vis.insert(it);
                }
            }
        }
        return ans;
    }
};