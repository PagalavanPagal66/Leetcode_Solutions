class Solution {
public:
    void dfs(int node,vector<int>& vis,vector<int>& subtree,vector<int> graph[],vector<int>& nums)
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
    int componentValue(vector<int>& nums, vector<vector<int>>& edges) {
        int n=nums.size();
        vector<int>graph[n];
        vector<int>subtree(n);
        vector<int>vis(n);    
        for(auto i:edges){
            graph[i[1]].push_back(i[0]);
            graph[i[0]].push_back(i[1]);
        }
        dfs(0,vis,subtree,graph,nums);
        int ans = 0;
        int total = 0;
        for(auto i:nums){
            total+=i;
        }
        for(int factor=1;factor*factor <= total;factor++){
            if(total%factor == 0){
                int first_factor = factor;
                int second_factor = total/factor;
                int cnt=0;
                for(auto i:subtree){
                    if(i%first_factor == 0){
                        cnt++;
                    }
                }
                if(cnt == second_factor){
                    ans = max(ans,second_factor-1);
                }
                cnt=0;
                if(first_factor != second_factor){
                    for(auto i:subtree){
                        if(i%second_factor == 0){
                            cnt++;
                        }
                    }
                    if(cnt == first_factor){
                        ans = max(ans,first_factor-1);
                    }
                }
            }
        }
        return ans;
    }
};