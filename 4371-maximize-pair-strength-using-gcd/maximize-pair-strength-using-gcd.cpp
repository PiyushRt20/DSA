class Solution {
public:
    long long maxPairStrength(vector<int>& nums) {
        int n = nums.size();
        long long maxi = 0;
        for(int i=0; i<n; i++){
            for(int j =i+1; j<n; j++){
                long long mul = 1LL * nums[i] * nums[j];
                long long g = gcd(nums[i], nums[j]);
                g = 1LL * g * g;
                long long val = mul / g;
                maxi = max(maxi , val);
            }
        }
        return maxi;
    }
};