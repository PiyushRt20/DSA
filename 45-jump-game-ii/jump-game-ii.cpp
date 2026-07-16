class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int jump = 1;
        int reach = 0;
        int end = 0;
        if(n == 1) return 0;
        for(int i=0; i<n; i++){
            reach = max(reach, i + nums[i]);
            if(reach >= n-1) break;
            if(i == end){
                jump++;
                end = reach;
            }
        }
        return jump;
    }
};