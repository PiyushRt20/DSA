class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int cntF = 0;
        int cntL = 0;
        int n = nums.size();
        if(n == 1){
            return nums[0];
        }
        if( k == n){
            return *max_element(nums.begin(), nums.end());
        }
        unordered_map<int, int> mpp;
        int firstEle = nums[0];
        int lastEle = nums[n-1];
        for(int i =0; i<n; i++){
            mpp[nums[i]]++;
            if(nums[i] == firstEle){
                cntF++;
            }
            if(nums[i] == lastEle){
                cntL++;
            }
        }
        int maxi = -1;
        for(auto it : mpp){
            if(it.second == 1){
                maxi = max(maxi, it.first);
            }
        }
        if(k == 1){
            return maxi;
        }
        if(cntL == 1 && cntF == 1){
            return max(firstEle, lastEle);
        }
        else if(cntL == 1 && cntF > 1){
            return lastEle;
        }
        else if(cntL > 1 && cntF == 1){
            return firstEle;
        }
        return -1;
    }
};