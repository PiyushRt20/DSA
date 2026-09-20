class Solution {
public:
    int reverseDegree(string s) {
        int val = 26;
        vector<int> alp(26, 0);
        for(int i =0; i<26; i++){
            alp[i] = val;
            val--;
        }
        long long ans = 0;
        for(int i =0; i<s.size(); i++){
            int add = (i+1) * alp[s[i]-'a'];
            ans += add;
        }
        return ans;
    }
};