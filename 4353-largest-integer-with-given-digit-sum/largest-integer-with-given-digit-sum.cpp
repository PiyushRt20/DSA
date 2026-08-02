class Solution {
public:
    int largestInteger(int n, int s) {
        if(n*9 < s){
            return -1;
        }
        if(s == 0){
            return 0;
        }
        string res = "";
        for(int i =0; i<n; i++){
            int t = min(9, s);
            res += ('0' + t) ;
            s -= t;
        }
        return stoi(res);
    }
};