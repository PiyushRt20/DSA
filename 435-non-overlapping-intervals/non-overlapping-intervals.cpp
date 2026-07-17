class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end(), [](auto &a , auto &b){
            if(a[1] != b[1]){
                return a[1] < b[1];
            }
            else{
                return a[0] < b[0];
            }
        });
        vector<vector<int>> vec = {intervals[0]};

        int ans =0;
        int j=0;
        for(int i=1; i<n; i++){
            if(intervals[i][0] < vec[j][1]){
                ans++;
            }
            else{
                j++;
                vec.push_back(intervals[i]);
            }
        }
        return ans;

    }
};