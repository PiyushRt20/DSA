class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n = arr.size();
        if(n == 0) return {};
        vector<int> nums = arr;
        sort(nums.begin(), nums.end());
        int rank = 1;
        unordered_map<int, int>mpp;
        mpp[nums[0]] = 1;
        for(int i=1; i<n; i++){
            if(nums[i] != nums[i-1]){
                rank++;
            }
            mpp[nums[i]] = rank;
        }
        for(int i =0; i<n; i++){
            arr[i] = mpp[arr[i]];
        }
        return arr;
    }
};