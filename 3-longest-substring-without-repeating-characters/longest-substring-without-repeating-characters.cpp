class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> mpp;
        int l = 0;
        int maxi = 0;
        for(int r =0; r<s.size(); r++){
            mpp[s[r]]++;
            while(mpp[s[r]] > 1){
                mpp[s[l]]--;
                l++;
            }
            maxi = max(r -l +1, maxi);
        }
        return maxi;
    }
};