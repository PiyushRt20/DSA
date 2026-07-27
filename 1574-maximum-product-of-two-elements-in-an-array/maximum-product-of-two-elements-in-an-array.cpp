class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxi = 0;
        int secMaxi = 0;
        int n = nums.size();
        for(int i =0; i<n; i++){
            if(nums[i] > maxi ){
                secMaxi = maxi;
                maxi = nums[i];
            }
            else if(nums[i] > secMaxi){
                secMaxi = nums[i];
            }
        }
        maxi -= 1;
        secMaxi -= 1;
        return maxi * secMaxi;
    }
};