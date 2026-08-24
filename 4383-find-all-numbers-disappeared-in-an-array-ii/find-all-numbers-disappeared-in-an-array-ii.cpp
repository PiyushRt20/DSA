class Solution {
public:
    vector<vector<int>> findDisappearedNumbers(vector<int>& nums, int lower, int upper) {
        unordered_set<int> s(nums.begin(), nums.end());
        vector<vector<int>> ans;
        int start = lower;
        for(int i =lower; i<= upper; i++){
            if(s.count(i)){
                if(start<=i-1){
                    ans.push_back({start, i-1});
                }
                start = i+1;
            }
            
        }
        if(start <= upper){
            ans.push_back({start, upper});
        }
        return ans;
    }
};