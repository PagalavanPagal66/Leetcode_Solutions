class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int n=graph.size();
        queue<pair<int,pair<int,int>>>qt;
        set<pair<int,int>>st;
        int all=(1<<n)-1;
        for(int i=0;i<n;i++){
            int mask=(1<<i);
            qt.push({0,{i,mask}});
            st.insert({i,mask});
        }
        while(!qt.empty()){
            auto it=qt.front();qt.pop();
            int cost=it.first;
            int src=it.second.first;
            int mask=it.second.second;
            if(mask==all)return cost;
            for(auto &it:graph[src]){
                int newMask=mask | (1<<it);
                if(st.find({it,newMask})== st.end()){
                    st.insert({it,newMask});
                    qt.push({cost+1,{it,newMask}});
                }
            }
        }
        return -1;
    }
};