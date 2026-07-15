class Solution {
public:
    bool solve(int idx, int tar, vector<int>& nums, vector<vector<int>>&dp){
        if(tar == 0) return true;
        if(idx == 0){
            return nums[0] == tar;
        }
        if(dp[idx][tar] != -1){
            return dp[idx][tar];
        }
        bool notPick = solve(idx-1, tar, nums, dp);
        bool pick = false;
        if(tar >= nums[idx]){
            pick = solve(idx-1, tar - nums[idx], nums, dp);
        }
        return dp[idx][tar] = pick || notPick;
    }
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum % 2 != 0){
            return false;
        }
        int tar = sum /2;
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(tar+1, -1));
        return solve(n-1, tar, nums, dp);
    }
};