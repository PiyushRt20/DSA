class Solution {
public:
    int jump(vector<int>& nums) {
        int jump = 0;
        int cnt = 0;
        int reach = 0;
        int n = nums.size();
        if(n == 1){
            return 0;
        }
        for(int i =0; i<n; i++){
            reach = max(reach, i + nums[i]);
            if(cnt == i){
                jump++;
                cnt = reach;
                if(cnt == n-1){
                    break;
                }
            }
        }
        return jump;
    }
};