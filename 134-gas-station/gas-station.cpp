class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int tgas = accumulate(gas.begin(), gas.end(), 0);
        int tcost = accumulate(cost.begin(), cost.end(), 0);
        if(tcost > tgas){
            return -1;
        }
        int n = gas.size();
        int idx = 0;
        int sum = 0;
        for(int i =0; i<n; i++){
            sum += gas[i];
            sum -= cost[i];
            if(sum < 0){
                sum = 0;
                idx = i+1;
            }
        }
        return idx;
    }
};