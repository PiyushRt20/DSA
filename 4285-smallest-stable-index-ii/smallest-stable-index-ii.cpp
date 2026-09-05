class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        if(n == 1){
            return 0;
        }
        vector<int> miniFromRight(n);
        miniFromRight[n-1] = nums[n-1];
        for(int i =n-2; i>=0; i--){
            miniFromRight[i] = min(miniFromRight[i+1], nums[i]);
        }
        int maxi = 0;
        for(int i =0; i<n; i++){
            maxi = max(maxi, nums[i]);
            if(maxi - miniFromRight[i] <= k){
                return i;
            }
        }
        return -1;
    }
};