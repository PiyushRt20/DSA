class Solution {
public:
    string reverseParentheses(string s) {
        stack<char> st;
        int n = s.size();
        for(int i =0; i<n; i++){
            if(s[i] != ')'){
                st.push(s[i]);
            }
            else{
                string res = "";
                while(!st.empty() && st.top() != '('){
                    res += st.top();
                    st.pop();
                }
                st.pop();
                for(int j =0; j<res.size(); j++){
                    st.push(res[j]);
                }
            }
        }
        string ans = "";
        while(!st.empty()){
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};