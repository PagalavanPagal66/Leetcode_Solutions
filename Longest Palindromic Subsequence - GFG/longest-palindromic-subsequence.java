//{ Driver Code Starts
//Initial Template for Java

import java.io.*;
import java.util.*;

class GfG
{
    public static void main(String args[])
        {
            Scanner sc = new Scanner(System.in);
            int t = sc.nextInt();
            while(t-->0)
                {
                    String s = sc.next();
                    Solution obj = new Solution();
                    System.out.println(obj.longestPalinSubseq(s));
                }
                
        }
}
// } Driver Code Ends


//User function Template for Java
class Solution
{
    public int longestPalinSubseq(String S)
    {
        int n = S.length();
        int[][] dp = new int[n][n];

        // All characters in the string are palindromic of length 1
        for (int i = 0; i < n; i++)
            dp[i][i] = 1;

        // Finding palindromic subsequences of length 2 to n
        for (int cl = 2; cl <= n; cl++) {
            for (int i = 0; i < n - cl + 1; i++) {
                int j = i + cl - 1;
                if (S.charAt(i) == S.charAt(j) && cl == 2)
                    dp[i][j] = 2;
                else if (S.charAt(i) == S.charAt(j))
                    dp[i][j] = dp[i + 1][j - 1] + 2;
                else
                    dp[i][j] = Math.max(dp[i][j - 1], dp[i + 1][j]);
            }
        }

        // Length of the longest palindromic subsequence in the entire string
        return dp[0][n - 1];
    }
}