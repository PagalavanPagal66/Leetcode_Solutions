class Solution {
public:
    
    int mod= 1e9+7;
    
    int recur(int n, int i, int minProfit, vector<int>& group, vector<int>& profit, vector<vector<vector<int>>>& dp)
    {    
        if(i== group.size()) 
        {
            if(minProfit<=0)
                return 1;
            return 0;
        }
        
        if(minProfit<=0 && dp[n][i][0] !=-1) return dp[n][i][0]; 
        else if(minProfit>0 && dp[n][i][minProfit] !=-1) return dp[n][i][minProfit];
        
        long long ways=0;
        
        ways+= recur(n,i+1,minProfit, group, profit,dp); 
        ways%= mod;
        
        if(n>= group[i])
        {
            ways+= recur(n-group[i], i+1, minProfit- profit[i], group, profit,dp);
            ways%= mod;
        }
        
        if(minProfit<=0)
            return dp[n][i][0]= ways% mod; 
        
        return dp[n][i][minProfit] = ways% mod;
    }
    
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        
        int m= group.size();
        
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(m, vector<int>(101,-1)));
        
        return recur(n,0, minProfit, group, profit,dp);
        
    }
};