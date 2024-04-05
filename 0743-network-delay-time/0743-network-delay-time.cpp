class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<pair<int,int>>adj[n];
        for(auto i:times){
            adj[i[0]-1].push_back({i[1]-1,i[2]});            
        }
        vector<int>dist(n,1e8);
        dist[k-1] = 0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,k-1});
        while(!pq.empty()){
            int node = pq.top().second;
            int currdist = pq.top().first;
            pq.pop();
            for(auto child:adj[node]){
                int childnode=child.first;
                int childdist=child.second;
                if(childdist+currdist<dist[childnode]){
                    dist[childnode]=childdist+currdist;
                    pq.push({dist[childnode],childnode});
                }
            }
        }
        int ans = 0;
        for(auto i:dist){
            if(i==1e8){
                return -1;
            }
            ans=max(ans,i);
        }
        return ans;
    }
};