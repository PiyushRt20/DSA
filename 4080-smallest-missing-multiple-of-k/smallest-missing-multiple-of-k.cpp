class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int> st(nums.begin(), nums.end());
        int i;
        for(i =k; i<=100; i+=k){
            if(!st.count(i)){
                return i;
            }
        }
        return i;
    }
};