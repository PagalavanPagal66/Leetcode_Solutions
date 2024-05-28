class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        vector<int>cost;
        for(int i=0;i<s.length();i++){
            cost.push_back(abs(s[i]-t[i]));
            cout<<cost[i]<<" ";
        }
        int sum=0;
        int i=0,j=0;
        int n=cost.size();
        int len=0;
        while(i<n){
            if(sum+cost[i]<=maxCost){
                sum+=cost[i];
                len=max(len,i-j+1);
                i++;    
            }
            else{
                sum-=cost[j];
                j++;
            }         
        }
        return len;
    }
};