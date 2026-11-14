class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int n = nums.size();
        int mini = 1e9;
        for(int i =0; i<n; i++){
            int sum = 0;
            for(int j=i; j<n; j++){
                sum += nums[j];
                if(sum > 0){
                    int len = j-i+1;
                    if(len >= l && len <= r){
                        mini = min(sum, mini);
                    }
                }
            }
        }
        return mini == 1e9 ? -1 : mini;
    }
};