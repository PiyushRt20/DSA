class Solution {
public:
    void solve(int idx, int n, vector<int>&ds, vector<vector<int>>&ans, vector<int>&candidates, int tar){
        if(tar < 0 ) return;
        if(idx == n){
            if(tar == 0){
                ans.push_back(ds);
            }
            return;
        }
        ds.push_back(candidates[idx]);
        solve(idx, n, ds, ans, candidates, tar - candidates[idx]);
        ds.pop_back();
        solve(idx+1, n, ds, ans, candidates, tar);
        
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int>ds;
        vector<vector<int>> ans;
        int n = candidates.size();
        solve(0, n, ds, ans, candidates, target);
        return ans;
    }
};