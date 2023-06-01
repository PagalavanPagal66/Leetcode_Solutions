//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution{
public:
      void dfs(int src, vector<vector<int>> &g,int &x,vector<int> &vis){
        x ++;
        vis[src] = true;
        for(auto v : g[src])
        if(!vis[v])
         dfs(v,g,x,vis);
    }
    vector<int> prime;
    void precompute(){
        vector<bool> isPrime(1e6+1,true);
        isPrime[0] = false;
        isPrime[1] = false;
        for(int i=2;i<=1e6+1;i++)
        if(isPrime[i]){
            prime.push_back(i);
            for(int j = 2*i;j<=1e6+1;j += i) isPrime[j] = false;
        }
    }
    int helpSanta(int n, int m, vector<vector<int>> &g){
        // Code here
        vector<int> vis(n+1);
        int x = 0;
        for(int i=1;i<=n;i++){
            int temp = 0;
            if(!vis[i]) dfs(i,g,temp,vis);
            x = max(temp,x);
        }
        if(x == 1) return -1;
        return prime[x-1];
    }
};

//{ Driver Code Starts.

int main(){
	int t;cin>>t;
	Solution ob;
	ob.precompute();
	while(t--){
        int n,e,u,v;
        cin>>n>>e;
        vector<vector<int>> g(n+10);
        
		for(int i = 0; i < e; i++)
		{
			cin>>u>>v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		cout << ob.helpSanta(n, e, g) << endl;
		
	}
}



// } Driver Code Ends