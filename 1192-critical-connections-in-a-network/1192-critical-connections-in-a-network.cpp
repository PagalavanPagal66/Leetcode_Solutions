class Solution {
public:
    int timer=1;
    void dfs(int node,int parent,vector<int>adj[],int tin[],int low[],vector<int>& vis,vector<vector<int>>& bdg){
        vis[node]=1;
        tin[node]=low[node]=timer;
        timer++;
        for(auto it:adj[node]){
            if(it==parent){
                continue;
            }
            if(vis[it]!=1){
                dfs(it,node,adj,tin,low,vis,bdg);
                low[node]=min(low[node],low[it]);
                if(low[it]>tin[node]){
                    bdg.push_back({it,node});
                }
            }
            else{
                low[node]=min(low[node],low[it]);
            }
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>>res;
        vector<int>adj[n];
        for(auto& i:connections){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        vector<int>visited(n,0);
        int tin[n];
        int low[n];
        dfs(0,-1,adj,tin,low,visited,res);
        return res;
    }
};