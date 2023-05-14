class Solution {
public:
    int recur(vector<int> &nums, int mask, vector<vector<int>> &dp,int op,int n){
        if(mask == (1<<n) - 1)    return 0;
        if(dp[mask][op]!=-1)    return dp[mask][op];
        int res = 0;
        for(int i=0;i<n;i++){
            if(mask & (1<<i))   continue;
            for(int j=0;j<n;j++){
                if(i==j || (mask & (1<<j))) continue;
                mask = mask | (1<<j);
                mask = mask | (1<<i);
                res = max(res,op*__gcd(nums[i],nums[j]) + recur(nums,mask,dp,op+1,n));
                mask = (mask & ~(1<<j)) ;
                mask = (mask & ~(1<<i)) ;
            }   
        }
        return dp[mask][op] = res;
    }
    int maxScore(vector<int>& nums) {
        vector<vector<int>> dp ((1<<nums.size()),vector<int>(nums.size(),-1));
        return recur(nums,0,dp,1,nums.size());
    }
};