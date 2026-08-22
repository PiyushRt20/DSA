class Solution {
public:
    bool checkDivisibility(int n) {
        int pro = 1;
        int sum = 0;
        int m = n;
        while(n>0){
            int digit = n%10;
            pro *= digit;
            sum += digit;
            n /= 10;
        }
        return m % (pro + sum ) == 0; 
    }
};