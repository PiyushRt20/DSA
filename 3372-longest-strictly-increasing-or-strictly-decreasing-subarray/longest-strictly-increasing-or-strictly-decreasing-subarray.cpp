class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int inc = 1;
        int dec = 1;
        int maxi =1;
        int n = nums.size();
        if(n == 1){
            return 1;
        }
        for(int i =0; i<nums.size()-1; i++){
            if(nums[i] == nums[i+1]){
                inc = 1;
                dec = 1;
                continue;
            }
            else if(nums[i] < nums[i+1]){
                inc++;
                dec = 1;
            }
            else if(nums[i] > nums[i+1]){
                inc = 1;
                dec++;
            }
            maxi = max({maxi, dec, inc});
        }
        // if(nums[n-2] < nums[n-1]){
        //     inc++;
        //     dec = 0;
        // }
        // else if(nums[n-2] > nums[n-1]){
        //     inc = 0;
        //     dec++;
        // }
        // // cout<<inc<<dec;
        // maxi = max({maxi, dec, inc});
        return maxi;
    }
};