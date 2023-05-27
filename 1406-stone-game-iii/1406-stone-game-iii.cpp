class Solution {
public:
    int dp[50001];
    int dfs(vector<int>&sv,int i){
        if(i>sv.size()){
            return 0;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        int maxi=INT_MIN;
        maxi=max(maxi,sv[i]-dfs(sv,i+1));
        if(i+1<sv.size()){
            maxi=max(maxi,sv[i]+sv[i+1]-dfs(sv,i+2));
        }
        if(i+2<sv.size()){
            maxi=max(maxi,sv[i]+sv[i+1]+sv[i+2]-dfs(sv,i+3));
        }
        return dp[i]=maxi;
    }
    string stoneGameIII(vector<int>& stoneValue) {
        int n=stoneValue.size();
        for(int i=0;i<n;i++)dp[i]=-1;
        int ans=dfs(stoneValue,0);
        if(ans>0){
            return "Alice";
        }
        if(ans<0){
            return "Bob";
        }
        return "Tie";
    }
};