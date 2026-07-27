class SGTree{
    vector<int>seg;
public:
    SGTree(int n){
        seg.resize(4 * n +1);
    }
    
    void build(int idx, int low, int high, vector<int>& nums){
        if(low == high){
            seg[idx] = nums[low];
            return;
        }
        int mid = (low + high)/2;
        build(2 * idx+1, low, mid, nums);
        build(2 * idx+2, mid+1, high, nums);
        seg[idx] = seg[2*idx+1] + seg[2*idx+2];
    }
    int query(int idx, int low, int high, int l, int r){
        if(l > high || r < low){
            return 0;
        }
        if(l <= low && r >= high ){
            return seg[idx];
        }
        int mid = (low+high)/2;
        int left = query(2*idx+1, low, mid, l, r);
        int right = query(2*idx+2, mid+1, high, l, r);
        return left + right;
    }
};
class NumArray {
    SGTree s;
    int n;
public:
    NumArray(vector<int>& nums) : s(nums.size()) {
        n = nums.size();
        s.build(0, 0, n-1, nums);
    }
    int sumRange(int left, int right) {
        return s.query(0, 0, n-1, left, right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */