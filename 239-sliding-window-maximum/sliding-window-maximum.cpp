class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans;
        deque<int> dq;
        for(int i =0; i<n; i++){
            //maintaining correct window
            if(!dq.empty() && dq.front() <= i-k){
                dq.pop_front();
            }
            // to make it monotonic decreasing
            while(!dq.empty() && nums[dq.back()] < nums[i]){
                dq.pop_back();
            }
            // storing idx to dq
            dq.push_back(i);

            //pushing it to ans
            if(i >= k-1){
                ans.push_back(nums[dq.front()]);
            }
        }
        return ans;
    }
};