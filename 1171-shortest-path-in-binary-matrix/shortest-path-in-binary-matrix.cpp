class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dis(n, vector<int>(m, 1e9));
        dis[0][0] = 1;
        // priority_queue<pair<int, pair<int, int>> , vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        queue<pair<int, pair<int, int>>> pq;
        int di[8] = {0, 0, -1, 1, 1,  1, -1, -1};
        int dj[8] = {1, -1, 0, 0, 1,  -1, 1, -1};
        pq.push({1, {0,0}});
        while(!pq.empty()){
            int d = pq.front().first;
            int i = pq.front().second.first;
            int j = pq.front().second.second;
            pq.pop();
            for(int k =0; k<8; k++){
                int newI = i + di[k];
                int newJ = j + dj[k];
                if(newI < n && newJ < m && newI >=0 && newJ >=0 && grid[newI][newJ] == 0){
                    if(d + 1 < dis[newI][newJ]){
                        dis[newI][newJ] = d + 1;
                        pq.push({dis[newI][newJ] , {newI, newJ}});

                    }
                }
            }
        } 
        if(grid[0][0] == 1 ||  dis[n-1][m-1] == 1e9){
            return -1;
        }
        else{
            return dis[n-1][m-1];
        }
    }
};