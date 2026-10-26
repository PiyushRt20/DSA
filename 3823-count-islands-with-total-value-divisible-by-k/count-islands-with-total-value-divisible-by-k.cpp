class Solution {
public:
    int di[4] = {1, -1, 0, 0};
    int dj[4] = {0, 0, -1, 1};
    int n , m;
    void solve(int i, int j, long long& sum, vector<vector<int>>& grid, vector<vector<int>>& vis){
        vis[i][j] = 1;
        sum += grid[i][j];
        for(int k =0; k<4; k++){
            int newI = i + di[k];
            int newJ = j + dj[k];
            if(newI < n && newI >= 0 && newJ < m && newJ >= 0 && grid[newI][newJ] > 0 && !vis[newI][newJ]){
                solve(newI, newJ, sum, grid, vis);
            }
        }
    }
    int countIslands(vector<vector<int>>& grid, int k) {
        n = grid.size();
        m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        int ans = 0;
        for(int i =0; i<n; i++){
            for(int j =0; j<m; j++){
                if(!vis[i][j] && grid[i][j] > 0 ){
                    long long sum = 0;
                    solve(i, j, sum, grid, vis);
                    if(sum % k == 0){
                        ans++;
                    }
                }
            }
        }   
        return ans;     
    }
};