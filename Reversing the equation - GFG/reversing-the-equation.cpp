//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
  public:
    string reverseEqn (string s)
    {
        int i=0;
        int n=s.size();
        stack<string> st;
        while(i<n)
        {
            if(s[i]>='0' && s[i]<='9')
            {
                string a;
                while(i<n && s[i]>='0' && s[i]<='9')
                {
                    a+=s[i];
                    i++;
                }
                i--;
                st.push(a);
            }
            else
            {
                string a;
                a+=s[i];
                st.push(a);
            }
            i++;
        }
        string ans;
        while(st.size()>0)
        {
            ans+=st.top();
            st.pop();
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        cout <<ob.reverseEqn (s) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends