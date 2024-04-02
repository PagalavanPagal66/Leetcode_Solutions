class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,0);
        if(n==1){
            return nums[0];
        }
        if(n==2){
            return max(nums[0],nums[1]);
        }
        if(n==3){
            return max({nums[0],nums[2],nums[1]});
        }
        dp[0] = 0;
        dp[1] = nums[1];
        for(int i=2;i<=n-1;i++){
            dp[i] = max(dp[i-1],dp[i-2]+nums[i]);
        }
        int ans1 = dp[n-1];
        reverse(nums.begin(),nums.end());
        dp[0] = 0;
        dp[1] = nums[1];
        for(int i=2;i<=n-1;i++){
            dp[i] = max(dp[i-1],dp[i-2]+nums[i]);
        }
        int ans2 = dp[n-1];
        return max(ans1,ans2);
    }
};