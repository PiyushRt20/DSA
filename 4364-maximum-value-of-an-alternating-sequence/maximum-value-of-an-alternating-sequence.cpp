class Solution {
public:
    long long maximumValue(int n, int s, int m) {
        if(n==1){
            return s;
        }
        long long ans = 0;
        int times = n/2;
        ans = (long long)s + 1LL * m * times;
        // cout<<ans;
        long long minus = times - 1;
        return ans - minus;
    }
};