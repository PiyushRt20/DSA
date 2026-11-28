class Solution {
public:
    int solve(int idx, vector<vector<int>>& items, int budget, vector<int>& free, int n, int cheapest, vector<vector<int>>& dp){
        if(idx == n){
            return budget/cheapest;
        }
        if(dp[idx][budget] != -1){
            return dp[idx][budget];
        }
        int take = 0;
        int notTake = 0;
        if(budget >= items[idx][1]){
            take += 1 + free[idx] + solve(idx+1, items, budget - items[idx][1], free, n, cheapest, dp);
        }
        notTake += solve(idx+1, items, budget, free, n, cheapest, dp);
        return  dp[idx][budget] = max(take,notTake);
    }
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();
        vector<int> free(n, 0);
        int cheapest = 1e9;
        for(int i =0; i<n; i++){
            cheapest = min(cheapest, items[i][1]);
            int copy = 0;
            for(int j =0; j<n; j++){
                if(i == j ) continue;
                if(items[j][0] % items[i][0] == 0){
                    copy++;
                }
            }
            free[i] = copy;
        }
        vector<vector<int>> dp(n, vector<int>(budget+1, -1));
        return solve(0, items, budget, free, n, cheapest, dp);
    }
};