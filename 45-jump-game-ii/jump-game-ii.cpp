class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int jump = 0;
        int end = 0;
        int reach = 0;
        for(int i =0; i<n; i++){
            if(i == n-1) break;
            reach = max(reach , i + nums[i]);
            if(i == end){
                jump++;
                end = reach;
            }
        }
        return jump;
    }
};