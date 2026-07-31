class Solution {
public:
    int minimumPushes(string word) {
        vector<int> freq(26, 0);
        for(auto it : word){
            freq[it - 'a']++;
        }
        vector<int> cnt;
        for(int i =0; i<26; i++){
            if(freq[i] > 0){
                cnt.push_back(freq[i]);
            }
        }
        sort(cnt.rbegin(), cnt.rend());
        int m = cnt.size();
        int ans = 0;
        for(int i =0; i<min(m, 26); i++){
            if(i >= 0 && i <= 7){
                ans += cnt[i] * 1;
            }
            else if(i > 7 && i < 16){
                ans += cnt[i] * 2; 
            }
            else if(i >= 16 && i < 24){
                ans += cnt[i] * 3;
            }
            else{
                ans += cnt[i] * 4;
            }
        }
        return ans;
    }
};