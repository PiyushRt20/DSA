class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int firstS = nums[0];
        int secS = INT_MAX;
        for(auto it : nums){
            if(it <= firstS){
                firstS = it;
            }
            else if(it <= secS){
                secS = it;
            }
            else{
                return true;
            }
        }
        return false;
    }
};