class Solution {
public:
    const int mod=1e9+7;
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<pair<int,int>>adj[n];
        for(auto i:roads){
            adj[i[0]].push_back({i[1],i[2]});
            adj[i[1]].push_back({i[0],i[2]});
        }
        vector<long long>dist(n,LLONG_MAX);
        vector<long long>ways(n,0);
        ways[0]=1;
        dist[0]=0;
        priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>>pq;
        pq.push({0,0});
        while(!pq.empty()){
            auto node= pq.top().second;
            auto nodedist = pq.top().first;
            pq.pop();
            for(auto child:adj[node]){
                auto childnode= child.first;
                auto childdist = child.second;
                if(childdist+nodedist<dist[childnode]){
                    dist[childnode] = childdist+nodedist;
                    ways[childnode]=ways[node];
                    pq.push({dist[childnode],childnode});
                }
                else if(childdist+nodedist==dist[childnode]){
                    ways[childnode] = (ways[node] + ways[childnode])%mod;
                }
            }
        }
        return ways[n-1]%mod;
    }
};