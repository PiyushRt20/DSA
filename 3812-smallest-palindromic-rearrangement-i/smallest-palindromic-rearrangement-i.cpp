class Solution {
public:
    string smallestPalindrome(string s) {
        map<char, int>mpp;
        for(auto it : s){
            mpp[it]++;
        }
        string ans = s;
        int n = s.size();
        int i =0;
        bool odd = false;
        char oddVal;
        for(auto it : mpp){
            int times = it.second/2;
            if(it.second % 2 != 0){
                oddVal = it.first;
                odd = true;
            }
            for(int j = i; j<i+times; j++){
                ans[j] = it.first;
                ans[n-j-1] = it.first;
            }
            i += times;
        }
        if(odd){
            ans[n/2] = oddVal;
        }
        return ans;
    }
};