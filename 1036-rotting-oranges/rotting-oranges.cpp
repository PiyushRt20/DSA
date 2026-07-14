class Solution {
public:
    int di[4] = {-1, 1, 0, 0};
    int dj[4] = {0, 0, -1, 1};
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        //vector<vector<int>> vis(n, vector<int>(m, 0));
        queue<pair<pair<int, int>, int>>q;
        for(int i =0; i<n; i++){
            for(int j =0; j<m; j++){
                if(grid[i][j] == 2){
                    q.push({{i, j}, 0});
                }
            }
        }
        int ans = 0;
        while(!q.empty()){
            int mini = q.front().second;
            auto [i, j] = q.front().first;
            q.pop();
            ans = max(ans, mini);
            for(int k=0; k<4; k++){
                int newI = i + di[k];
                int newJ = j + dj[k];
                if(newI >= 0 && newJ >= 0 && newI < n && newJ < m &&
                grid[newI][newJ] == 1) {
                    q.push({{newI, newJ}, mini+1});
                    grid[newI][newJ] = 2;
                } 
            }
        }
        for(int i =0; i<n; i++){
            for(int j =0; j<m; j++){
                if(grid[i][j] == 1){
                    return -1;
                }
            }
        }
        return ans;
    }
};