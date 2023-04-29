class Solution {
    int n,m;
public:
    bool isSimilar(string a,string b)
    {
        int cnt=0;
        for(int i=0;i<m && cnt<=2;i++)
        {
            if(a[i]!=b[i])cnt++;
        }
    
        return cnt==2 || cnt==0;
    }

    void dfs(int i,vector<string>& strs,vector<bool>& vis)
    {
        vis[i]=true;
    
        for(int j=0;j<n;j++)
        if(!vis[j])
        {
            if(isSimilar(strs[i],strs[j]))dfs(j,strs,vis);
        }
    }

    int numSimilarGroups(vector<string>& strs)
    {
        n = strs.size(),m=strs[0].size();
    
        int ans=0;
    
        vector<bool> vis(n);
    
        for(int i=0;i<n;i++)
        if(!vis[i])
        {
            ans++;
            dfs(i,strs,vis);
        }
        return ans;
    }
};