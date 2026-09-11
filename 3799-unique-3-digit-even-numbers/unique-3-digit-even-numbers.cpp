class Solution {
public:
    void solve(vector<int>& digits, unordered_set<int>& st, string ds, unordered_map<int, int>mpp){
        if(!ds.empty() && ds[0] == '0'){
            return;
        }
        if(ds.size() == 3){
            int val = stoi(ds);
            if(val % 2 == 0){
                st.insert(val);
            }
            return;
        }
        for(int i =0; i<digits.size(); i++){
            string s = to_string(digits[i]);
            if(mpp[digits[i]] != 0){
                mpp[digits[i]]--;
                ds += s;
                solve(digits, st, ds, mpp);
                ds.pop_back();
                mpp[digits[i]]++;
            }
        }
    }
    int totalNumbers(vector<int>& digits) {
        unordered_set<int> st;
        unordered_map<int, int>mpp;
        for(auto it : digits){
            mpp[it]++;
        }
        solve(digits, st, "", mpp);
        return st.size();
    }
};