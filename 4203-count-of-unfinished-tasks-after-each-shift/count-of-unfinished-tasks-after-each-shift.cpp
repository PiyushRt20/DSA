class Solution {
public:
    vector<int> countTasks(vector<int>& tasks, vector<int>& shifts) {
        int n = tasks.size();
        vector<long long> preSum_task(n);
        preSum_task[0] = tasks[0];
        for(int i =1; i<n; i++){
            preSum_task[i] = preSum_task[i-1] + tasks[i];
        }
        int m = shifts.size();
        vector<int> ans(m);
        long long task = 0;
        for(int i =0; i<m; i++){
            task += shifts[i];
            int idx = upper_bound(preSum_task.begin(), preSum_task.end(), task) - preSum_task.begin();
            ans[i] = idx == n ? 0 : n - idx;
            if(task >= preSum_task[n-1]){
                task = 0;
            }
        }
        return ans;
    }
};