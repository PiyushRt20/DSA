class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        //n2 log(m)
        // int n = nums.size();
        // set<vector<int>> ans;
        // for(int i =0; i<n; i++){
        //     unordered_map<int, int> mpp;
        //     int tar = -nums[i];
        //     for(int j =i+1; j<n; j++){
        //         int req = tar - nums[j];
        //         if(mpp.find(req) != mpp.end()){
        //             vector<int> temp;
        //             temp.push_back(nums[i]);
        //             temp.push_back(nums[j]);
        //             temp.push_back(req);
        //             sort(temp.begin(), temp.end());
        //             ans.insert(temp);
        //         }
        //         mpp[nums[j]]++;
        //     }
        // }
        // vector<vector<int>> res;
        // for(auto it : ans){
        //     res.push_back(it);
        // }
        // return res;


        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        int n = nums.size();
        for(int i =0; i<n; i++){
            if(i > 0 && nums[i] == nums[i-1]){
                continue;
            }
            int j = i+1;
            int k = n-1;
            while(j < k){
                int sum = nums[i] + nums[j] + nums[k];
                if(sum < 0){
                    j++;
                }
                else if(sum > 0){
                    k--;
                }
                else{
                    ans.push_back({nums[i], nums[j], nums[k]});
                    j++;
                    k--;
                    while(j < k && nums[j] == nums[j-1]){
                        j++;
                    }
                    while(j < k && nums[k] == nums[k+1]){
                        k--;
                    }
                }
            }
        }
        return ans;
    }
};