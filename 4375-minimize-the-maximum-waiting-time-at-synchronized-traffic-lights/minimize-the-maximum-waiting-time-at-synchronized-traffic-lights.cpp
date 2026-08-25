class Solution {
public:
    int minPenalty(int period, vector<int>& lights, vector<int>& arrivalTime) {
        int n = arrivalTime.size();
        for(int i =0; i<n; i++){
            arrivalTime[i] = arrivalTime[i] % period;
        }
        int maxi = 0;
        int maxLight = *max_element(lights.begin(), lights.end());
        for(int i =0; i<n; i++){
            if(maxLight <= arrivalTime[i]){
                maxi = max(maxi, period - arrivalTime[i]);
            }
        }
        return maxi;
    }
};