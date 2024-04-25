class Solution {
public:
    int dp[100000][27];
    int go(string &s,int k,int ch,int i)
    {
    if(i>=s.size())
        return 0;
    int take=0,skip=0;
    if(dp[i][ch]!=-1)
        return dp[i][ch];
    if(ch==26 ||abs((s[i]-'a')-ch)<=k )
    {
        take=1+go(s,k,s[i]-'a',i+1);
    }
    skip=go(s,k,ch,i+1);
    return dp[i][ch]=max(take,skip);
    }
    int longestIdealString(string s, int k) {
        memset(dp,-1,sizeof(dp));
        return go(s,k,26,0);
    }
};