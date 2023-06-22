class Solution {
public:
    int func( int i , int cb , vector<int>&prices ,vector<vector<int>>&dp , int fee ){
        if( i == prices.size()) return  0 ;
        if( dp[i][cb] != -1 ) return dp[i][cb] ;
        int p = 0 ;
        if( cb){
            int a = prices[i]*-1 ;
            p = a + func( i+1 , 0 , prices ,dp ,fee ) ; 
            p = max( p , func(i+1,1,prices,dp,fee)) ;
        }
        else{
            p = prices[i] + func( i+1 , 1 , prices , dp ,fee ) - fee ;
            p = max( p , func(i+1,0,prices,dp,fee)) ;
        }
        dp[i][cb] = p ; 
        return dp[i][cb] ;

    }
    
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size() ;
        vector<vector<int>>dp(n,vector<int>(2,-1));
        int ans = func( 0 , 1 , prices , dp , fee ) ;
        return ans ;
    }
};