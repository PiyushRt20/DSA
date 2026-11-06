class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
        int m = logs.size();
        int q = queries.size();

        sort(logs.begin(), logs.end(), [](vector<int>& a, vector<int>& b) {
            return a[1] < b[1];
        });

        vector<pair<int,int>> arr;

        for(int i = 0; i < q; i++){
            arr.push_back({queries[i], i});
        }

        sort(arr.begin(), arr.end());

        unordered_map<int,int> mp;

        vector<int> ans(q);

        int i = 0;
        int j = 0;

        for(int k = 0; k < q; k++){

            int time = arr[k].first;
            int idx = arr[k].second;

            int start = time - x;
            int end = time;

            // Expansion
            while(j < m && logs[j][1] <= end){
                mp[logs[j][0]]++;
                j++;
            }

            // Shrinking
            while(i < m && logs[i][1] < start){
                mp[logs[i][0]]--;

                if(mp[logs[i][0]] == 0){
                    mp.erase(logs[i][0]);
                }

                i++;
            }

            ans[idx] = n - mp.size();
        }

        return ans;
    }
};