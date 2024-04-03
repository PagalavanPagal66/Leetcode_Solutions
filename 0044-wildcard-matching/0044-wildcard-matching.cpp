class Solution {
public:
    bool solve(string& s,string& p,int i,int j,vector<vector<int>>& dp){
        int n=s.size();
        int m=p.size();
        if(i==n && j==m){
            return true;
        }
        if(i==n){
            bool flag=false;
            for(int k=j;k<m;k++){
                if(p[k]!='*'){
                    return false;
                }
            }
            return true;
        }
        if(j==m){
            return false;
        }
        if(dp[i][j]!= -1){
            return dp[i][j];
        }
        char temp = p[j];
        if(temp=='?'){
            return dp[i][j] = solve(s,p,i+1,j+1,dp);
        }
        if(temp=='*'){
            bool flag = false;
            for(int k=i;k<=n;k++){
                flag |= solve(s,p,k,j+1,dp);
            }
            return dp[i][j] = flag;
        }
        if(s[i] == p[j]){
            return dp[i][j] = solve(s,p,i+1,j+1,dp);
        }
        return dp[i][j] = false;
    }
    bool isMatch(string s, string p) {
        int n=s.size();
        int m=p.size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return solve(s,p,0,0,dp);
    }
};