class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int curSum = 0;
        unordered_map<int, int>mpp;
        mpp[0] =1;
        int cnt = 0;
        for(int i =0; i<nums.size(); i++){
            curSum += nums[i];
            int req = curSum - k;
            if(mpp.find(req) != mpp.end()){
                cnt += mpp[req];
            }
            mpp[curSum]++;
        }
        return cnt;
    }
};