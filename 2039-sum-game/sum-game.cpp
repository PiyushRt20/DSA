class Solution {
public:
    bool sumGame(string num) {
        int leftSum = 0;
        int rightSum = 0;
        int leftQues = 0;
        int rightQues = 0;
        int n = num.size();
        for(int i =0; i<n; i++){
            if(num[i] == '?'){
                if(i < n/2){
                    leftQues++;
                }
                else{
                    rightQues++;
                }
            }
            else{
                if(i < n/2){
                    leftSum += num[i] - '0';
                }
                else{
                    rightSum += num[i] - '0';
                }
            }
        }
        int totalQues = leftQues + rightQues;
        if(totalQues % 2 != 0){
            return true;
        }
        int leftTotalSum = 2 * leftSum + 9 * leftQues;
        int rightTotalSum = 2 * rightSum + 9 * rightQues;
        return leftTotalSum != rightTotalSum;
    }
};