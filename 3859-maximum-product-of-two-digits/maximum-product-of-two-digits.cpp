class Solution {
public:
    int maxProduct(int n) {
        int maxi = 0;
        int secMaxi = 0;
        while(n > 0){
            int digit = n % 10;
            if(digit > maxi){
                secMaxi = maxi;
                maxi = digit;
            }
            else if(digit >= secMaxi){
                secMaxi = digit;
            }
            n /= 10;
        }
        return maxi * secMaxi;
    }
};