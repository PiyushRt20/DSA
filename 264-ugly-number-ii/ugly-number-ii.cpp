class Solution {
public:
    int nthUglyNumber(int n) {
        
        vector<int> dp(n+1);
        //first ugly number
        dp[1] = 1;

        int i2, i3, i5;
        i2 = i3 = i5 = 1;
        for(int i =2; i<=n; i++){
            int i2Ugly = dp[i2] * 2;
            int i3Ugly = dp[i3] * 3;
            int i5Ugly = dp[i5] * 5;

            int miniUgly = min({i2Ugly, i3Ugly, i5Ugly});
            dp[i] = miniUgly;

            if(miniUgly == i2Ugly){
                i2++;
            }
            if(miniUgly == i3Ugly){
                i3++;
            }
            if(miniUgly == i5Ugly){
                i5++;
            }
        }
        return dp[n];
    }
};