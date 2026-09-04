class Solution {
public:
    int di[4] = {-1, 1, 0, 0};
    int dj[4] = {0, 0, -1, 1};
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> minTime(n, vector<int>(n, 1e9));
        priority_queue<pair<int , pair<int, int>>, vector<pair<int , pair<int, int>>>, greater<pair<int , pair<int, int>>>> pq;
        pq.push({grid[0][0],{0, 0}});
        minTime[0][0] = grid[0][0];
        while(!pq.empty()){
            int t = pq.top().first;
            auto [r, c] = pq.top().second;
            pq.pop();
            if(r == n-1 && c == n-1){
                return t;
            }
            for(int k=0; k<4; k++){
                int newR = r + di[k];
                int newC = c + dj[k];
                if(newR >= 0 && newC >= 0 && newR < n && newC < n){
                    int newT = max(grid[newR][newC], t);
                    if(newT < minTime[newR][newC]){
                        minTime[newR][newC] = newT;
                        pq.push({newT, {newR, newC}});
                    }     
                }
            }
        }
        return -1;
    }
};