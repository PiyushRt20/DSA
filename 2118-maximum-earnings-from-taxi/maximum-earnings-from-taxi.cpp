class Solution {
public:
    int findNextIdx(int low, int val, vector<vector<int>>& rides){
        int high = rides.size()-1;
        int ans = -1;
        while(low <= high){
            int mid = low + (high - low )/2;
            if(rides[mid][0] >= val){
                ans = mid;
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return ans;
    }
    long long solve(int idx, vector<vector<int>>& rides, vector<long long>&dp){
        if(idx >= rides.size()){
            return 0;
        }
        if(idx < 0) return 0;
        if(dp[idx] != -1){
            return dp[idx];
        }
        int j = findNextIdx(idx, rides[idx][1], rides);

        long long notPick = 0 + solve(idx+1,rides, dp);
        long long pick = rides[idx][1] - rides[idx][0] + rides[idx][2] + solve(j, rides, dp);
        return dp[idx] =  max(pick , notPick);
    }
    long long maxTaxiEarnings(int n, vector<vector<int>>& rides) {
        sort(rides.begin(), rides.end());
        vector<long long>dp(rides.size(), -1);
        return solve(0,rides, dp);
    }
};