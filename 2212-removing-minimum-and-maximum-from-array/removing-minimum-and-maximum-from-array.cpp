class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        if(n == 1 || n == 2){
            return n;
        }
        int mini = 1e9;
        int maxi = -1e9;
        for(int i =0; i<n; i++){
            maxi = max(maxi, nums[i]);
            mini = min(mini, nums[i]);
        }
        int minSteps = 1e9;
        int cnt = 0;
        int i = 0;
        int j = n-1;
        bool one = false;
        bool two = false;
        while(i < j){
            if(!one && (nums[i] == mini || nums[i] == maxi)){
                one = true;
                cnt++;
            }
            if(!two && (nums[j] == mini || nums[j] == maxi)){
                two = true;
                cnt++;
            }
            if(one && two){
                break;
            }
            if(one){
                j--;
                cnt++;
            }
            else if(two){
                i++;
                cnt++;
            }
            else{
                i++;
                j--;
                cnt += 2;
            }
        }
        minSteps = min(minSteps, cnt);
        cnt = 0;
        one = false;
        two = false;
        for(int i =0; i<n; i++){
            cnt++;
            if(nums[i] == maxi || nums[i] == mini){
                if(one) two = true;
                one = true;
                
            }
            // if(nums[i] == maxi || nums[i] == mini){
            //     two = true;
            // }
            if(one && two ){
                break;
            }
        }
        minSteps = min(minSteps, cnt);
        cnt = 0;
        one = false;
        two = false;
        for(int i =n-1; i>=0; i--){
            cnt++;
            if(nums[i] == maxi || nums[i] == mini){
                if(one) two = true;
                one = true;
            }
            // if(nums[i] == maxi || nums[i] == mini){
            //     two = true;
            // }
            if(one && two ){
                break;
            }
        }
        minSteps = min(minSteps, cnt);
        return minSteps;
    }
};