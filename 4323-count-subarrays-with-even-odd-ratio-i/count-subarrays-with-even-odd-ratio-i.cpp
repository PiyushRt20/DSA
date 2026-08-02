class Solution {
public:
    int countRatioSubarrays(vector<int>& nums, int a, int b) {
        int n = nums.size();
        vector<int> odd_count(n);
        vector<int> even_count(n);
        int even = 0;
        int odd = 0;
        for(int i =0; i<n; i++){
            if(nums[i] % 2 == 0){
                even++;
            }
            else{
                odd++;
            }
            odd_count[i] = odd;
            even_count[i] = even;
        }
        int ans = 0;
        double check = double(a) / b;
        for(int i =0; i<n; i++){
            odd = 0;
            even = 0;
            for(int j = i; j<n; j++){
                if(i == 0){
                    odd = odd_count[j];
                    even = even_count[j];
                }
                else{
                    odd = odd_count[j] - odd_count[i-1];
                    even = even_count[j] - even_count[i-1];
                }
                double d = double(even) / odd;
                if(odd > 0 && d <= check){
                    ans++;
                }
            }
        }
        return ans;
    }
};