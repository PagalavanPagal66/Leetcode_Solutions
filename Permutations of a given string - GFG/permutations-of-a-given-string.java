//{ Driver Code Starts
import java.util.*;
import java.lang.*;
import java.io.*;
class GFG
{
	public static void main(String[] args) throws IOException
	{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter out=new PrintWriter(System.out);
        int t = Integer.parseInt(br.readLine().trim());
        while(t-->0)
        {
            String S = br.readLine().trim();
            Solution obj = new Solution();
            List<String> ans = obj.find_permutation(S);
            for( int i = 0; i < ans.size(); i++)
            {
                out.print(ans.get(i)+" ");
            }
            out.println();
                        
        }
        out.close();
	}
}


// } Driver Code Ends

class Solution {
    char[] arr;
    int n, m;
    HashSet<String> visited;
    private List<String> solve(int mask) {
        List<String> ans = new ArrayList<>();
        if(mask == m) {
            ans.add("");
            return ans;
        }
        
        for(int j = 0; j < n; j++) {
            if(((1 << j) & mask) == 0) {
                List<String> res = solve(((1 << j) ^ mask));
                for(String s : res) {
                    String x = (Character.toString(arr[j]) + s);
                    if(x.length() == n && visited.contains(x)) {
                        continue;
                    }
                    
                    if(x.length() == n) {
                        visited.add(x);
                    }
                    
                    ans.add(x);
                }
            }
        }
        
        return ans;
        
    }
    
    public List<String> find_permutation(String S) {
        this.n = S.length();
        this.visited = new HashSet<>();
        this.m = ((int)Math.pow(2, this.n)) - 1;
        this.arr = S.toCharArray();
        Arrays.sort(arr);
        
        return solve(0);
    }
}