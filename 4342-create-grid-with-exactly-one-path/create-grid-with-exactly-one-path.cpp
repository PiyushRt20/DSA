class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<string>ans;
        for(int i =0; i<m-1; i++){
            string ds = "";
            for(int j =0; j<n; j++){
                if(j == 0){
                    ds += ".";
                }else{
                    ds += "#";
                }
            }
            ans.push_back(ds);
        }
        string ds = "";
        for(int i =0; i<n; i++){
            ds += ".";
        }
        ans.push_back(ds);
        return ans;
    }
};