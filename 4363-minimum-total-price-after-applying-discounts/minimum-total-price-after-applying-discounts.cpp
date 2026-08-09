class Solution {
public:
    double minPrice(vector<int>& prices, vector<int>& discounts) {
        sort(prices.rbegin(),prices.rend());
        sort(discounts.rbegin(),discounts.rend());
        int i = 0;
        int j = 0;
        int n = prices.size();
        int m = discounts.size();
        double ans = 0;
        while(i <n && j <m){
            double add = (double)prices[i] * (100 - discounts[j])/100;
            ans += add;
            i++;
            j++;
        }
        while(i < n){
            ans += prices[i];
            i++;
        }
        return ans;
    }
};