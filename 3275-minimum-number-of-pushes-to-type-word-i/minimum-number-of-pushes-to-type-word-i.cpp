class Solution {
public:
    int minimumPushes(string word) {
        int n = word.size();
        int ans = 0;
        for(int i =1; i<=n; i++){
            if(i <= 8){
                ans += 1;
            }
            else if(i > 8 && i < 17){
                ans += 2;
            }
            else if(i > 16 && i < 25){
                ans += 3;
            }
            else{
                ans += 4;
            }
        }
        return ans;
    }
};