class Solution {
public:
    int myAtoi(string s) {
        string t = "";
        int idx = 0;
        while(idx < s.size() && s[idx] == ' '){
            idx++;
        }
        bool neg = false;
        bool pos = false;
        if(s[idx] == '-'){
            neg = true;
        }
        if(s[idx] == '+') pos = true;
        int j = neg || pos ? idx+1 : idx;
        while(j < s.size() && s[j] == '0'){
            j++;
        }
        for(int i =j; i<s.size(); i++){
            if(!isdigit(s[i])) break;
            t += s[i];
        }
        if(t.size() == 0){
            return 0;
        } 
        long long num = 0;
        int i = 0;
        while(i<t.size()){
            int digit = t[i] - '0';
            num = num * 10 + digit;

            if(num > INT_MAX) {
                return neg ? INT_MIN : INT_MAX;
            }
            i++;
        }
        return neg ? num * -1 : num;
    }
};