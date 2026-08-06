class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for(int i =0; i<tokens.size(); i++){
            if(tokens[i] == "*"){
                int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();
                int val = a * b;
                st.push(val);
            }
            else if(tokens[i] == "/"){
                int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();
                int val = b / a;
                st.push(val);
            }
            else if(tokens[i] == "+"){
                int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();
                int val = a + b;
                st.push(val);
            }
            else if(tokens[i] == "-"){
                int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();
                int val = b - a;
                st.push(val);
            }
            else{
                int val = stoi(tokens[i]);
                st.push(val);
            }
        }
        return st.top();
    }
};