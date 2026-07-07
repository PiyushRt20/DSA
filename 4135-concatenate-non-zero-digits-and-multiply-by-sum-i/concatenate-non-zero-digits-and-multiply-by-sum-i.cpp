class Solution {
public:
    long long sumAndMultiply(int n) {
        if(n== 0){
            return 0;
        }
        string s = to_string(n);
        int sum = 0;
        string x = "";
        for(auto it : s){
            if(it != '0'){
                x += it;
                sum += it - '0';
            }
        }
        int mul = stoi(x);
        long long ans = 1LL * mul * sum;
        return ans;
    }
};