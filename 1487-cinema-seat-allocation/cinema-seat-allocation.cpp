class Solution {
public:
    struct node{
        bool seat1 = true;
        bool seat2 = true;
        bool seat3 = true;
    };
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        map<int, node> mpp;
        for(auto it : reservedSeats){
            int a = it[0];
            int b = it[1];
            if((b == 2 || b==3)){
                mpp[a].seat1 = false;
            }
            else if((b == 4 || b==5)){
                mpp[a].seat1 = false;
                mpp[a].seat2 = false;
            }
            else if((b == 6 || b==7)){
                mpp[a].seat2 = false;
                mpp[a].seat3 = false;
            }
            else if((b == 8 || b==9)){
                mpp[a].seat3 = false;
            }
        }
        int cnt = 0;
        for(auto [it, s] : mpp){
            if(s.seat1 && s.seat2 && s.seat3){
                cnt += 2;
            }
            else if(!s.seat1 && !s.seat2 && !s.seat3){
                cnt += 0;
            }
            else{
                cnt += 1;
            }
        }
        int m = mpp.size();
        int val2 = n - m;
        val2 *= 2;
        cnt += val2;
        return cnt;
    }
};