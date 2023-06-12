class Solution {
public:
    int isvalid(int i,int j,int n,int m){
        if(i<0 || j<0 || i>=n || j>=m){
            return 0;
        }
        return 1;
    }
    int minCost(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<int>r={0,0,1,-1};
        vector<int>c={1,-1,0,0};
        vector<vector<int>>dp(n,vector<int>(m,INT_MAX-1));
        queue<pair<int,int>>q;
        q.push({0,0});
        dp[0][0]=0;
        while(!q.empty()){
            int x=q.front().first;
            int y=q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int t=i+1;
                int cr=x+r[i];
                int cc=y+c[i];
                if(isvalid(cr,cc,n,m)){
                    if(t==grid[x][y] && dp[x][y]<dp[cr][cc]){
                        dp[cr][cc]=dp[x][y];
                        q.push({cr,cc});
                    }
                    else if(dp[x][y]+1<dp[cr][cc]){
                        dp[cr][cc]=dp[x][y]+1;
                        q.push({cr,cc});
                    }
                }
            }
        }
        return dp[n-1][m-1];
    }
};