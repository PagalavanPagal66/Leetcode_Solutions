class Solution {
public:
    int dfs(int i,int j,vector<vector<int>>& dp,string& text1,string& text2){
        if(i>=text1.length() || j>=text2.length() || i<0 || j<0 ){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        if(text1[i]==text2[j]){
            return dp[i][j]=1+dfs(i+1,j+1,dp,text1,text2);
        }
        return dp[i][j]=max(dfs(i,j+1,dp,text1,text2),dfs(i+1,j,dp,text1,text2));
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n=text1.size();
        int m=text2.size();
        vector<vector<int>>vec(n+1,vector<int>(m+1,-1));
        return dfs(0,0,vec,text1,text2);
    }
};