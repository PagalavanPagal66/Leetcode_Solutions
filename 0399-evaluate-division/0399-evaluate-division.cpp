class Solution {
public:

    double dfs(string& start, string& end, double dist, map<string, vector<pair<string, double>>>& adj, map<string, bool> vis){
        if(start == end) return dist;
        vis[start] = true;
        double maxi = -1;
        for(auto &i: adj[start]){
            if(vis[i.first]) continue;
            vis[i.first] = true;
            maxi = max(maxi, dfs(i.first, end, dist * i.second, adj, vis));
        }
        return maxi;
    }

    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        map<string, vector<pair<string, double>>> adj;
        map<string, bool> vis;
        int x = 0;
        for(auto &i: equations){
            adj[i[0]].push_back({i[1], values[x]});
            vis[i[0]] = false;
            adj[i[1]].push_back({i[0], 1 / values[x++]});
            vis[i[1]] = false;
        }

        vector<double> ans;
        for(auto &i: queries){
            if(!adj.count(i[0]) || !adj.count(i[1])){
                ans.push_back(-1);
                continue;
            }

            string start = i[0], end = i[1];
            ans.push_back(dfs(start, end, 1, adj, vis));
        }

        return ans;
    }
};