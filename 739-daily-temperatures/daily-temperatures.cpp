class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> nge(n);
        stack<int> st;
        for(int i = n-1; i>= 0; i--){
            while(!st.empty() && temperatures[i] >= temperatures[st.top()]){
                st.pop();
            }
            nge[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        vector<int> ans(n, 0);
        for(int i =0; i<n; i++){
            if(nge[i] == n) continue;
            ans[i] = nge[i] - i;
        }
        return ans;
    }
};