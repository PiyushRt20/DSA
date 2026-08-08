class Solution {
public:
    void solve(int n, vector<int>&ds, vector<vector<int>>&ans, vector<int>&nums, unordered_map<int, int> &mpp){
        if(ds.size() == n){
            ans.push_back(ds);
            return;
        }
        for(int i =0; i<n; i++){
            if(mpp[nums[i]] == 1){
                continue;
            }
            ds.push_back(nums[i]);
            mpp[nums[i]]++;
            solve(n, ds, ans, nums, mpp);
            ds.pop_back();
            mpp[nums[i]]--;
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> mpp;
        vector<int>ds;
        vector<vector<int>>ans;
        solve(n, ds, ans, nums, mpp);
        return ans;
    }
};