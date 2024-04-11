class DSU{
    public:
    vector<int>parent,size,value;
    DSU(int n){
        parent.resize(n);
        size.resize(n);
        value.resize(n);
        for(int i=0;i<n;i++){
            parent[i]=i;
            value[i] = INT_MAX;
        }
    }
    int find_par(int node){
        if(parent[node] == node){
            return node;
        }
        value[node] = value[parent[node]];
        return parent[node] = find_par(parent[node]);
    }
    void add(int u,int v,int wt){
        int x = find_par(u);
        int y = find_par(v);
        if(size[x]>=size[y]){
            size[x]+=size[y];
            parent[y] = x;
            value[x] &= value[y] & wt;
        }
        else{
            size[y]+=size[x];
            parent[x] = y;
            value[y] &= value[x] & wt;
        }
    }
    int compsize(){
        int cnt=0;
        for(int i=0;i<parent.size();i++){
            if(parent[i]==i){
                cnt++;
            }
        }
        return cnt;
    }
};

class Solution {
public:
    struct Node {
        int val = INT_MAX;
    };
    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
        DSU dsu(n+1);
        for(auto i:edges){
            int strt = i[0];
            int end = i[1];
            int wt = i[2];
            dsu.add(strt,end,wt);
        }
        vector<int>ans;
        for(auto i:query){
            int strt = i[0];
            int end = i[1];
            if(strt==end){
                ans.push_back(0);
                continue;
            }
            if(dsu.find_par(strt) == dsu.find_par(end)){
                ans.push_back(dsu.value[dsu.find_par(strt)]);
            }
            else{
                ans.push_back(-1);
            }
        }
        return ans;
    }
};