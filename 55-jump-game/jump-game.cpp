class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int reach = 0;
        if(n == 1) return true;
        for(int i =0; i<n; i++){
            reach = max(reach, i + nums[i]);
            if(reach >= n-1){
                return true;
            }
            if(i >= reach){
                return false;
            }
        }
        return false;
    }
};