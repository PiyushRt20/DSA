class Solution {
public:
    long long nCr(int n, int r, int k){
        r = min(r, n-r);
        long long result = 1;
        for(int i =1; i<= r; i++){
            result = result * (n - r + i) / i;
            if(result >= k){
                return k;
            }
        }
        return result;
    }
    string smallestPalindrome(string s, int k) {
        int n = s.size();
        string ans = "";
        // int cntLetters = 0;
        vector<int> count(26, 0);
        for(int i =0; i<n/2; i++){
            count[s[i] - 'a']++;
            // cntLetters++;
        }
        // long long tways = 1;
        // for(int i =0; i<26; i++){
        //     if(count[i] > 0){
        //         tways *= nCr(cntLetters, count[i], k);
        //         cntLetters -= count[i];
        //     }
        //     if(tways >= k){
        //         break;
        //     }
        // }
        // if(tways < k){
        //     return "";
        // }

        for(int i =0; i<n/2; i++){
            bool placedChar = false;
            for(int j = 0; j<26; j++){
                if(count[j] > 0){
                    count[j]--;
                    long long ways = 1;
                    int totalLetters = 0;
                    for(int c =0; c<26; c++){
                        totalLetters += count[c];
                    }
                    for(int c =0; c<26; c++){
                        if(count[c] > 0){
                            ways *= nCr(totalLetters, count[c], k); 
                            totalLetters -= count[c];
                        }

                        if(ways >= k) break;
                    }
                    if(ways >= k){
                        ans.push_back(j + 'a');
                        placedChar = true;
                        break;
                    }
                    k -= ways;
                    count[j]++;
                }
            }
            if(placedChar == false){
                return "";
            }
        }
        string r = ans;
        reverse(r.begin(), r.end());
        if(n % 2 != 0){
            ans += s[n/2];
        }
        ans += r;
        return ans;
    }
};