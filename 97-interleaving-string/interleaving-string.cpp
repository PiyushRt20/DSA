class Solution {
public:
    bool solve(int i, int j, string& s1, string& s2, string& s3, vector<vector<int>>&dp){
        if(i + j + 1 < 0){
            return true;
        }
        if(dp[i+1][j+1] != -1){
            return dp[i+1][j+1];
        }
        int k = i + j +1;
        bool p = false;
        bool q = false;
        if(i >= 0 && s3[k] == s1[i]){
            p = solve(i-1, j, s1, s2, s3, dp);
        }
        if(j >= 0 && s3[k] == s2[j]){
            q = solve(i, j-1, s1, s2, s3, dp);
        }
        return dp[i+1][j+1] =  p || q;
    }
    bool isInterleave(string s1, string s2, string s3) {
        int n = s1.size();
        int m = s2.size();
        int o = s3.size();
        if(n + m != o) return false;
        vector<vector<int>>dp(n+1, vector<int>(m+1, -1));
        return solve(n-1, m-1, s1, s2, s3, dp);
    }
};