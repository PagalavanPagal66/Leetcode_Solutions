class Solution {
public:
    long long pos(vector<int>&nums,vector<int>&andvalues,int ind,int value,int covered,unordered_map<int,unordered_map<int,unordered_map<int,int>>>&dp){
        if(covered>=andvalues.size())return 1e6;
        if(ind>=nums.size()){
            if(value==andvalues[andvalues.size()-1] && covered+1==andvalues.size())return nums[ind-1];
            return 1e6;
        }
        if(dp.find(ind)!=dp.end() && dp[ind].find(covered)!=dp[ind].end() && dp[ind][covered].find(value)!=dp[ind][covered].end())return dp[ind][covered][value];
        long long select=1e6,unselect=1e6;
        if(value==andvalues[covered]){
            unselect=pos(nums,andvalues,ind+1,value&nums[ind],covered,dp);
            select=nums[ind-1]+pos(nums,andvalues,ind+1,nums[ind],covered+1,dp);
            return dp[ind][covered][value]=min(unselect,select);
        }
        unselect=pos(nums,andvalues,ind+1,value&nums[ind],covered,dp);
        return dp[ind][covered][value]=min(select,unselect);
    }
    int minimumValueSum(vector<int>& nums, vector<int>& andValues) {
        // vector<vector<vector<int>>>dp(nums.size()+1,vector<vector<int>>(andValues.size()+1,vector<int>(1e5,-1)));
        unordered_map<int,unordered_map<int,unordered_map<int,int>>>dp;
        long long res=pos(nums,andValues,1,nums[0],0,dp);
        return (res>=1e6)?-1:res;
    }
};