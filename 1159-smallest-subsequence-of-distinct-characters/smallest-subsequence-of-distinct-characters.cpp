class Solution {
public:
    string smallestSubsequence(string s) {
        stack<int> st;
        vector<int>freq(26, 0);
        for(auto it : s){
            freq[it- 'a']++;
        }
        vector<bool>inStack(26, false);
        for(int i =0; i<s.size(); i++){
            int val = s[i] - 'a';
            if(inStack[val] == false){
                while(!st.empty() && val <= st.top() && freq[st.top()] > 0){
                    inStack[st.top()] = false;
                    st.pop();
                }
                st.push(val);
                inStack[val] = true;
                freq[val]--;
            }
            else{
                freq[val]--;
            }
        }
        string t = "";
        while(!st.empty()){
            int val = st.top();
            t += char(val + 'a');
            st.pop();
        }
        reverse(t.begin(), t.end());
        return t;
    }
};