class Solution {
public:
   
   bool BFS(int curr_node,int curr_color,unordered_map<int,vector<int>> &adj,vector<int> &color){
      queue<int> qu;
      qu.push(curr_node);
      color[curr_node]=curr_color;
    
      while(!qu.empty()){
         int size = qu.size();
         while(size--){
             int u = qu.front();
             qu.pop();
             for(auto &v : adj[u]){
                 if(color[v]==color[u]){
                     return false;
                 }
                 else if(color[v]==-1){
                     color[v]=1-color[u];
                     qu.push(v);
                 }
             }
         }
      }
      return true;
   }



    bool isBipartite(vector<vector<int>>& graph) {
        int V=graph.size();
        unordered_map<int,vector<int>> adj;
        for(int i=0;i<graph.size();i++){
            for(int j=0;j<graph[i].size();j++){
                int v = graph[i][j];

                adj[i].push_back(v);
            }
        }


        vector<int> color(V,-1);  
        for(int i=0;i<V;i++){
            if(color[i]==-1){
                if(BFS(i,0,adj,color)==false){
                    return false;
                }
            }
        }
       return true;
    }
};