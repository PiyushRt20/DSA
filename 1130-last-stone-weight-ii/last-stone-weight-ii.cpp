class Solution {
public:
    bool solve(int idx, int tar, vector<vector<int>>&dp, vector<int>&stones){
        if(idx == 0){
            if(tar == 0 || tar == stones[idx]){
                return true;
            }
            return false;
        }
        if(dp[idx][tar] != -1){
            return dp[idx][tar];
        }
        bool notPick = solve(idx-1, tar, dp, stones);
        bool pick = false;
        if(tar >= stones[idx]){
            pick = solve(idx-1, tar - stones[idx], dp, stones);
        }
        return dp[idx][tar] = pick || notPick;
    }
    int lastStoneWeightII(vector<int>& stones) {
        int n = stones.size();
        int sum = accumulate(stones.begin(), stones.end(), 0);
        int tar = sum/2;
        int subset = 0;
        vector<vector<int>> dp(n, vector<int>(tar+1, -1));
        for(int i =1; i<=tar; i++){
            if(solve(n-1, i, dp, stones)){
                subset = i;
            }
        }
        return sum - 2* subset;
    }
};