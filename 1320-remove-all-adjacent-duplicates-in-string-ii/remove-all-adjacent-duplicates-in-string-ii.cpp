class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char, int>> st;
        for(auto it : s){
            if(!st.empty() && st.top().first == it){
                st.top().second++;
                if(st.top().second == k){
                    st.pop();
                }
            }
            else{
                st.push({it, 1});
            }
        }
        string ans = "";
        while(!st.empty()){
            while(st.top().second){
                ans += st.top().first;
                st.top().second--;
            }
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};