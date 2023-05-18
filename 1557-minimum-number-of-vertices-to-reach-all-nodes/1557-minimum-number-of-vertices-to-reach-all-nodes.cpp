class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        int vis[100005] = {0};
        for(auto x: edges) vis[x[1]]++;
        vector<int> ans;
        for(int i=0; i<n; i++) if(!vis[i]) ans.push_back(i);
        return ans;
    }
};