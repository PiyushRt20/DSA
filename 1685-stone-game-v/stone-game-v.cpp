class Solution {
public:
    int solve(int l, int r, vector<int>& preSum, vector<vector<int>>& dp){
        if(l >= r ){
            return 0;
        }
        if(dp[l][r] != -1){
            return dp[l][r];
        }
        int score = 0;
        for(int mid = l; mid <= r-1; mid++){
            int leftSum = preSum[mid] - (l-1 >= 0 ? preSum[l-1] : 0);
            int rightSum = preSum[r] - preSum[mid];
            if(leftSum < rightSum){
                score = max(score, leftSum + solve(l, mid, preSum, dp));
            }
            else if(leftSum > rightSum){
                score = max(score, rightSum + solve(mid+1, r, preSum, dp));
            }
            else{
                score = max({score, leftSum + solve(l, mid, preSum, dp), rightSum + solve(mid+1, r, preSum, dp)});
            }
        }
        return dp[l][r] = score;
    }
    int stoneGameV(vector<int>& stoneValue) {
        int n = stoneValue.size();
        vector<int> preSum(n);
        preSum[0] = stoneValue[0];
        for(int i =1; i<n; i++){
            preSum[i] = preSum[i-1] + stoneValue[i];
        }
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return solve(0, n-1, preSum, dp);
    }
};