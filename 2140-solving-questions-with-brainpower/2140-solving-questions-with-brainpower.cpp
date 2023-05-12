class Solution {
public:
    long long solve(int in,vector<vector<int>> &q,vector<long long> &dp)
    {
        if(in>=q.size()){
            return 0;
        }
        if(dp[in]!=-1){
            return dp[in];
        }
        return dp[in]=max(q[in][0]+solve(in+q[in][1]+1,q,dp),solve(in+1,q,dp));
    }
    long long mostPoints(vector<vector<int>>& questions) {
        int n=questions.size();
        vector<long long> dp(n,-1);
        return solve(0,questions,dp);
    }
};