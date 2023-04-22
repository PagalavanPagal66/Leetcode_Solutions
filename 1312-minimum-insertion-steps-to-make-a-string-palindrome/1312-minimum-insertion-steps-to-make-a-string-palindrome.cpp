class Solution {
public:
    int minInsertions(string s) {
        vector<vector<int>> dp(s.size(),vector<int>(s.size(),0));
        string t=s;
        reverse(t.begin(),t.end());
        for(int i=0;i<s.size();i++)for(int j=0;j<t.size();j++)
            (s[i]==t[j])?(dp[i][j]= 1+((i-1>=0 && j-1>=0)?dp[i-1][j-1]:0)):( dp[i][j]=max(((i>0)?dp[i-1][j]:0),((j>0)?dp[i][j-1]:0)));
        return s.size()-dp[s.size()-1][t.size()-1];
    }
};