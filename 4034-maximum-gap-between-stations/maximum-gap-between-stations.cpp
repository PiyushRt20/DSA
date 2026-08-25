class Solution {
public:
    int maximumGap(string skill, string station) {
        int n = skill.size();
        int m = station.size();
        vector<int>leftMostPossible(n);
        vector<int>rightMostPossible(n);
        int i =0;
        int j =0;
        while(i < n && j < m){
            if(skill[i] == station[j]){
                leftMostPossible[i] = j;
                i++;
            }
            j++;
        }
        // for(auto it : leftMostPossible){
        //     cout<<it<<endl;
        // }
        i = n-1;
        j = m-1;
        while(i >= 0 && j >=0){
            if(skill[i] == station[j]){
                rightMostPossible[i] = j;
                i--;
            }
            j--;
        }
        int maxi = 0;
        for(int i =1; i<n; i++){
            maxi = max(maxi, rightMostPossible[i] - leftMostPossible[i-1]);
        }
        return maxi;
    }
};