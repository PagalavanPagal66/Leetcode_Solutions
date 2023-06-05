class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& vec) {
        int n=vec.size();
        vector<vector<int>>graph(n);
        for(int i=0;i<n;i++){
            for(auto j:vec[i]){
                graph[j].push_back(i);
            }
        }
        vector<int>topo;
        queue<int>q;
        vector<int>outdegree(n);
        for(int i=0;i<n;i++){
            for(auto j:graph[i]){
                outdegree[j]++;
            }
            
        }

        for(int i=0;i<n;i++){
            if(outdegree[i]==0){
                q.push(i);
            }
        }

        while(!q.empty()){
            int node= q.front();
            q.pop();
            topo.push_back(node);
            for(auto i:graph[node]){
                outdegree[i]--;
                if(outdegree[i]==0){
                    q.push(i);
                }
            }
        }
        sort(topo.begin() , topo.end());
        return topo;

    }
};