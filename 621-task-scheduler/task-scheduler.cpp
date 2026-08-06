class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int maxi = 0;
        unordered_map<char, int> mpp;
        for(auto it : tasks){
            mpp[it]++;
            maxi = max(maxi, mpp[it]);
        }
        int cnt = 0;
        for(auto it : mpp){
            if(it.second == maxi){
                cnt++;
            }
        }
        int ans = 0;
        ans += (maxi-1) * n + maxi;
        if(cnt > 1){
            cnt--;
            ans += cnt;
        }
        if(tasks.size() > ans){
            return tasks.size();
        }
        return ans;
    }
};