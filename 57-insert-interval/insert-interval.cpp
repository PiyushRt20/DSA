class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>>& updatedIntervals = intervals;
        updatedIntervals.push_back(newInterval);
        sort(updatedIntervals.begin(), updatedIntervals.end());
        vector<vector<int>> ans;
        ans.push_back(updatedIntervals[0]);
        for(int i =1; i<updatedIntervals.size(); i++){
            if(ans.back()[1] >= updatedIntervals[i][0]){
                ans.back()[1] = max(ans.back()[1], updatedIntervals[i][1]);
            }
            else{
                ans.push_back(updatedIntervals[i]);
            }
        }
        return ans;
    }
};