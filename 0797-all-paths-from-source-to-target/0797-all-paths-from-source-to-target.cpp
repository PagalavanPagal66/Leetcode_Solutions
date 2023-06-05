class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> path;
        vector<vector<int>> result;
        path.push_back(0);
        getPath(0,n,graph,path,result);
        return result;
    }

    void getPath(int v, int n, vector<vector<int>>& graph, vector<int>& path, vector<vector<int>>& result){
        if(v == n-1){
            result.push_back(path);
            return;
        }
        for(auto node: graph[v]){
            path.push_back(node);
            getPath(node, n, graph, path, result);
            path.pop_back();
        }
        
    }
};