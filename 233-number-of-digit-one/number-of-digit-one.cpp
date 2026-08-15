class Solution {
public:
    int solve(string &s, int idx, int flag, int cnt, vector<vector<vector<int>>>& dp){
        if(idx == s.size()){
            return cnt;
        }
        if(dp[idx][flag][cnt] != -1){
            return dp[idx][flag][cnt];
        }
        int limit = (flag == 1) ? s[idx] - '0' : 9;
        int ans = 0;
        for(int i =0; i<= limit; i++){
            int updatedCnt = cnt + (i == 1 ? 1 : 0);
            ans += solve(s, idx+1, (flag & (i == s[idx] - '0')), updatedCnt, dp);
        } 
        return dp[idx][flag][cnt] = ans;
    }
    int countDigitOne(int n) {
        vector<vector<vector<int>>> dp(12, vector<vector<int>>(2, vector<int>(12, -1)));  //idx , flag, cnt
        string s = to_string(n);
        return solve(s, 0, 1, 0, dp);
    }
};