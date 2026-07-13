class Solution {
public:
    void solve(long long num, int low, int high, vector<int>&ans){
        if(num > high){
            return;
        }
        if(num >= low && num <= high){
            ans.push_back(num);
        }
        for(int i =1; i<=9; i++){
            int digit1 = num % 10;
            long long newNum = num * 10 + i;
            int digit2 = newNum % 10;
            string s = to_string(newNum);
            int n = s.size();
            if(n == 1 || (n>1 && digit1 +1 == digit2)){
                solve(newNum, low, high, ans);
            }
        }
    }
    vector<int> sequentialDigits(int low, int high) {
        vector<int>ans;
        long long num = 0;
        solve(num, low, high, ans);
        sort(ans.begin(), ans.end());
        return ans;
    }
};