//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    string longestPalin (string s) {
        // code here
        int mini = INT_MIN;
        string ans = "";
        // odd
        for (int i = 0; i < s.size(); i++)
        {
            int start = i, end = i;
            while (start >= 0 && end < s.size())
            {
                if (s[start] != s[end])
                    break;
                if (end - start + 1 > mini)
                {
                    mini = end - start + 1;
                    ans = s.substr(start, end - start + 1);
                }
                start--;
                end++;
            }
        }
        // even
        for (int i = 0; i < s.size() - 1; i++)
        {
            if (s[i] == s[i + 1])
            {
                int start = i, end = i+1;
                while (start >= 0 && end < s.size())
                {
                    if (s[start] != s[end])
                        break;
                    if (end - start + 1 > mini)
                    {
                        mini = end - start + 1;
                        ans = s.substr(start, end - start + 1);
                    }
                    start--;
                    end++;
                }
            }
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
        string S; cin >> S;
        
        Solution ob;
        cout << ob.longestPalin (S) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends