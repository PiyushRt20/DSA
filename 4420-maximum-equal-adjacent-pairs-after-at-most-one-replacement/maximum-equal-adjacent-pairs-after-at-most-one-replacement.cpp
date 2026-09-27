class Solution {
public:
    int maxEqualAdjacentPairs(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        int alreadyEqual = 0;
        map<pair<int, int>, int> mpp;
        for(int i =1; i<n; i++){
            if(nums[i] == nums[i-1]){
                alreadyEqual++;
            }
            else{
                int a = nums[i-1];
                int b = nums[i];
                if(a > b){
                    mpp[{b,a}]++;
                }
                else{
                    mpp[{a,b}]++;
                }
            }
        }
        ans = alreadyEqual;
        for(auto it : mpp){
            ans = max(ans, alreadyEqual + it.second);
        }
        return ans;
    }
};