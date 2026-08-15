class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n = nums.size();
        int val = nums[0];
        for(int i =1; i<n; i++){
            val ^= nums[i];
        }
        if(val != 0){
            return n;
        }
        for(auto it : nums){
            if(it != 0){
                return n-1;
            }
        }
        return 0;
    }
};