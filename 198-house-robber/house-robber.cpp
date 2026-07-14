class Solution {
public:
    // int solve(int idx, vector<int>&nums, vector<int>&dp){
    //     if(idx < 0 ) return 0;
    //     if(idx == 0){
    //         return nums[0];
    //     }
    //     if(dp[idx] != -1){
    //         return dp[idx];
    //     }
    //     int notPick = solve(idx-1, nums, dp);
    //     int pick = nums[idx] + solve(idx-2, nums, dp);
    //     return dp[idx] = max(pick, notPick);
    // }
    int rob(vector<int>& nums) {
        int n = nums.size();
        // vector<int> dp(n, -1);
        // return solve(n-1, nums, dp);

        vector<int> dp(n, 0);
        dp[0] = nums[0];
        for(int i =1; i<n; i++){
            int notPick = dp[i-1];
            int pick = nums[i];
            if(i > 1){
                pick += dp[i-2];
            }
            
            dp[i] = max(pick, notPick);
        }
        return dp[n-1];
    }

};