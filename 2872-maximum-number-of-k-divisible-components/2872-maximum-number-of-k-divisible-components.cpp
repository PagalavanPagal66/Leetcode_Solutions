class Solution {
public:
    #define ll long long
    void dfs(int node,vector<int>& vis,vector<ll>& subtree,vector<int> graph[],vector<ll>& nums)
    {
        vis[node]=1;
        subtree[node] = nums[node];
        for(auto child:graph[node]){
            if(vis[child]){
                continue;
            }
            dfs(child,vis,subtree,graph,nums);
            subtree[node]+=subtree[child];
        }
    }
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        vector<int>graph[n];
        vector<ll>subtree(n);
        vector<int>vis(n);    
        for(auto i:edges){
            graph[i[1]].push_back(i[0]);
            graph[i[0]].push_back(i[1]);
        }
        vector<ll>nums;
        for(auto i:values){
            nums.push_back(1LL*i);
        }
        dfs(0,vis,subtree,graph,nums);
        int ans = 0;
        ll total = 0;
        for(auto i:nums){
            total+=i;
        }
        int cnt=0;
        for(auto i:subtree){
            if(i%k==0){
                cnt++;
            }
        }
        return cnt;
    }
};