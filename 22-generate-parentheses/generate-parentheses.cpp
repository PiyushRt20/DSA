class Solution {
public:
    void solve(int open, int close, string &ds, vector<string>& ans, int n){
        if(open > n || close > open){
            return;
        }
        if(ds.size() == 2*n){
            ans.push_back(ds);
            return;
        }
        ds += '(';
        solve(open +1, close, ds, ans, n);
        ds.pop_back();
        ds += ')';
        solve(open, close+1, ds, ans, n);
        ds.pop_back();
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string ds = "";
        solve(0, 0, ds, ans, n);
        return ans;
    }
};