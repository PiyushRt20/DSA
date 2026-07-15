class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        int sumO = 0;
        int sumE = 0;
        int even = 2;
        int odd = 1;
        while(n--){
            sumO += even;
            even += 2;
            sumE += odd;
            odd += 2;
        }
        int ans = gcd(sumO, sumE);
        return ans;
    }
};