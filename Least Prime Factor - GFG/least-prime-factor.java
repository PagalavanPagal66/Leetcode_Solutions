//{ Driver Code Starts
//Initial Template for Java
import java.util.*;
import java.lang.*;
import java.io.*;
class GFG
{
    public static void main(String[] args) throws IOException
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter out=new PrintWriter(System.out);
        int T = Integer.parseInt(br.readLine().trim());
        while(T-->0)
        {
            int n = Integer.parseInt(br.readLine().trim());
            Solution ob = new Solution();
            int[] ans = ob.leastPrimeFactor(n);
            for(int i = 1; i <=n; i++)
            {
                out.print(ans[i] + " ");
            }
            out.println();
        }
        out.close();
    }
}

// } Driver Code Ends


//User function Template for Java
class Solution
{
   public int[] leastPrimeFactor(int n)
    {
        int[] arr = new int[n+1];
        arr[1]=1;
        int pos =2;
        
        for(int i=2;i<=n;i++){
            
           if(i==2 || i==3 || i==5)
           {
               arr[i]=i;
               continue;
               
           }
            
            arr[i] = leastPrime(i);
            
        }
    
        return arr;
    }
    
    
    
        int leastPrime(int no){
            
            if(no%2==0){
                return 2;
            }
            else if(no%3==0)
            return 3;
            
            for(int i=2;i<=Math.sqrt(no);i++){
                
                if(no%i==0)
                return i;
                
            }
            
            return no;
        }
}