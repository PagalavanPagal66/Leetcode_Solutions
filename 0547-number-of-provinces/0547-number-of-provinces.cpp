class Solution {
public:
    void dfs(int i,vector<int>&vis,vector<int> adj[]){
        vis[i]=1;
        for(auto j:adj[i]){
            if(vis[j]!=1){
                dfs(j,vis,adj);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& nc) {
        int n=nc.size();
        vector<int>adj[n];
        vector<int>vis(n,0);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(nc[i][j] && i!=j){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        int ans=0;
        for(int i=0;i<n;i++){
            if(vis[i]==0){
                ans++;
                dfs(i,vis,adj);
            }
        }
        return ans;
    }
};