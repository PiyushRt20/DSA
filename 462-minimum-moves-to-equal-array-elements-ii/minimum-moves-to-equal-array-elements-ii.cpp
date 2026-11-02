class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int mid = n/2;
        int midEle = nums[n/2];
        int ans = 0;
        for(int i =0; i<n; i++){
            if(i == mid) continue;
            if(i < mid){
                ans += midEle - nums[i];
            }
            else{
                ans += nums[i] - midEle;
            }
        }
        return ans;
    }
};