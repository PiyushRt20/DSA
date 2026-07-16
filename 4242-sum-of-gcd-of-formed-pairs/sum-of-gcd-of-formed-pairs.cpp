class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int n = nums.size();
        vector<long long> prefixGcd(n);
        int maxi = INT_MIN;
        for(int i =0; i<n; i++){
            maxi = max(maxi, nums[i]);
            prefixGcd[i] = gcd(maxi, nums[i]);
        }
        sort(prefixGcd.begin(), prefixGcd.end());
        int l = 0;
        int r = n-1;
        long long ans = 0;
        while(l<r){
            ans += gcd(prefixGcd[l],prefixGcd[r]);
            l++;
            r--;
        }
        return ans;
    }
};