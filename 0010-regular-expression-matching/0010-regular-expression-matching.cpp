class Solution {
public:
    bool solve(string& s,string& p,int i,int j,vector<vector<int>>& dp){
        int n=s.size();
        int m=p.size();
        if(i>=n && j>=m){
            return true;
        }
        if(j>=m){
            //cout<<"YES"<<endl;
            return false;
        }
        if(i>=n){
            for(int k=j+1;k<m;k+=2){
                if(p[k]=='*'){
                    continue;
                }
                return false;
            }
            if(p[m-1]!='*'){
                return false;
            }
            return true;
        }
        if(dp[i][j]!=-1){
            //cout<<i<<" "<<j<<endl;
            return dp[i][j];
        }
        char temp = p[j];
        if(j<m-1 && p[j+1]=='*'){
            return dp[i][j] = (solve(s,p,i,j+2,dp) || ((s[i]==p[j] || p[j]=='.') && solve(s,p,i+1,j,dp)));
        }
        if(temp == '.'){
            bool curr = solve(s,p,i+1,j+1,dp);
            return dp[i][j] = curr;
        }
        if(s[i]==p[j]){
            return dp[i][j] = solve(s,p,i+1,j+1,dp);
        }
        return dp[i][j] = false;
    }
    bool isMatch(string s, string p) {
        int n=s.size();
        int m=p.size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<m;j++){
        //         cout<<dp[i][j]<<" - ";
        //     }
        //     cout<<endl;
        // }
        if(solve(s,p,0,0,dp)){
            return true;
        }
        // for(int i=0;i<m;i++){
        //     if(p[i]=='*'){
        //         if(solve(s,p,0,i,dp)){
        //             return true;
        //         }
        //     }
        // }
        return false;
    }
};