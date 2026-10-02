class Solution {
public:
    void solve(int  open, int close, int n , vector<string> &ans, string ds){
        if(close > open){
            return;
        }
        if(open > n){
            return;
        }
        if(ds.size() == 2*n){
            ans.push_back(ds);
            return;
        }
        ds += '(';
        solve(open+1, close, n, ans, ds);
        ds.pop_back();
        ds += ')';
        solve(open, close+1, n, ans, ds);
        ds.pop_back();
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        solve(0, 0,n, ans, "");
        return ans;
    }
};