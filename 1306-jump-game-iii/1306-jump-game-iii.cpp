class Solution {
public:
    bool dfs(int start,vector<bool>& dp,vector<bool>&isvis, vector<int>& arr){
        if(start<0 || start>=arr.size()){
            return false;
        }
        if(dp[start] || isvis[start]){
            return dp[start];
        }
        if(arr[start]==0){
            return dp[start]=true;
        }
        isvis[start]=true;
        return dfs(start+arr[start],dp,isvis,arr) || dfs(start-arr[start],dp,isvis,arr); 
    }
    bool canReach(vector<int>& arr, int start) {
        int n=arr.size();
        vector<bool>dp(n,false);
        vector<bool>isvis(n,false);
        return dfs(start,dp,isvis,arr);
    }
};