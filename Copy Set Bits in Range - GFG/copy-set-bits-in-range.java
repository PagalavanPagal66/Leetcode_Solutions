//{ Driver Code Starts
//Initial Template for Java
import java.io.*;
import java.util.*;

class GFG{
    public static void main(String args[])throws IOException{
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(in.readLine());
        while(t-- > 0){
            String line[] = in.readLine().trim().split("\\s+");
            int x = Integer.parseInt(line[0]);
            int y = Integer.parseInt(line[1]);
            int l = Integer.parseInt(line[2]);
            int r = Integer.parseInt(line[3]);
            
            Solution ob = new Solution();
            System.out.println(ob.setSetBit(x, y, l, r));
        }
    }
}
// } Driver Code Ends


//User function Template for Java

class Solution{
    static int setSetBit(int x, int y, int l, int r){
        // code here
        int result = x;
        int pow = 1;
        int digit =1;
        while(digit!=l){
            x=x/2;
            y=y/2;
            if(digit!=1){
                pow= pow*2;
            } 
            digit++;
        }
        for(int i =1; i<=r-l+1; i++){
            if(digit != 1){
                pow = pow*2;
            } else {
                digit++;
            }
            if(y==1){
                int bitx = x%2;
                if(bitx ==0){
                    result+=pow;
                }
                return result;
            }
            int bitx = x%2;
            int bity = y%2;
            if(bity ==1 && bitx==0){
                 result+=pow;
            }
            x = x/2;
            y = y/2;
        }
        return result;
    }

}