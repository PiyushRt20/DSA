class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string, string> mpp;
        for(auto it : knowledge){
            string a = it[0];
            string b = it[1];
            mpp[a] = b;
        }
        string ans = "";
        for(int i =0; i<s.size(); i++){
            if(s[i] != '('){
                ans += s[i];
            }
            else{
                string key = "";
                i++;
                while(s[i] != ')'){
                    key += s[i];
                    i++;
                }
                if(mpp.find(key) != mpp.end()){
                    ans += mpp[key];
                }
                else{
                    ans += '?';
                }
            }
        }
        return ans;
    }
};