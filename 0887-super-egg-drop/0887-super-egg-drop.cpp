class Solution {
public:
int backtrack(vector<vector<int>>&dp,int k,int n){
        if(n==0 || n==1 || k==1){
            return n;
        }
        if(dp[n][k]!=-1){
            return dp[n][k];
        }
        int ans=INT_MAX;
        int l=1,h=n;
        while(l<=h)
        {
            int mid=(l+h)/2;
            int left=backtrack(dp,k-1,mid-1);   
            int right=backtrack(dp,k,n-mid);   
            int temp=1+max(left,right);          
            if(left<right){                  
              l=mid+1;                       
            }
            else                            
            {    
                h=mid-1;
            }
            ans=min(ans,temp);               
        }
        dp[n][k] = ans;
        return ans;
    }
    int superEggDrop(int k, int n) {
        vector<vector<int>>dp(n+1,vector<int>(k+1,-1));
        return backtrack(dp,k,n);
    }
};