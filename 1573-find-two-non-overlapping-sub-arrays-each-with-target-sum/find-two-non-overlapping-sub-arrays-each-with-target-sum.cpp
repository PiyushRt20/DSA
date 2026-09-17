class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int l =0;
        int sum = 0;
        int n = arr.size();
        int ans = 1e9;
        int mini = 1e9;
        vector<int> subLenTillIdx(n, 1e9);
        for(int r = 0; r<n; r++){
            sum += arr[r];
            while(sum > target){
                sum -= arr[l];
                l++;
            }
            int len = r-l+1;
            if(sum == target){
                if(r > 0 && subLenTillIdx[r-1] != 1e9){
                    ans = min(ans, len + subLenTillIdx[l-1]);
                }
                mini = min(mini, len);
            }    
            subLenTillIdx[r] = mini;
        }
        return ans == 1e9 ? -1 : ans;
    }
};