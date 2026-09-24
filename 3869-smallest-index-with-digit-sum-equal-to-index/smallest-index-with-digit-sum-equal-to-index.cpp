class Solution {
public:
    int smallestIndex(vector<int>& nums) {
        int n = nums.size();
        for(int i =0; i<n; i++){
            int sum = 0;
            int val = nums[i];
            while(val > 0){
                int digit = val%10;
                sum += digit;
                val /= 10;
            }
            if(sum == i){
                return i;
            }
        }
        return -1;
    }
};