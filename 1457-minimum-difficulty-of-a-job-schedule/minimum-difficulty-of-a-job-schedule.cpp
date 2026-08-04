class Solution {
public:
    int n;
    int solve(int idx, int d, vector<int>& jobDifficulty, vector<vector<int>> &dp){
        if(d == 1){
            int maxi = -1;
            for(int i = idx; i<=n-d; i++){
                maxi = max(maxi, jobDifficulty[i]);
            }
            return maxi;
        }
        // if(idx >= n && d == 0){
        //     return 0;
        // }
        if(dp[idx][d] != -1){
            return dp[idx][d];
        }
        int ans = INT_MAX;
        int maxi = -1;
        for(int i = idx; i<=n-d; i++){
            maxi = max(maxi , jobDifficulty[i]);
            int val = maxi + solve(i+1, d-1, jobDifficulty, dp);
            ans = min(ans, val);
        }
        return dp[idx][d] = ans;
    }
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        n = jobDifficulty.size();
        if(d > n){
            return -1;
        }
        if(d == n){
            int sum = accumulate(jobDifficulty.begin(), jobDifficulty.end(), 0);
            return sum;
        }
        vector<vector<int>> dp(n, vector<int>(d+1, -1));
        return solve(0, d, jobDifficulty, dp);
    }
};