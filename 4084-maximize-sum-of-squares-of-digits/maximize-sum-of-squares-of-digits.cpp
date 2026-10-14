class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        string ans = "";
        while(sum > 0){
            if(sum > 9){
                ans += '9';
                sum -= 9;
            }
            else{
                ans += to_string(sum);
                sum = 0;
            }
        }
        if(ans.size() < num){
            int leftOver = num - ans.size();
            while(leftOver--){
                ans += '0';
            }
            return ans;
        }
        else if(ans.size() == num){
            return ans;
        }
        return "";
    }
};