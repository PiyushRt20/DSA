class Solution {
public:
    int minMirrorPairDistance(vector<int>& nums) {
        unordered_map<int, int>mpp;
        int n = nums.size();
        int mini = 1e9;
        for(int i =n-1; i>=0; i--){
            int val = nums[i];
            int newVal = 0;
            while(val > 0 ){
                int digit = val % 10;
                newVal = newVal * 10 + digit;
                val /= 10;
            }
            while (newVal % 10 == 0 && newVal != 0) {
                newVal /= 10;
            }
            if(mpp.find(newVal) != mpp.end()){
                mini = min(mini, mpp[newVal] - i);
            }
            mpp[nums[i]] = i;
        }
        return mini == 1e9 ? -1 : mini;
    }
};