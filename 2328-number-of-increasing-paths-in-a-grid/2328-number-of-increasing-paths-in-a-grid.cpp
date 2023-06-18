class Solution {
public:
 vector<vector<int>>dp;
    int dfs(int r,int c,vector<vector<int>>&matrix,int m,int n,int pre ){
    
    if(r>=m || c>=n || c<0 ||  r<0 || matrix[r][c] <=pre ) return 0;
        
    if(dp[r][c]!=-1) return dp[r][c];
       int top =   dfs(r-1,c,matrix,m,n,matrix[r][c]);
       int down =   dfs(r+1,c,matrix,m,n,matrix[r][c]);
       int left =   dfs(r,c-1,matrix,m,n,matrix[r][c]);
       int right =   dfs(r,c+1,matrix,m,n,matrix[r][c]);

    int ans =  (top+down+left+right+1)%1000000007;
    return dp[r][c] = ans;
    }
    int countPaths(vector<vector<int>>& matrix) {
        int m = matrix.size(),n = matrix[0].size();
        if(m==0) return m;
        int res = 0;
        dp.resize(m,vector<int>(n,-1));
  
        for(int i=0;i<m;i++){
            for(int z=0;z<n;z++){
                    if(dp[i][z]==-1){
                    int ans = dfs(i,z,matrix,m,n,-1);
                    res= (res + ans)%1000000007;
                    }else
                    res= (res + dp[i][z])%1000000007;
            }
        }

        return res;
    }
};