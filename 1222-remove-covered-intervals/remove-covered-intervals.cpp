class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end(),[](auto& a, auto& b){
            if(a[0] != b[0]){
                return a[0] < b[0];
            }
            else{
                return a[1] > b[1];
            }
        });
        for(int i =0; i<n; i++){
            for(int j=0; j<2; j++){
                cout<<intervals[i][j]<<" ";
            }
            cout<<endl;
        }
        int b = intervals[0][1];
        int cnt = 1;
        for(int i =1; i<n; i++){
            if(b >= intervals[i][1]){
                continue;
            }
            cnt++;
            b = intervals[i][1];
        }
        cout<<cnt;
        return cnt;
    }
};