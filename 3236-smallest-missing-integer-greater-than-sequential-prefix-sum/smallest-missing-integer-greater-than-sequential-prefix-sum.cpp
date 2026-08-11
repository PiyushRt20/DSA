class Solution {
public:
    int missingInteger(vector<int>& nums) {
        set<int>s(nums.begin(), nums.end());
        int preSum = nums[0];
        for(int i =1; i<nums.size(); i++){
            if(nums[i] == nums[i-1] + 1){
                preSum += nums[i];
            } 
            else{
                break;
            }
        }
        for(int i = preSum; i <= preSum+50; i++){
            if(!s.count(i)){
                return i;
            }
        }
        return -1;
    }
};