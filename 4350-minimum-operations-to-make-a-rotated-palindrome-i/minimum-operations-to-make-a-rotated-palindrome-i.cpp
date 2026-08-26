class Solution {
public:
    bool isPalin(string &s, int i , int j){
        while(i < j){
            if(s[i] != s[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    int minOperations(string s) {
        int n = s.size();
        if(isPalin(s, 0, n-1)){
            return 0;
        }
        int mini = 1e9;
        for(int k =0; k<n; k++){
            string t = s;
            rotate(t.begin(), t.begin()+k, t.end());
            int cnt = k;
            int i =0;
            int j = n-1;
            while(i < j){
                int char1 = t[i] - 'a';
                int char2 = t[j] - 'a';
                int val = abs(char1 - char2);
                int cost = min(val , 26 - val);
                cnt += cost;
                i++;
                j--;
            }
            mini = min(mini, cnt);
        }
        return mini;
    }
};