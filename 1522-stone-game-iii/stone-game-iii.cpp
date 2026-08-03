class Solution {
public:
    int n;
    int solve(int i, vector<int>& stoneValue, vector<int> &dp){
        if(i >= n){
            return 0;
        }
        if(dp[i] != -1){
            return dp[i];
        }
        //if take one
        int ans = stoneValue[i] - solve(i+1, stoneValue, dp);
        //if take two
        if(i+1 < n){
            ans = max(ans, stoneValue[i] + stoneValue[i+1] - solve(i+2, stoneValue, dp));
        }
        //if take three
        if(i+2 < n){
            ans = max(ans, stoneValue[i] + stoneValue[i+1] + stoneValue[i+2] - solve(i+3, stoneValue, dp));
        }
        return dp[i]  = ans;
    }
    string stoneGameIII(vector<int>& stoneValue) {
        n = stoneValue.size();
        vector<int> dp(n, -1);
        int diff = solve(0, stoneValue, dp);
        if(diff == 0) return "Tie";
        return diff > 0 ? "Alice" : "Bob";
    }
};