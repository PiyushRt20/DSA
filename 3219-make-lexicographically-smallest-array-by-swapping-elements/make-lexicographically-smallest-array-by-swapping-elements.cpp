class DSU{
    vector<int> parent,size;

public:
    DSU(int n){
        parent.resize(n);
        size.resize(n,1);

        for(int i = 0;i<n;i++){
            parent[i] = i;
        }
    }

    int find_UP(int node){
        if(node == parent[node]){
            return node;
        }
        return parent[node] = find_UP(parent[node]);
    }

    void unionBySize(int u,int v){
        int UP_U = find_UP(u);
        int UP_V = find_UP(v);

        if(UP_U == UP_V){
            return;
        }

        if(size[UP_U] > size[UP_V]){
            parent[UP_V] = UP_U;
            size[UP_U] += size[UP_V];
        }
        else{
            parent[UP_U] = UP_V;
            size[UP_V] += size[UP_U];
        }
    }
};

class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();

        vector<pair<int,int>> v;
        
        for(int i = 0;i<n;i++){
            v.push_back({nums[i],i});
        }

        sort(v.begin(),v.end());

        DSU dsu(n);

        for(int i = 0;i<n-1;i++){
            if(v[i+1].first-v[i].first <= limit){
                dsu.unionBySize(v[i].second,v[i+1].second);
            }
        }

        unordered_map<int,vector<int>> mpp;

        for(int i = 0;i<n;i++){
            mpp[dsu.find_UP(i)].push_back(nums[i]);
        }

        for(auto &it : mpp){
            sort(it.second.begin(),it.second.end());
        }

        unordered_map<int,int> idx;

        for(int i = 0;i<n;i++){
            int root = dsu.find_UP(i);
            nums[i] = mpp[root][idx[root]];
            idx[root]++;
        }

        return nums;
    }
};