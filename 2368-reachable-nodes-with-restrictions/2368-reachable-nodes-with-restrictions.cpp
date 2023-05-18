class Solution {
public:
    int isfound(int val,vector<int>&r){
        int n=r.size();
        int strt=0;
        int end=n-1;
        while(strt<=end){
            int mid=(strt+end)/2;
            if(r[mid]==val){
                return 1;
            }
            if(r[mid]>val){
                end=mid-1;
            }
            else{
                strt=mid+1;
            }
        }
        return 0;
    }
    void dfs(vector<int>&vis,int i,vector<int>adj[],vector<int>&res){
        if(isfound(i,res)){
            return;
        }
        vis[i]=1;
        for(auto j:adj[i]){
            if(vis[j]==0 && isfound(j,res)==0){
                vis[j]=1;
                dfs(vis,j,adj,res);
            }
        }
        return;
    }
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
        vector<int>adj[n];
        sort(restricted.begin(),restricted.end());
        for(auto i:edges){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        vector<int>visited(n,0);
        dfs(visited,0,adj,restricted);
        int cnt=0;
        for(auto i:visited){
            if(i!=0){
                cnt++;
            }
        }
        return cnt;
    }
};