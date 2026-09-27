class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        map<int, int> mpp;
        for(auto it : nums){
            mpp[it]++;
        }
        int n = nums.size();
        vector<int> ans;
        while(ans.size() < n){
            for(auto it : mpp){
                if(mpp[it.first] == 0){
                    continue;
                }
                ans.push_back(it.first);
                mpp[it.first]--;
            }
        }
        return ans;
    }
};