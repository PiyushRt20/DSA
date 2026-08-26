class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        string ans = "";
        int ansLen = 1e9;
        // long long mini = LLONG_MAX;
        int n = s.size();
        int l = 0;
        int cnt1 = 0;
        for(int r = 0; r<n; r++){
            if(s[r] == '1'){
                cnt1++;
            }
            while(cnt1 >= k){
                if(s[l] == '1' && cnt1 == k){
                    break;
                    l++;
                }
                if(s[l] == '1'){
                    cnt1--;
                }
                l++;
            }
            if(cnt1 == k){
                int len = r - l +1;
                // long long val = stoll(s.substr(l, len), nullptr, 2);
                // cout<<val<<endl;
                // if(len <= lenofAns){
                //     if(val < mini){
                //         ans = s.substr(l, len);
                //         mini = val;
                //         lenofAns = len;
                //     }
                // }
                if(len < ansLen){
                    ans = s.substr(l, len);
                    ansLen = len;
                }
                else if(len == ansLen){
                    if(s.substr(l, len) < ans){
                        ans = s.substr(l, len);
                    }
                }
            }
        }
        return ans;
    }
};