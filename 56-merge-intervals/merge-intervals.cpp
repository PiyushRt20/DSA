class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ans;
        int n = intervals.size();
        ans.push_back(intervals[0]);
        int last = intervals[0][1];
        for(int i =1; i<n; i++){
            if(last >= intervals[i][0]){
                last = max(last, intervals[i][1]);
                ans.back()[1] = last;
            }
            else{
                ans.push_back(intervals[i]);
                last = intervals[i][1];
            }
        }
        return ans;
    }
};