class SGTree{
    vector<int>seg;
public:
    SGTree(int n){
        seg.resize(n*4+1);
    }
    void build(int idx, int low, int high, vector<int>&arr){
        if(low == high){
            seg[idx] = low;
            return;
        }
        int mid = low + (high - low)/2;
        build(2*idx+1, low, mid, arr);
        build(2*idx+2, mid+1, high, arr);
        int leftIdx = seg[2*idx+1];
        int rightIdx = seg[2*idx+2];
        if(arr[leftIdx] > arr[rightIdx]){
            seg[idx] = leftIdx;
        }
        else{
            seg[idx] = rightIdx;
        }
    }
    int query(int idx, int low, int high, int l, int r, vector<int>&arr){
        if(r < low || l > high){
            return -1;
        }
        if(l <= low && r >= high){
            return seg[idx];
        }
        int mid = low + (high-low)/2;
        int left = query(2*idx+1, low, mid, l, r, arr);
        int right = query(2*idx+2, mid+1, high, l, r, arr);
        if(left == -1){
            return right;
        }
        if(right == -1){
            return left;
        }
        if(arr[left] > arr[right]){
            return left;
        }
        else{
            return right;
        }
    }
};
class Solution {
public:
    vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {
        int n = heights.size();
        SGTree sg(n);
        sg.build(0, 0, n-1, heights);
        vector<int>ans;
        for(int i=0; i<queries.size(); i++){
            int a = queries[i][0];
            int b = queries[i][1];
            int maxIdx = max(a, b);
            int minidx = min(a, b);
            if(a == b){
                ans.push_back(a);
            }
            else if(heights[maxIdx] > heights[minidx]){
                ans.push_back(maxIdx);
            }
            else{
                int ansIdx = -1;
                int l = maxIdx+1;
                int h = n-1;
                while(l <= h){
                    int mid = l + (h-l)/2;
                    int idx = sg.query(0, 0, n-1, l, mid, heights);
                    if(heights[idx] > max(heights[a], heights[b])){
                        ansIdx = idx;
                        h = mid-1;
                    }
                    else{
                        l = mid+1;
                    }
                }
                ans.push_back(ansIdx);
            }
        }
        return ans;
    }
};