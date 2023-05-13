class Solution {
private:
    const int mod = 1e9 + 7;
    int solve(int low, int high, int zero, int one, int cnt, vector<int>& dp) {
        if(cnt > high) return 0;

        if(dp[cnt] != -1) return dp[cnt];
        
        int ans = 0;
        if(cnt >= low && cnt <= high) ans = 1;
        int append_0 = solve(low, high, zero, one, cnt + zero, dp)%mod;
        int append_1 = solve(low, high, zero, one, cnt + one, dp)%mod;

        return dp[cnt] = (ans + append_0 + append_1)%mod;
    } 

public:
    int countGoodStrings(int low, int high, int zero, int one) {
        vector<int> dp(high+1, -1);
        return solve(low, high, zero, one, 0, dp);
    }
};