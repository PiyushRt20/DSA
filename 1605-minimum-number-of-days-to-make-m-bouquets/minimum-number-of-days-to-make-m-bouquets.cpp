class Solution {
public:
    bool possible(vector<int>& arr, int day, int m, int k){
        int cnt =0;
        int noOfB = 0;
        for(int i=0; i<arr.size(); i++){
            if(arr[i] <= day){
                cnt++;
            }
            else{
                noOfB += cnt/k;
                cnt =0;
            }
        }
        noOfB += cnt/k;
        if(noOfB >= m){
            return true;
        }
        else{
            return false;
        }
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        if (1LL * m * k > bloomDay.size()) return -1;
        int ans =-1;
        int mini = *min_element(bloomDay.begin(), bloomDay.end());
        int maxi = *max_element(bloomDay.begin(), bloomDay.end());
        int low = mini;
        int high = maxi;
        while(low<= high){
            int mid = (low+high) /2;
            if(possible(bloomDay, mid, m,k)){
                ans = mid;
                high = mid -1;
            }
            else{
                low = mid+1;
            }
        }
        return ans;
    }
};