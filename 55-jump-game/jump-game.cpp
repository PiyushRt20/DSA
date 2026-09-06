class Solution {
public:
    bool canJump(vector<int>& nums) {
        int reach = 0;
        int n = nums.size();
        if(n == 1){
            return true;
        }
        for(int i =0; i<n; i++){
            reach = max(reach, i + nums[i]);
            if(reach == n-1){
                return true;
            }
            if(reach == i){
                return false;
            }
        }
        return true;
    }
};