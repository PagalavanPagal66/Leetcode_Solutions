//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:	
		
	int isDivisible(string s){
	    //complete the function here
	     int ans = 0;
        int l = 0;
        int n = s.size();
        for(int i = n-1; i>=0; i--){
            if(s[i]=='1'){
                if(l%2)ans += 2;
                else ans += 1;
            }
            l++; 
        }
        return ans%3==0;
	}

};

//{ Driver Code Starts.
int main(){
    
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        Solution ob;
        cout << ob.isDivisible(s) << endl;
    }
return 0;
}


// } Driver Code Ends