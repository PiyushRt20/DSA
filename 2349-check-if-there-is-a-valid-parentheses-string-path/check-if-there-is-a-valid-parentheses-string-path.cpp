class Solution {
public:
    int n, m;
    bool solve(int i, int j, int valid, vector<vector<char>>& grid, vector<vector<vector<int>>> &dp){
        if(i >= n || j >= m){
            return false;
        }
        if(valid < 0){
            return false;
        }
        // if(valid > (n - i) + (m - j)){
        //     return false;
        // }    
        if(i == n-1 && j == m-1 && valid == 0){
            return true;
        }
        if(dp[i][j][valid] != -1){
            return dp[i][j][valid]; 
        }
        int rightValid = valid;
        int bottomValid = valid;
        if(j+1 < m){
            if(grid[i][j+1] == '('){
                rightValid += 1;
            }
            else{
                rightValid -= 1;
            }
        }
        if(i+1 < n){
            if(grid[i+1][j] == '('){
                bottomValid += 1;
            }
            else{
                bottomValid -= 1;
            }
        }
        bool right = solve(i, j+1, rightValid, grid, dp);
        if(right){
            return true;
        }
        bool bottom = solve(i+1, j, bottomValid, grid, dp);
        if(bottom){
            return true;
        }
        return dp[i][j][valid] = right || bottom;
    }
    bool hasValidPath(vector<vector<char>>& grid) {
        n = grid.size();
        m = grid[0].size();
        if(grid[0][0] == ')'){
            return false;
        }
        if((n + m - 1) % 2 != 0){
            return false;
        }
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(n+m, -1)));
        return solve(0, 0, 1, grid, dp);
    }
};