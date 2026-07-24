class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        unordered_set<int> s;
        int n = nums.size();
        for(int i =0; i<n; i++){
            for(int j =i; j<n; j++){
                s.insert(nums[i] ^ nums[j]);
            }
        }
        unordered_set<int> s1;
        for(auto it : s){
            for(auto i : nums){
                s1.insert(it ^ i);
            }
        }
        return s1.size();
    }
};