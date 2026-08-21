class Solution {
public:
    int solve(int idx, string &s, int n, vector<int>& dp){
        if(idx > n){
            return 0;
        }
        if(idx == n) return 1;
        if(dp[idx] != -1){
            return dp[idx];
        }
        if(s[idx] == '0') return 0;
        int one = solve(idx+1, s, n, dp);
        int two = 0;
        if(s[idx] < '2'){
            two = solve(idx+2, s, n, dp);
        }
        else if(s[idx] == '2' && idx+1 < n && s[idx+1] < '7'){
            two = solve(idx+2, s, n, dp);
        }
        return dp[idx] =  one + two;
    }
    int numDecodings(string s) {
        int n = s.size();
        vector<int> dp(n, -1);
        return solve(0,s, n, dp);
    }
};