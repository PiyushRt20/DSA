class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        map<int, int> mpp;
        for(int i =0; i<nums.size(); i++){
            mpp[nums[i]] = 1;
        }
        int maxi = 1;
        int cnt = 0;
        int val = -1e9;
        if(nums.size() == 1){
            return 1;
        }
        if(nums.size() == 0){
            return 0;
        } 
        for(auto it : mpp){
            if(cnt == 0){
                cnt++;
            }
            if(it.first == val +1){
                cnt++;
            }
            else{
                cnt = 0;
            }
            val = it.first;
            maxi = max(cnt, maxi);
        }
        return maxi;
    }
};