class Solution {
public:
    int solve(vector<vector<int>>& dp, vector<vector<int>>& triangle,int i, int j, int n,int sum){
        if(i==n-1){
            return triangle[i][j];
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int b=min(INT_MAX,solve(dp,triangle,i+1,j,n,sum));
        int c=min(INT_MAX,solve(dp,triangle,i+1,j+1,n,sum));
        return dp[i][j]=min({b,c})+triangle[i][j];
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return solve(dp,triangle,0,0,n,0);
    }
};