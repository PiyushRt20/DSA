class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int n = nums1.size();
        int oddCnt = 0;
        int minOdd = 1e9;
        int minEven = 1e9;
        for(int i =0; i<n; i++){
            if(nums1[i] % 2 == 1){
                oddCnt++;
                minOdd = min(minOdd, nums1[i]);
            }
            else{
                minEven = min(minEven, nums1[i]);
            }
        }
        if(oddCnt == n){
            return true;
        }
        else if(oddCnt == 0){
            return true;
        }
        else if(minEven - minOdd >= 1){
            return true;
        }
        return false;
    }
};