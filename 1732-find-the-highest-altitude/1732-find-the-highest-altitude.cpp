class Solution {
public:
    int largestAltitude(vector<int>& gain) 
    {
         int ans=0;
         int n=gain.size();
        
        ans = max(ans,(ans+gain[0]));
        for(int i=1;i<n;i++)
        {
            
            gain[i] = gain[i]+gain[i-1];
            ans = max(ans,gain[i]);
        }
      return ans;
    }
};