class Solution {
public:
vector<int> TreeNode[200001];
int size[200001];
int  sum[200001];
    void dfs1(int src,int par){
        
        for(int child:TreeNode[src]){
            if(child!=par){
                dfs1(child,src);
                size[src]+=size[child];
                sum[src]+=size[child]+sum[child];
            }
        }
        size[src]++;
    }
    void reroot(int srca,int srcb){
        size[srca]-=size[srcb];
        sum[srca]-=sum[srcb]+size[srcb];
        size[srcb]+=size[srca];
        sum[srcb]+=sum[srca]+size[srca];
    }
    void dfs2(int src,int par,vector<int>&ans){
        ans[src] = sum[src];
        for(int child:TreeNode[src]){
            if(child!=par){
                reroot(src,child);
                dfs2(child,src,ans);
                reroot(child,src);
            }
        }
    }
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        for(auto i:edges){
            TreeNode[i[0]].push_back(i[1]);
            TreeNode[i[1]].push_back(i[0]);
        }
        dfs1(0,-1);
        vector<int>ans(n,0);
        dfs2(0,-1,ans);
        return ans;
    }
};