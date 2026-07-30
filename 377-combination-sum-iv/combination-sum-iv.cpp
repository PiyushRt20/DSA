class Solution {
public:
    int solve(int tar, vector<int>& nums, vector<int>& dp){
        if(tar < 0) return 0;
        if(tar == 0) return 1;
        if(dp[tar] != -1){
            return dp[tar];
        }
        int cnt = 0;
        for(auto it : nums){
            cnt += solve(tar - it , nums, dp);
        }
        return dp[tar] = cnt;
    }
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(target+1, -1);
        return solve(target, nums, dp);
    }
};