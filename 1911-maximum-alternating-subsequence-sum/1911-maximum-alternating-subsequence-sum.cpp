class Solution {
public:
    long long dp[100001][2];
    long long dfs(vector<int>& nums,int i,int flag){
        if(i>=nums.size()){
            return 0;
        }
        if(dp[i][flag]!= -1){
            return dp[i][flag];
        }
        long long ans=0;
        if(flag==0){
            ans=max(nums[i]+dfs(nums,i+1,1),dfs(nums,i+1,0));
        }
        else{
            ans=max(-nums[i]+dfs(nums,i+1,0),dfs(nums,i+1,1));
        }
        return dp[i][flag]=ans;
    }
    long long maxAlternatingSum(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        return dfs(nums,0,0);
    }
};