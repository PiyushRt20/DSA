class Solution {
public:
    int di[4] = {1, -1, 0, 0};
    int dj[4] = {0, 0, -1, 1};
    int n , m;
    void solve(int i, int j, bool& check, vector<vector<int>>& grid, vector<vector<int>>& vis){
        vis[i][j] = 1;
        if(i == 0 || i == n-1 || j == 0 || j == m-1){
            check = true;
        }
        for(int k =0; k<4; k++){
            int newI = i + di[k];
            int newJ = j + dj[k];
            if(newI < n && newI >= 0 && newJ < m && newJ >= 0 && grid[newI][newJ] == 0 && !vis[newI][newJ]){
                solve(newI, newJ, check, grid, vis);
            }
        }
    }
    int closedIsland(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        int islands = 0;
        for(int i =0; i<n; i++){
            for(int j =0; j<m; j++){
                if(!vis[i][j] && grid[i][j] == 0){
                    bool check = false;
                    solve(i, j, check, grid, vis);
                    if(!check){
                        islands += 1;
                    }
                }
            }
        }
        return islands;
    }
};