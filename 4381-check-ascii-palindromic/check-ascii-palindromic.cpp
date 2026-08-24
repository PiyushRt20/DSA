class Solution {
public:
    bool isPalindromic(string s) {
        string t = "";
        int n = s.size();
        for(int i=0; i<n; i++){
            int val = s[i];
            string bin = bitset<8>(val).to_string();
            t += bin;
        }
        cout<<t;
        int m = t.size();
        for(int i =0; i<m/2; i++){
            if(t[i] != t[m-i-1]){
                return false;
            }
        }
        return true;
    }
};