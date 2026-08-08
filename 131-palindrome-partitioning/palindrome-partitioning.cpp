class Solution {
public:
    bool checkPalin(string t){
        int i = 0;
        int j = t.size()-1;
        while(i <= j){
            if(t[i] != t[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    void solve(int idx, int n, vector<string>&ds, vector<vector<string>>&ans, string& s){
        if(idx == n){
            ans.push_back(ds);
            return;
        }
        for(int i =idx; i<n; i++){
            if(checkPalin(s.substr(idx, i-idx+1))){
                ds.push_back(s.substr(idx, i-idx+1));
                solve(i+1, n, ds, ans, s);
                ds.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        int n = s.size();
        vector<vector<string>>ans;
        vector<string>ds;
        solve(0, n,ds, ans, s);
        return ans;
    }
};