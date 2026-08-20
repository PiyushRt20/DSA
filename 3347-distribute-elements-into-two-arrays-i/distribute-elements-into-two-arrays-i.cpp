class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        vector<int>arr1;
        vector<int>arr2;
        arr1.push_back(nums[0]);
        arr2.push_back(nums[1]);
        int j = 0;
        int k = 0;
        int n = nums.size();
        for(int i =2; i<n; i++){
            if(arr1[j] > arr2[k]){
                arr1.push_back(nums[i]);
                j++;
            }
            else{
                arr2.push_back(nums[i]);
                k++;
            }
        }
        vector<int> res = arr1;
        res.insert(res.end(), arr2.begin(), arr2.end());
        return res;
    }
};