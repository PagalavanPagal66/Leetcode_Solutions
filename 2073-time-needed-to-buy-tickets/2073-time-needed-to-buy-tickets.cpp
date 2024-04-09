class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int ans=tickets[k];
        for(int i=0;i<k;i++)
        {
            if(tickets[i]>=tickets[k])
            {
                ans+=tickets[k];
            }
            else
            ans+=tickets[i];
        }
        int n=tickets.size();
        for(int i=k+1;i<n;i++)
        {
             if(tickets[i]>=tickets[k])
            {
                ans+=tickets[k]-1;
            }
            else
            ans+=tickets[i];
        }
        return ans;
    }
    
};