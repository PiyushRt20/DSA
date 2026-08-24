class Solution {
public:
    vector<vector<int>> findDisappearedNumbers(vector<int>& nums, int lower, int upper) {
        unordered_set<int> s(nums.begin(), nums.end());
        vector<vector<int>> ans;
        for(int i =lower; i<= upper; i++){
            int a ,b;
            if(!s.count(i)){
                a = i;
                while(i <= upper && !s.count(i)){
                    i++;
                }
                b = i-1;
                ans.push_back({a,b});
            }
            
        }
        return ans;
    }
};