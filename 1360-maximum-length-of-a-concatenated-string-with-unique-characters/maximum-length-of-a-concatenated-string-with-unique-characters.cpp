class Solution {
public:
    int n;
    bool check_unique(string s1, string s2){
        vector<int> freq(26, 0);
        for(auto it : s1){
            if(freq[it - 'a'] == 1) return false;
            freq[it - 'a']++;
        }
        for(auto it : s2){
            if(freq[it - 'a'] == 1) return false;
            freq[it-'a']++;
        }
        return true;
    }
    int solve(int idx, string temp, vector<string>&arr){
        if(idx == n) return temp.size();
    
        int take_it = 0;
        int notTake = 0; 
        if(check_unique(temp, arr[idx])){
            take_it = max(solve(idx +1, temp + arr[idx], arr), solve(idx +1, temp, arr));
        }
        else{
            notTake = solve(idx+1, temp, arr);
        }
        return max(take_it, notTake);
    }
    int maxLength(vector<string>& arr) {
        n = arr.size();
        return solve(0, "", arr);
    }
};