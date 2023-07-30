class Solution {
public:
    vector<vector<int>> dp;
    string s;
    int solve(int l, int r) {
        if (l==r) return 1;
        if (dp[l][r] != -1) return dp[l][r];
        dp[l][r] = 1e9;
        for (int i = l; i < r; i++) {
            dp[l][r] = min(dp[l][r], solve(l,i)+solve(i+1,r)-(int)(s[l]==s[r]));
        }
        return dp[l][r];
    }
    int strangePrinter(string _s) {
        s = _s;
        int n = s.size();
        dp = vector<vector<int>>(n, vector<int>(n,-1));
        return solve(0,n-1); 
    }
};