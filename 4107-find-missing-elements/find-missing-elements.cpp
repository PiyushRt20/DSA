class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        vector<int> arr(100+1, 0);
        int mini = *min_element(nums.begin(), nums.end());
        int maxi = *max_element(nums.begin(), nums.end());
        for(auto it : nums){
            arr[it] = 1;
        }
        vector<int> ans;
        for(int i = mini; i<=maxi; i++){
            if(arr[i] == 0){
                ans.push_back(i);
            }
        }
        return ans;
    }
};