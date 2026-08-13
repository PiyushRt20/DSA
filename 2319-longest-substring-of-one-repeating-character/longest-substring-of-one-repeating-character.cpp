struct Node{
    char leftChar;
    char rightChar;
    int pre;
    int suf;
    int maxVal;
};
class SGTree{
    vector<Node> seg;
    Node merge(Node L, Node R, int leftLen, int rightLen){
        Node root;
        root.leftChar = L.leftChar;
        root.rightChar = R.rightChar;
        root.pre = L.pre;
        if(L.pre == leftLen && L.rightChar == R.leftChar){
            root.pre = L.pre + R.pre;
        }
        root.suf = R.suf;
        if(R.suf == rightLen && R.leftChar == L.rightChar){
            root.suf = L.suf + R.suf;
        }
        root.maxVal = max(L.maxVal, R.maxVal);
        if(L.rightChar == R.leftChar){
            root.maxVal = max(root.maxVal, L.suf + R.pre);
        }
        return root;
    }
public:
    SGTree(int n){
        seg.resize(4*n+1);
    }
    void build(int idx, int low, int high, string& s){
        if(low == high){
            seg[idx] = {s[low], s[low], 1, 1, 1};
            return;
        }
        int mid = low + (high - low)/2;
        build(2*idx+1, low, mid, s);
        build(2*idx+2, mid+1, high, s);
        seg[idx] = merge(seg[2*idx+1], seg[2*idx+2], mid-low+1, high - (mid+1) + 1);
    }
    void update(int idx, int low, int high, int pos, char ch){
        if(low == high){
            seg[idx] = {ch, ch, 1, 1, 1};
            return;
        }
        int mid = low + (high-low)/2;
        if(pos <= mid){
            update(2*idx+1, low, mid, pos, ch);
        }
        else{
            update(2*idx+2, mid+1, high, pos, ch);
        }
        seg[idx] = merge(seg[2*idx+1], seg[2*idx+2], mid-low+1, high - (mid+1) + 1);
    }
    int query(int idx){
        return seg[idx].maxVal;
    }
};
class Solution {
public:
    vector<int> longestRepeating(string s, string queryCharacters, vector<int>& queryIndices) {
        int n = s.size();
        int m = queryCharacters.size();
        vector<int> ans;
        SGTree sg(n);
        sg.build(0, 0, n-1, s);
        for(int i =0; i<m; i++){
            int pos = queryIndices[i];
            char ch = queryCharacters[i];
            sg.update(0, 0, n-1, pos, ch);
            int maxLen = sg.query(0);
            ans.push_back(maxLen);
        }
        return ans;
    }
};