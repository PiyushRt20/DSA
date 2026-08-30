class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        if(n == 1 || n == 2){
            return n;
        }
        int mini = 1e9;
        int maxi = -1e9;
        for(int i =0; i<n; i++){
            maxi = max(maxi, nums[i]);
            mini = min(mini, nums[i]);
        }
        int l_Idx = -1;
        int u_Idx = -1;
        for(int i = 0; i<n; i++){
            if(nums[i] == mini){
                l_Idx = i;
            }
        }
        for(int i = 0; i<n; i++){
            if(nums[i] == maxi){
                u_Idx = i;
            }
        }
        int minSteps = 1e9;
        minSteps = min(minSteps, max(l_Idx, u_Idx) + 1);
        minSteps = min(minSteps, n - min(l_Idx, u_Idx));
        minSteps = min(minSteps, l_Idx + 1 + n - u_Idx);
        minSteps = min(minSteps, n - l_Idx  + u_Idx + 1);
        return minSteps;

    }
};