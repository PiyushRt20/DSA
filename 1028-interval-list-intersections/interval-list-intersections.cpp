class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        vector<vector<int>> ans;
        int n = firstList.size();
        int m = secondList.size();
        for(int i =0; i<n; i++){
            for(int j =0; j<m; j++){
                vector<int> temp;
                if(secondList[j][0] <= firstList[i][1] &&
                firstList[i][0] <= secondList[j][1]){
                    temp.push_back(max(secondList[j][0], firstList[i][0]));
                    temp.push_back(min(secondList[j][1], firstList[i][1]));
                }
                if(temp.size() != 0){
                    ans.push_back(temp);
                }
            }
        }
        return ans;
    }
};