class Solution {
public:
    int n;
    int M = 1e9+7;
    long long solve(int idx, int gcd1, int gcd2, vector<int>&nums, vector<vector<vector<int>>>& dp){
        if(idx == n){
            if(gcd1 == gcd2 && gcd1 != 0){
                return 1;
            }
            return 0;
        }
        if(dp[idx][gcd1][gcd2] != -1){
            return dp[idx][gcd1][gcd2];
        }
        int notTake = solve(idx+1, gcd1, gcd2, nums, dp);
        int seq1 = solve(idx+1, gcd(gcd1, nums[idx]),gcd2, nums, dp);
        int seq2 = solve(idx+1, gcd1, gcd(gcd2, nums[idx]), nums, dp);
        return dp[idx][gcd1][gcd2] = ((notTake + seq1) % M + seq2) % M;
    }
    int subsequencePairCount(vector<int>& nums) {
        n = nums.size();
        int maxi = *max_element(nums.begin(), nums.end());
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(maxi+1, vector<int>(maxi+1, -1)));
        return solve(0, 0, 0, nums, dp);
    }
};