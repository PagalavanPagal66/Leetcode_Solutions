//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    int maxEqualSum(int N1, int N2, int N3, std::vector<int>& S1, std::vector<int>& S2, std::vector<int>& S3) {
        int sum1 = 0, sum2 = 0, sum3 = 0;
        int i = 0, j = 0, k = 0;
        
        for (int x : S1) sum1 += x;
        for (int x : S2) sum2 += x;
        for (int x : S3) sum3 += x;
        
        while (i < N1 && j < N2 && k < N3) {
            int minSum = std::min({sum1, sum2, sum3});
            int maxSum = std::max({sum1, sum2, sum3});
            
            if (minSum == maxSum) {
                return minSum;
            }
            
            if (maxSum == sum1) {
                sum1 -= S1[i++];
            } else if (maxSum == sum2) {
                sum2 -= S2[j++];
            } else {
                sum3 -= S3[k++];
            }
        }
        
        return 0;
    }
};

//{ Driver Code Starts.

int main(){
    
    int t;
    cin>>t;
    while(t--){
        int n1,n2,n3;
        cin>>n1>>n2>>n3;
        vector<int> s1(n1),s2(n2),s3(n3);
        for(int i=0;i<n1;i++){
            cin>>s1[i];
        }
        for(int i=0;i<n2;i++){
            cin>>s2[i];
        }
        for(int i=0;i<n3;i++){
            cin>>s3[i];
        }
        Solution ob;
        int ans=ob.maxEqualSum(n1,n2,n3,s1,s2,s3);
        cout<<ans<<endl;
    }
    
    return 0;
}
// } Driver Code Ends