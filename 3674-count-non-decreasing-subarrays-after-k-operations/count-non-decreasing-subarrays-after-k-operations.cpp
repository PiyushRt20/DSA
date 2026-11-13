class Solution {
public:
    long long countNonDecreasingSubarrays(vector<int>& nums, int k) {
        //Brute force
        // long long ans = 0;
        // int n = nums.size();
        // for(int i =0; i<n; i++){
        //     int maxi = nums[i];
        //     int change =0;
        //     bool flag = false;
        //     for(int j=i; j<n; j++){
        //         maxi = max(maxi, nums[j]);
        //         change += maxi - nums[j];
        //         if(change > k){
        //             flag = true;
        //             ans += j-i;
        //             break;
        //         }
        //     }
        //     if(!flag){
        //         ans += n-i;
        //     }
        // }
        // return ans;
        deque<pair<int, int>> dq;
        long long ans = 0;
        int n = nums.size();
        long long operations =0;
        int r = n-1;
        for(int l = n-1; l>=0; l--){
            int cnt =0;
            while(!dq.empty() && dq.front().first <= nums[l]){
                operations += 1LL * (nums[l] - dq.front().first) * dq.front().second;
                cnt += dq.front().second;
                dq.pop_front();
            }
            dq.push_front({nums[l],cnt+1});
            while(!dq.empty() && operations > k){
                operations -= dq.back().first - nums[r];
                dq.back().second--;
                if(dq.back().second == 0){
                    dq.pop_back();
                }
                r--;
            }
            ans += r - l +1;


        }
        return ans;
    }
};