class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int mini = 1e9;
        for(auto it : strs){
            int m = it.size();
            mini = min(mini, m);
        }
        if(mini == 0){
            return "";
        }
        string s = strs[0];
        string ans = "";
        for(int i =0; i<mini; i++){
            bool flag = false;
            for(int j =1; j<strs.size(); j++){
                string t = strs[j];
                if(s[i] != t[i]){
                    flag = true;
                }
            }
            if(!flag){
                ans += s[i];
            }else{
                break;
            }
        }
        return ans;
    }
};