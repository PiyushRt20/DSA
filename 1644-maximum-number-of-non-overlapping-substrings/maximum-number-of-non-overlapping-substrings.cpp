class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        vector<int> st_Idx(26, -1);
        vector<int> end_Idx(26, -1);
        int n = s.size();
        for(int i =0; i<n; i++){
            int idx = s[i] - 'a';
            if(st_Idx[idx] == -1){
                st_Idx[idx] = i;
            }
            end_Idx[idx] = i;
        }
        vector<bool> isValid(26, true);
        for(int i =0; i<26; i++){
            int stIdx = st_Idx[i];
            if(stIdx == -1) continue;
            for(int j = stIdx; j <= end_Idx[i]; j++){
                if(st_Idx[s[j]-'a'] < stIdx){
                    isValid[i] = false;
                    break;
                }
                end_Idx[i] = max(end_Idx[i], end_Idx[s[j]-'a']);
            }
        }
        vector<string> ans;
        int lastTakenStart = 1e9;
        
        for (int i = n-1; i>=0; i--) {
            int c = s[i] - 'a';

            if(!isValid[c]) continue;

            if (i == st_Idx[c] && end_Idx[c] < lastTakenStart) { //must not over lap with any last taken substring
                ans.push_back(s.substr(i, end_Idx[c] - i + 1));
                lastTakenStart = i;
            }
        }

        return ans;
    }
};