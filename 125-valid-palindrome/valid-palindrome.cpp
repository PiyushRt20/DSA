class Solution {
public:
    bool isPalindrome(string s) {
        string t = "";
        int n = s.size();
        for(int i = 0; i<n; i++){
            if(isalnum(s[i])){
                char ch = tolower(s[i]);
                t += ch;
            }
        }
        int l =0;
        int r = t.size()-1;
        while(l < r){
            if(t[l] != t[r]){
                return false;
            }
            l++;
            r--;
        }
        return true;
    }
};