class Solution {
public:
    string removeStars(string s) {
        stack<char> st;
        for(auto it : s){
            if(it == '*'){
                st.pop();
            }
            else{
                st.push(it);
            }
        }
        string ans = "";
        if(st.empty()){
            return "";
        }
        while(!st.empty()){
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};