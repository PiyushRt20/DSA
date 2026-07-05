class Solution {
public:
    int n;
    bool isPalin(int i, int j, string& t){
        while(i <= j){
            if(t[i] != t[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    // int solve(int i, string& s, vector<int>& dp){
    //     if(i == n){
    //         return 0;
    //     }
    //     if(dp[i] != -1){
    //         return dp[i];
    //     }
    //     int mini = 1e9;
    //     for(int j = i; j<n; j++){
    //         if(isPalin(i, j,s)){
    //             int cost = 1 + solve(j+1, s, dp);
    //             mini = min(cost, mini);
    //         }
    //     }
    //     return dp[i] = mini;
    // }
    int minCut(string s) {
        n = s.size();
        // vector<int> dp(n, -1);
        // return solve(0, s, dp) - 1;       //sub -1 for EX - s = ABC so ek partition 
                 //                           pr hoga then ek B pr then final C p 
                 //                         then    i == 0  n hoga n return 0 so ek extra hota h

        vector<int>dp(n+1, 0);
        for(int i = n-1; i>=0; i--){
            int mini = 1e9;
            for(int j = i; j<n; j++){
                if(isPalin(i, j,s)){
                    int cost = 1 + dp[j+1];
                    mini = min(cost, mini);
                }
            }
            dp[i] = mini;
        }  
        return dp[0]-1;       
    }
};