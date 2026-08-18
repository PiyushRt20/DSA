class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int ele = nums[0];
        int cnt = 1;
        int n = nums.size();
        for(int i =1; i<n; i++){
            if(nums[i] == ele){
                cnt++;
            }
            else{
                cnt--;
            }
            if(cnt == 0 ){
                ele = nums[i];
                cnt = 1;
            }
        }
        return ele;
    }
};