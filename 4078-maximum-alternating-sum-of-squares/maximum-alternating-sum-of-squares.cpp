class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        for(int i =0; i<n; i++){
            if(nums[i] < 0){
                nums[i] *= -1;
            }
        }
        sort(nums.begin(), nums.end());
        vector<int> res;
        int i =0;
        int j = n-1;
        long long ans = 0;
        while(i<=j){
            res.push_back(nums[j]);
            res.push_back(nums[i]);
            i++;
            j--;
        }
        // for(auto it : res){
        //     cout<<it<<" "<<endl;
        // }
        for(int i =0; i<n; i++){
            if(i % 2 == 0){
                ans += res[i] * res[i];
            }
            else{
                ans -= res[i] * res[i];
            }
        }
        return ans;
    }
};