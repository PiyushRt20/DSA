class Solution {
public:
    int minAddToMakeValid(string s) {
        int depth = 0;
        int ans = 0;
        for(auto it : s){
            if(it == '('){
                depth++;
            }
            else{
                depth--;  
            }
            if(depth < 0 ){
                ans++;
                depth = 0;
            }
        }
        if(depth == 0){
            return ans;
        }
        if(depth > 0 ){
            ans += depth;
        }
        return ans;
    }
};