//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int dp[51];
    bool ispow(long long n){
        if(n==0) return false;
        if(n==1) return true;
        while(n>1){
            if(n%5!=0) return false;
            n /= 5;
        }
        return true;
    }
    int cuts(string s){
        //code
        memset(dp,-1,sizeof(dp));
        return helper(s,s.size()-1);
    }
    int helper(string &s,int n){
        if(n==-1) return 0;
        if(dp[n]!=-1) return dp[n];
        long long num = 0,t=1;
        int ans = INT_MAX;
        for(int i=n;i>=0;i--){
            if(s[i]=='1') num+=t;
            t*=2;
            if(s[i]=='1' && ispow(num)){
                int ne = helper(s,i-1);
                if(ne!=-1){
                    // cout<<num<<endl;
                    ans = min(ans,1+ne);
                }
            }
        }
        if(ans==INT_MAX){
            return -1;
        }
        return dp[n] = ans;
    }
};

//{ Driver Code Starts.
int main()
{
   int t;
   cin>>t;
   string s;
   while(t--)
   {
    cin>>s;
    Solution obj;
    int res=obj.cuts(s);
    cout<<res<<endl;

   }


    return 0;
}

// } Driver Code Ends