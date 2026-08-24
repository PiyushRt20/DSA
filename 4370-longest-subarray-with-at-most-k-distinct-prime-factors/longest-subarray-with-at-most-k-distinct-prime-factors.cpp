class Solution {
public:
    vector<int> primeFact(int n){
        vector<int> temp;
        for(int i =2; i*i <= n; i++){
            bool flag = false;
            while(n % i == 0){
                flag = true;
                n /= i;
            }
            if(flag){
                temp.push_back(i);
            }
        }
        if(n > 1){
            temp.push_back(n);
        }
        return temp;
    }
    int longestSubarray(vector<int>& nums, int k) {
        unordered_map<int , vector<int>>mpp;
        for(int i =0; i<nums.size(); i++){
            mpp[nums[i]] = primeFact(nums[i]);
        }
        // for(auto it : nums){
        //     cout<<it<<"->"<<" ";
        //     for(auto val : mpp[it]){
        //         cout<<val<<",";
        //     }
        //     cout<<endl;
        // }
        int maxi = 0;
        unordered_map<int , int> mp;
        int l = 0;
        for(int i =0; i<nums.size(); i++){
            for(auto it : mpp[nums[i]]){
                mp[it]++;
            }
            while(mp.size() > k){
                for(auto it : mpp[nums[l]]){
                    mp[it]--;
                    if(mp[it] == 0){
                        mp.erase(it);
                    }
                }
                l++;
            }
            // for(auto it : mp){
            //     cout<<it.first<<" "<<it.second<<endl;
            // }
            maxi = max(maxi, i - l +1);
        }
        return maxi;
    }
};