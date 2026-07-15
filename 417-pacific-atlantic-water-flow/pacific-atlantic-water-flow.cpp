class Solution {
public:
    int n, m;
    int di[4] = {1, -1, 0, 0};
    int dj[4] = {0, 0, -1, 1};
    void dfs(int i, int j, vector<vector<int>>& heights, vector<vector<int>>& vis){
        vis[i][j] = 1;
        for(int k =0; k<4; k++){
            int newI = i + di[k];
            int newJ = j + dj[k];
            if(newI < n && newJ < m && newI >= 0 && newJ >= 0 &&
             vis[newI][newJ] == 0 &&
             heights[newI][newJ] >= heights[i][j]){
                dfs(newI, newJ, heights, vis);
            }
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        n = heights.size();
        m = heights[0].size();
        vector<vector<int>> ans;
        vector<vector<int>> pacific(n, vector<int>(m, 0));
        vector<vector<int>> atlantic(n, vector<int>(m, 0));
        for(int j =0; j<m; j++){
            if(!pacific[0][j]){
                dfs(0, j, heights, pacific);
            }
        }
        for(int i=1; i<n; i++){
            if(!pacific[i][0]){
                dfs(i, 0, heights, pacific);
            }
            
        }
        for(int j =0; j<m; j++){
            if(!atlantic[n-1][j]){
                dfs(n-1, j, heights, atlantic);
            }
        }
        for(int i =0; i<n-1; i++){
            if(!atlantic[i][m-1]){
                dfs(i, m-1, heights, atlantic);
            }
        }
        for(int i =0; i<n; i++){
            for(int j =0; j<m; j++){
                if(pacific[i][j] == 1 && atlantic[i][j] == 1){
                    ans.push_back({i, j});
                }
            }        
        }    
        return ans;
    }
};