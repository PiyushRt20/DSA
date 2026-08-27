class Solution {
public:
    string ans = "";
    bool solve(int idx, string& res, string& target, vector<int>&freq, bool greater){
        if(idx == target.size()){
            if(greater == true){
                ans = res;
                return true;
            }
            return false;
        }
        for(char ch = 'a'; ch<='z'; ch++){
            if(freq[ch-'a'] == 0) continue;
            if(greater == false && ch < target[idx]){
                continue;
            }
            res.push_back(ch);
            freq[ch-'a']--;
            bool isGreater = ch > target[idx] || greater;
            if(solve(idx+1, res, target, freq, isGreater)){
                return true;
            }
            res.pop_back();
            freq[ch - 'a']++;
        }
        return false;
    }
    string lexGreaterPermutation(string s, string target) {
        vector<int> freq(26, 0);
        int n = s.size();
        for(int i =0; i<n; i++){
            freq[s[i]- 'a']++;
        }
        string res = "";
        solve(0, ans, target, freq, false);
        return ans;
    }
};