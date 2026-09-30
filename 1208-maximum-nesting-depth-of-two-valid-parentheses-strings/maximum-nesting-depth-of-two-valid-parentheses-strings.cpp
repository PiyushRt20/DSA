class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        int depth = 0;
        int n = seq.size();
        vector<int> ans(n);
        for(int i =0; i<n; i++){
            if(seq[i] == '('){
                depth++;
                ans[i] = depth % 2;
            }
            else{
                ans[i] = depth % 2;
                depth--;
            }
        }
        return ans;
    }
};