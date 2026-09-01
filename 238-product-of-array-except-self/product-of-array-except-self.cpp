class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefix(n);
        vector<int> suffix(n);
        prefix[0] = 1;
        for(int i =1; i<n; i++){
            prefix[i] = prefix[i-1] * nums[i-1];
        }
        int suf = 1;
        for(int i =n-2; i>= 0; i--){
            suf *= nums[i+1];
            prefix[i] *= suf ;
        }
        return prefix;
    }
};