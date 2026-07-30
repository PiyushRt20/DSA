class Solution {
public:
    //dekha jae to mujhe es ques m find krna tha ki ese do subset jinke sum ka diff minimum ho 
    //suppose x = sum of subset 1 
    //then sum - x = sum of subset 2
    // so i need to find their diff that is -> sum - x - x = sum - 2x 
    // so i just need the min val of sum - 2x


    // bool solve(int idx, int tar, vector<vector<int>>&dp, vector<int>&stones){
    //     if(idx == 0){
    //         if(tar == 0 || tar == stones[idx]){
    //             return true;
    //         }
    //         return false;
    //     }
    //     if(dp[idx][tar] != -1){
    //         return dp[idx][tar];
    //     }
    //     bool notPick = solve(idx-1, tar, dp, stones);
    //     bool pick = false;
    //     if(tar >= stones[idx]){
    //         pick = solve(idx-1, tar - stones[idx], dp, stones);
    //     }
    //     return dp[idx][tar] = pick || notPick;
    // }
    int lastStoneWeightII(vector<int>& stones) {
        int n = stones.size();
        int sum = accumulate(stones.begin(), stones.end(), 0);
        int tar = sum/2;
        // int subset = 0;
        // vector<vector<int>> dp(n, vector<int>(tar+1, -1));
        // for(int i =tar; i>0; i--){
        //     if(solve(n-1, i, dp, stones)){
        //         subset = i;
        //         break;
        //     }
        // }
        // return sum - 2* subset;


        vector<vector<bool>> dp(n, vector<bool>(tar+1, false));
        dp[0][0] = true;
        if(stones[0] <= tar){
            dp[0][stones[0]] = true;
        }
        for(int i =1; i<n; i++){
            for(int j =0; j<=tar; j++){
                bool notPick = dp[i-1][j];
                bool pick = false;
                if(j >= stones[i]){
                    pick = dp[i-1][j - stones[i]];
                }
                dp[i][j] = pick || notPick;
            }
        }
        for(int j =tar; j>=0; j--){
            if(dp[n-1][j] == true){
                return sum - 2*j;
            }
        }
        return 0;
    }
};