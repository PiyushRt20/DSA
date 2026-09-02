class Solution {
public:
    bool checkValidString(string s) {
        stack<int> st, star;
        int n = s.size();
        for(int i =0; i<n; i++){
            if(s[i] == '('){
                st.push(i);
            }
            else if(s[i] == ')'){
                if(!st.empty() && s[st.top()] == '('){
                    st.pop();
                }
                else if(!star.empty()){
                    star.pop();
                }
                else{
                    return false;
                }
            }
            else{
                star.push(i);
            }
        }
        if(st.empty()){
            return true;
        }
        while(!st.empty() && !star.empty()){
            if(st.top() > star.top()){
                return false;
            }
            st.pop();
            star.pop();
        }
        return st.empty();
    }
};