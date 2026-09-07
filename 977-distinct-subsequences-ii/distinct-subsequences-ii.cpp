class Solution {
public:
    // void solve(int idx, int n, string& s, string& ds, unordered_set<string>& st){
    //     if(idx == n){
    //         st.insert(ds);
    //         return;
    //     }
    //     ds.push_back(s[idx]);
    //     solve(idx+1, n, s, ds, st);
    //     ds.pop_back();
    //     solve(idx+1, n, s, ds, st);
    // }
    int distinctSubseqII(string s) {
    //     int n = s.size();
    //     unordered_set<string> st;
    //     string ds = "";
    //     solve(0, n, s, ds, st);
    //     // for(auto it : st){
    //     //     cout<<it<<" ";
    //     // }
    //     return st.size()-1;
        const int MOD = 1e9 + 7;
        int total = 0;
        int end[26] = {0};

        for (char c : s) {
            int index = c - 'a';
            int oldTotal = total;
            int newSubsequences = (oldTotal + 1 - end[index] + MOD) % MOD;
            total = (total + newSubsequences) % MOD;
            end[index] = (end[index] + newSubsequences) % MOD;
        }
        return total;
    }
};

