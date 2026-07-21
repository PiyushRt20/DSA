class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        vector<int> consecutiveZeroes;
        int cnt = 0;
        int cnt1 = -1;
        string t = '1' + s + '1';
        for(int i =1; i< t.size(); i++){
            if(t[i] == '0'){
                cnt++;
            }
            else{
                cnt1++;
                if(cnt > 0){
                    consecutiveZeroes.push_back(cnt);
                    cnt = 0;
                }
            }
        }
        // for(auto it : consecutiveZeroes){
        //     cout<<it<<" ";
        // }
        if(consecutiveZeroes.size() > 1){
            int maxi = 0;
            for(int i =0; i<consecutiveZeroes.size()-1; i++){
                int sum = consecutiveZeroes[i] + consecutiveZeroes[i+1];
                maxi = max(maxi, sum);
            }
            return maxi + cnt1;
        }
        return cnt1;
    }
};