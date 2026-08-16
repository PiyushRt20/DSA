class Solution {
public:
    int nearestDrone(vector<vector<int>>& drones, vector<int>& target) {
        int mini = 1e9;
        int minVal = 1e9;
        int n = drones.size();
        for(int i =0; i<n; i++){
            int diff = abs(drones[i][0] - target[0]);
            diff += abs(drones[i][1] - target[1]);
            // cout<<diff<<" ";
            if(diff <= drones[i][2]){
                if(diff < minVal){
                    minVal = diff;
                    mini = i;
                }
            }
        }
        if(mini == 1e9 ){
            return -1;
        }
        return mini;
    }
};