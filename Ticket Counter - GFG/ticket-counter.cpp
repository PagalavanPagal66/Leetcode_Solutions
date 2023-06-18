//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
   public:
    int distributeTicket(int N, int K) {
        int i=1,j=N;
        bool f=true;
        int ans=1;
        while(i<j)
        {
            if(f)
            {
                for(int a=0;a<K && i<j;a++)
                {
                    i++;
                    ans=i;
                }
                f=false;
            }
            else
            {
                for(int a=0;a<K && i<j;a++)
                {
                    j--;
                    ans=j;
                }
                f=true;
            }
          
        }
        return ans;
    
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int N;
        scanf("%d",&N);
        
        
        int K;
        scanf("%d",&K);
        
        Solution obj;
        int res = obj.distributeTicket(N, K);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends