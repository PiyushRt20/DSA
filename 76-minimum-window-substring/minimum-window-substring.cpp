class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> mpp;
        for(auto it : t){
            mpp[it]++;
        }
        int n = s.size();
        int m = t.size();
        int minLen = 1e9;
        int l = 0;
        int cnt = 0;
        int idx = -1;
        for(int r = 0; r<n; r++){
            if(mpp.find(s[r]) != mpp.end()){
                if(mpp[s[r]] > 0){
                    cnt++;
                }
            }
            mpp[s[r]]--;
            if(cnt == m){
                minLen = min(minLen, r-l+1);
                if(minLen == r-l+1){
                    idx = l;
                }
                while(cnt == m){
                    mpp[s[l]]++;
                    if(mpp[s[l]] > 0){
                        cnt--;
                    }
                    l++;
                    if(cnt == m){
                        minLen = min(minLen, r-l+1);
                        if(minLen == r-l+1){
                            idx = l;
                        }
                    }
                }
            }
        }
        if(minLen == 1e9) return  "";
        return s.substr(idx, minLen);
    }
};