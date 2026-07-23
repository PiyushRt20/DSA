class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        if(nums.size() < 3){
            return nums.size();
        }
        int bits = 0;
        while((1 << bits) <= nums.size()){
            bits++;
        }
        return (1 << bits);
    }
};