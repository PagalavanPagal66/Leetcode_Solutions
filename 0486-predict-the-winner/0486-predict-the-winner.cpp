class Solution {
public:
    int dfs(vector<int>&nums, int left, int right,vector<vector<int>>& dp){
        if(left>right){
            return 0;
        }
        if(dp[left][right]!=-1){
            return dp[left][right];
        }
        int l = nums[left] - dfs(nums,left+1,right,dp);
        int r = nums[right] - dfs(nums,left,right-1,dp);
        return dp[left][right]=max(l,r);
    }
    bool PredictTheWinner(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        if(dfs(nums,0,n-1,dp)>=0){
            return true;
        }
        return false;
    }
};