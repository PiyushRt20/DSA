class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n = nums.size();
        int xo = 0;
        for(int num : nums){
            xo ^= num;
        }
        if(xo != 0){
            return n;
        }
        for(int val : nums){
            if(val != 0){
                return n-1;
            }
        }
        return 0;
    }
};