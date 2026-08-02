class Solution {
public:
    vector<vector<int>> aggregateTimeSeries(vector<vector<int>>& series1, vector<vector<int>>& series2) {
        vector<vector<int>> ans;
        int n = series1.size();
        int m = series2.size();
        int i = 0, j = 0;
        while(i <n && j < m){
            if(series1[i][0] == series2[j][0]){
                series1[i][1] = series1[i][1] + series2[j][1];
                ans.push_back(series1[i]);
                i++;
                j++;
            }
            else if(series1[i][0] < series2[j][0]){
                series1[i][1] = series1[i][1] + series2[j][1];
                ans.push_back(series1[i]);
                i++;
            }
            else{
                series2[j][1] = series1[i][1] + series2[j][1];
                ans.push_back(series2[j]);
                j++;
            }
        }
        while(i < n){
            ans.push_back(series1[i]);
            i++;
        }
        while(j < m){
            ans.push_back(series2[j]);
            j++;
        }
        return ans;
    }
};