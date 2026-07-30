class Solution {
public:
    int solve(int idx, int n, int m, vector<vector<vector<int>>>& dp, vector<pair<int, int>>& vp){
        if(idx == 0){
            if(n >= vp[0].first && m >= vp[0].second){
                return 1;
            }
            return 0;
        }
        if(dp[idx][n][m] != -1){
            return dp[idx][n][m];
        }
        int notPick = 0 + solve(idx-1, n, m, dp, vp);
        int pick = 0;
        if(n >= vp[idx].first && m >= vp[idx].second){
            pick = 1 + solve(idx-1, n - vp[idx].first, m - vp[idx].second, dp, vp);
        }
        return dp[idx][n][m] = max(pick, notPick);
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        int s = strs.size();
        vector<pair<int, int>> vp;
        for(int i =0; i<s; i++){
            int ones = 0;
            int zeroes = 0;
            for(auto it : strs[i]){
                if(it == '0'){
                    zeroes++;
                }
                else{
                    ones++;
                }
            }
            vp.push_back({ones, zeroes});
        }
        vector<vector<vector<int>>> dp(s, vector<vector<int>>(n+1, vector<int>(m+1, -1)));
        return solve(s-1, n, m, dp, vp);
    }
};