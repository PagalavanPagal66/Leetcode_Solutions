class DSU{
    public:
    vector<int>parent,size;
    DSU(int n){
        parent.resize(n);
        size.resize(n);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
    }
    int find_par(int node){
        if(parent[node] == node){
            return node;
        }
        return parent[node] = find_par(parent[node]);
    }
    void add(int u,int v){
        int x = find_par(u);
        int y = find_par(v);
        if(x==y){
            return;
        }
        if(size[x]>=size[y]){
            size[x]+=size[y];
            parent[y] = parent[x];
        }
        else{
            size[y]+=size[x];
            parent[x] = parent[y];
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
    bool isvalid(int n,int i,int j){
        if(i<0 || j<0 || i>=n || j>=n){
            return false;
        }
        return true;
    }

    int largestIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<int>xdir = {0,0,-1,1};
        vector<int>ydir = {-1,1,0,0};
        DSU dsu(n*n);
        vector<vector<int>>vis(n,vector<int>(n,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    dsu.size[i*n+j]=1;
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    int index = i*n + j;
                    
                    vis[i][j] = 1;
                    for(int ind=0;ind<4;ind++){
                        int newx = i+xdir[ind];
                        int newy = j+ydir[ind];
                        int newindex = newx*n + newy;
                        if(isvalid(n,newx,newy)){
                            if(grid[newx][newy]==1){
                                                             dsu.add(newindex,index);
                                 }
                        }
                    }
                }
            }
        }
        int ans=0;
        for(int i=0;i<n*n;i++){
            ans = max(ans,dsu.size[i]);
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0){
                    int index = i*n + j;
                    int surr = 0;
                    set<int>st;
                    for(int ind=0;ind<4;ind++){
                        int newx = i+xdir[ind];
                        int newy = j+ydir[ind];
                        int newindex = newx*n + newy;
                        if(isvalid(n,newx,newy)){
                            st.insert(dsu.find_par(newindex));
                        }
                    }
                    for(auto i:st){
                        surr+=(dsu.size[i]);
                    }
                    ans=max(ans,surr+1);
                }
            }
        }
        return ans;
    }
};