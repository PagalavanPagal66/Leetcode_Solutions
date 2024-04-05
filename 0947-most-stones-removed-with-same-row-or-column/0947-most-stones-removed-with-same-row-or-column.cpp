class Disjoint{
    public:
    vector<int>parents,size;
    Disjoint(int n){
        parents.resize(n,0);
        size.resize(n,0);
        for(int i=0;i<n;i++){
            parents[i] = i;
        }
    }
    int find_parent(int u){
        if(u==parents[u]){
            return u;
        }
        return parents[u] = find_parent(parents[u]);
    }
    void add(int u,int v){
        int x = find_parent(u);
        int y = find_parent(v);
        if(size[x]<=size[y]){
            size[y]+=size[x];
            parents[x] = y;
        }
        else{
            size[x]+=size[y];
            parents[y] = x;
        }
    }
    vector<int> compcount(){
        int cnt=0,ind=0;
        vector<int>ret;
        for(auto i:parents){
            if(i==ind){
                ret.push_back(size[i]);
                cnt++;
            }
            ind++;
        }
        return ret;
    }
};
class Solution {
    
public:
    int removeStones(vector<vector<int>>& stones) {
        int maxi = 0;
        for(auto i:stones){
            for(auto j:i){
                maxi = max(maxi,j);
            }
        }
        int n=stones.size();
        Disjoint dsu(n);
        for(int i=0;i<stones.size();i++){
            for(int j=i+1;j<stones.size();j++){
                if(stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1])
                    dsu.add(i,j);
            }
        }
        vector<int>vals = dsu.compcount();
        return stones.size()-vals.size();
    }
};