class Solution {
public:
    bool solve(int idx, string& s, int n, unordered_set<string> &st, vector<int>&dp){
        if(idx == n){
            return true;
        }
        if(dp[idx] != -1){
            return dp[idx];
        }
        for(int i = idx; i<n; i++){
            string t = s.substr(idx, i-idx+1);
            if(st.count(t)){
                if(solve(i+1, s, n, st, dp)){
                    return true;
                }
            }
        }
        return dp[idx] = false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> st(wordDict.begin(), wordDict.end());
        int n = s.size();
        vector<int> dp(n, -1);
        return solve(0, s, n, st, dp);
    }
};