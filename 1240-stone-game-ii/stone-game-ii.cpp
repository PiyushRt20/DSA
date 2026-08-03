class Solution {
public:
    int n;
    int alice(int turn, int i, int m, vector<int>& piles, vector<vector<vector<int>>>& dp){
        if(i >= n) return 0;
        if(dp[turn][i][m] != -1){
            return dp[turn][i][m];
        }
        int stones = 0;
        int result = turn == 1 ? 0 : INT_MAX;
        for(int x = 1; x<= min(2*m, n-i); x++){
            stones += piles[i + x-1];
            if(turn == 1){                      //alice turn
                result = max(result, stones + alice(0, i+x, max(m, x), piles, dp));
            }
            else{
                result = min(result, alice(1, i+x, max(m, x), piles, dp));
            }
        }
        return dp[turn][i][m] = result;
    }
    int stoneGameII(vector<int>& piles) {
        n = piles.size();
        vector<vector<vector<int>>> dp(2, vector<vector<int>>(n+1, vector<int>(n+1, -1)));
        return alice(1, 0, 1, piles, dp);
    }
};