class Solution {
public:
    int n;
    int get_Idx(vector<int>& startTime, int end){
        int idx = lower_bound(startTime.begin(), startTime.end(), end) - startTime.begin();
        return idx;
    }
    int solve(int idx, vector<int>& startTime, vector<int>& endTime, vector<int>& profit, vector<int> &dp){
        if(idx >= n){
            return 0;
        }
        if(dp[idx] != -1){
            return dp[idx];
        }
        int nextIdx = get_Idx(startTime, endTime[idx]);
        int take = profit[idx] + solve(nextIdx, startTime, endTime, profit, dp);
        int notTake = solve(idx+1, startTime, endTime, profit, dp);
        return dp[idx] = max(take, notTake);
    }
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        n = profit.size();
        vector<pair<pair<int, int>, int>> vp;
        for(int i =0; i<n; i++){
            vp.push_back({{startTime[i], endTime[i]}, profit[i]});
        }
        sort(vp.begin(), vp.end(), [](auto &a, auto &b){
            if(a.first.first != b.first.first){
                return a.first.first < b.first.first;
            }
            else{
                return a.first.second < b.first.second;
            }
        });
        for(int i =0; i<n; i++){
            startTime[i] = vp[i].first.first;
            endTime[i] = vp[i].first.second;
            profit[i] = vp[i].second;
        }
        vector<int> dp(n, -1);
        return solve(0, startTime, endTime, profit, dp);
    }
};