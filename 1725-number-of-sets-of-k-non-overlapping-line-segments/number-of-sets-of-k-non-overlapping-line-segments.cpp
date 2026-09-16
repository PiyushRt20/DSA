// class Solution {
// public:
//     int M = 1e9+7;
//     // int solve(int idx, int n, int k, vector<vector<int>>& dp){
//     //     if(k == 0) return 1;
//     //     if(idx >= n) return 0;
//     //     if(dp[idx][k] != -1){
//     //         return dp[idx][k];
//     //     }
//     //     int notTake = solve(idx+1, n, k, dp);
//     //     int take = 0;
//     //     for(int i =idx+1; i<n; i++){
//     //         take = (take + solve(i, n, k-1, dp)) % M;
//     //     }
//     //     return dp[idx][k] = (take + notTake) % M;
//     // }
//     int numberOfSets(int n, int k) {
//         // vector<vector<int>> dp(n, vector<int>(k+1, -1));
//         // return solve(0, n, k, dp);

//         vector<vector<int>> dp(n+1, vector<int>(k+1, 0));        
//         for(int i =0; i<n; i++){
//             dp[i][0] = 1;
//         }
//         for(int i =n-1; i>=0; i--){
//             for(int j = 1; j<=k; j++){
//                 long long notTake = dp[i+1][j];
//                 long long take = 0;
//                 for(int l =i+1; l<n; l++){
//                     take = (take + dp[l][j-1]) % M;
//                 }
//                 dp[i][j] = (take + notTake) % M;
//             }
//         }
//         return dp[0][k];
//     }
// };
class Solution {
public:
    int M = 1e9 + 7;
    int dp[1001][1001];

    int numberOfSets(int n, int K) {

        for (int i = 0; i <= n; i++) {
            dp[0][i] = (i < n) ? 1 : 0;
        }

        for (int k = 1; k <= K; k++) {

            vector<int> prevRowSum(n + 1, 0);

            //prevRowSum[x] = dp[k-1][x] + dp[k-1][x+1] + ... + dp[k-1][n-1]
            for (int x = n - 1; x >= 0; x--) {
                prevRowSum[x] = (prevRowSum[x + 1] + dp[k - 1][x]) % M;
            }

            for (int i = n - 1; i >= 0; i--) {
                
                int skip = dp[k][i + 1];

                int take = prevRowSum[i+1];
                //dp[k-1][i+1] + dp[k-1][i+2] ...... + dp[k-1][n-1]

                dp[k][i] = (take + skip) % M;
            }
        }

        return dp[K][0];
    }
};