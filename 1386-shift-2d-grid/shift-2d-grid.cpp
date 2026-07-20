class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        for(int i =0; i<k; i++){
            vector<int>temp;
            temp.push_back(grid[n-1][m-1]);
            for(int i = 0; i<n-1; i++){
                temp.push_back(grid[i][m-1]);
            }
            for(int i =0; i<n; i++){
                for(int j =m-1; j> 0; j--){
                    grid[i][j] = grid[i][j-1];
                }
            }
            int idx = 0;
            for(int i = 0; i<n; i++){
                grid[i][0] = temp[idx];
                idx++;
            }
        }
        return grid;
    }
};