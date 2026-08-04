class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_map<string, vector<string>> mpp;
        for(auto it : strs){
            string s = it;
            sort(s.begin(), s.end());
            mpp[s].push_back(it);
        }
        for(auto it : mpp){
            ans.push_back({it.second});
        }
        return ans;
    }
};