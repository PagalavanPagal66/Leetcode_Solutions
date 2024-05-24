class Solution {
public:
    int maxStarSum(vector<int>& vals, vector<vector<int>>& edges, int k) {
        int ans=INT_MIN;
        vector<vector<int>> g(vals.size());
        for(auto& e:edges){
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }
        for(int i=0;i<vals.size();i++){
            int cost=vals[i];
            priority_queue<int,vector<int>,less<int>> pq;
            for(int node:g[i]){
                if(vals[node]>0){
                    pq.push(vals[node]);
                }
            }
            int idx=0;
            while(!pq.empty() && idx<k){
                cost+=pq.top();
                pq.pop();
                idx++;
            }
            ans=max(ans,cost);
        }
        return ans;
    }
};