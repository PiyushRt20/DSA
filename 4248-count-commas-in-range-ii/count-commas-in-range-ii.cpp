class Solution {
public:
    long long countCommas(long long n) {
        long long ans = 0;
        long long l = 1000;
        while(l <= n){
            ans += (n - l) + 1;
            l *= 1000;
        }
        return ans;
    }
};