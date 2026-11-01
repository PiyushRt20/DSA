class Solution {
public:
    int minMoves(vector<int>& nums) {
        //tle
        // vector<long long> res(nums.begin(), nums.end());
        // int maxi = -1e9;
        // int mini = 1e9;
        // for(auto it : nums){
        //     maxi = max(maxi, it);
        //     mini = min(mini, it);
        // }
        // long long MAXI = LLONG_MIN;
        // long long MINI = LLONG_MAX;
        // int ans = 0;
        // while(mini != maxi){
        //     int add = maxi - mini;
        //     ans += add;
        //     int cnt = 0;
        //     for(int i =0; i<nums.size(); i++){
        //         if(res[i] == maxi ) cnt++;
        //         if(res[i] == maxi && cnt == 1) continue;
        //         res[i] = res[i] + add;
        //         MAXI = max(MAXI, res[i]);
        //         MINI = min(MINI, res[i]);
        //     }
        //     mini = MINI;
        //     maxi = MAXI;
        //     MAXI = LLONG_MIN;
        //     MINI = LLONG_MAX;
        // }
        // return ans;
        long long sum = 0;
        int mini = INT_MAX;
        for(auto it : nums){
            sum += it;
            mini = min(mini, it);
        }
        int n = nums.size();
        return sum - n * mini;
    }
};