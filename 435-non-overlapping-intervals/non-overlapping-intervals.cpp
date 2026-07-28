class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int cnt = 0;
        sort(intervals.begin(), intervals.end(), [](auto &a, auto &b){
            if(a[0] != b[0]){
                return a[0] < b[0];
            }
            else{
                return a[1] > b[1];
            }
        });
        int lastVal = intervals[0][1];
        for(int i =1; i<intervals.size(); i++){
            if(lastVal > intervals[i][0]){
                lastVal = min(lastVal , intervals[i][1]);
                cnt++;
            }
            else{
                lastVal = intervals[i][1];
            }
        }
        return cnt;
    }
};