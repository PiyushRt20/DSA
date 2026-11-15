class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int n = arr.size();
        int M = 1e9+7;
        vector<long long> preSum(n, 0);
        preSum[0] = arr[0];
        for(int i =1; i<n; i++){
            preSum[i] = preSum[i-1] + arr[i];
        }
        int oddSum = 0;
        int evenSum = 1; //as 0 is also even
        int ans = 0;
        for(int i =0; i<n; i++){
            if(preSum[i] % 2 == 0){
                ans = (ans + oddSum) % M;
                evenSum++;
            }
            else{
                ans = (ans + evenSum) % M;
                oddSum++;
            }
        }
        return ans;
    }
};