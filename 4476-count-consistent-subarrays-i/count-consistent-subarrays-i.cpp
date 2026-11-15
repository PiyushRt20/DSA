class Solution {
public:
    int countConsistent(vector<int>& nums) {
        int n = nums.size();
        int ans = n;
            for(int i =0; i<n; i++){
                int mini = nums[i];
                int val = nums[i];
                for(int j =i+1; j<n; j++){
                    mini = min(mini, nums[j]);
                    val &= nums[j];
                    if(val == mini){
                        ans++;
                    }
                }
            }
          
        return ans;
    }
};