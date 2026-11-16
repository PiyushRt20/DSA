class Solution {
public:
    string digitSum(string s, int k) {
        string t = s;
        while(t.size() > k){
            int n = t.size();
            int val = 0;
            string res = "";
            for(int i =0; i<n; i++){
                val += t[i] - '0';
                if((i+1) % k == 0){
                    res += to_string(val);
                    val = 0;
                }
                else if(i == n-1 && n % k != 0){
                    res += to_string(val);
                    val = 0;
                }
            }
            t = res;
        }
        return t;
    }
};