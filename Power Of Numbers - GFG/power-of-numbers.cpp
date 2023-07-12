//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
    public:
       int mod=1e9+7;
    long long f(int n,int r)
    {
        if(r==0)
        {
            return 1;
        }

        long long ans=f(n,(long long)(r)/2);
        
        if(r&1)
        {
           return ((ans%mod*ans%mod)*n)%mod;
        }
        else
        {
          return ((ans)%mod*(ans)%mod)%mod; 
        }
    }
    
    
    long long power(int n,int r)
    {
       //Your code here
       
       return f(n,r);
        
    }

};

//{ Driver Code Starts.

// compute reverse of a number 
long long rev(long long n)
{
    long long rev_num = 0;
     while(n > 0) 
      { 
        rev_num = rev_num*10 + n%10; 
        n = n/10; 
      } 
      return rev_num;
}




int main()
{
    int T;
    cin>>T;//testcases
    
    while(T--)
    {
        long long N;
        cin>>N;//input N
        
        long long R = 0; 
        
        // reverse the given number n
        R = rev(N);
        Solution ob;
        //power of the number to it's reverse
        long long ans =ob.power(N,R);
        cout << ans<<endl;
    }
}
// } Driver Code Ends