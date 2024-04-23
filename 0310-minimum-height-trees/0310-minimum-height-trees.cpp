class Solution {
public:
    int solve(int level,int par,int root,vector<int>& heights,vector<int>adj[]){
        int maxi = 0;
        for(auto child:adj[root]){
            if(child!=par)
                maxi = max(maxi,solve(level+1,root,child,heights,adj));
        }
        heights[root] = max(level,maxi);
        return maxi;
    }
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<int>heights(n);
        int root = 0;
        vector<int>adj[n];
        vector<int>indegree(n,0);
        for(auto i:edges){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
            indegree[i[0]]++;
            indegree[i[1]]++;
        }
        vector<int>ans;
        queue<int>q;
        for(int i=0;i<indegree.size();i++){
            if(indegree[i] == 1){
                q.push(i);
            }
        }
        while(!q.empty()){
            int s = q.size();
            ans.clear();
            while(s--){
                int ele = q.front();
                ans.push_back(ele);
                q.pop();
                for(auto child:adj[ele]){
                    indegree[child]--;
                    if(indegree[child] == 1){
                        q.push(child);
                    }
                }
            }
        }
        if(ans.size()==0){
            return {0};
        }
        return ans;
    }
};