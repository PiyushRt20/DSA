class Solution {
public:
    int M = 1e9+7;
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int n = s.size();
        vector<long long>digits(n);
        vector<int>preSum(n);
        vector<int>nonZeroDigits(n);
        vector<long long>pow_10(n);
        preSum[0] = s[0] - '0';
        for(int i =1; i<n; i++){
            int digit = s[i] - '0';
            preSum[i] = preSum[i-1] + digit;
        }
        int notZero = 0;
        long long number = 0;
        for(int i =0; i<n; i++){
            if(s[i] != '0'){
                notZero++;
                int digit = s[i] - '0';
                number = (number*10 + digit) % M;
            }
            nonZeroDigits[i] = notZero;
            digits[i] = number;    
        }
        for(auto it : digits){
            cout<<it<<" ";
        }
        pow_10[0] = 1;
        for(int i =1; i<n; i++){
            pow_10[i] = (pow_10[i-1] * 10 % M);
        }
        vector<int>ans(queries.size(), 0);
        for(int i =0; i<queries.size(); i++){
            int l = queries[i][0];
            int r = queries[i][1];
            if(l == 0){
                ans[i] = (1LL * digits[r] * preSum[r]) % M;
            }
            else{
                int k = nonZeroDigits[r] - nonZeroDigits[l-1];
                int digitsBtw = (digits[r] - (digits[l-1] * pow_10[k] % M) + M) % M;
                long long sum = preSum[r] - preSum[l-1];
                ans[i] = (1LL * sum * digitsBtw) % M;
            }
        }
        return ans;
    }
};