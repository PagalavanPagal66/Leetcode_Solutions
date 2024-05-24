class Solution {
public:
    int maxJump(vector<int>& stones) {
        int n=stones.size();
        if(n==2 or n==3) return stones[n-1]-stones[0];
        vector<int> odd,even;
        int ans=INT_MIN;
        for(int i=0;i<n;i++){
            if(i%2==0) even.push_back(stones[i]);
            else odd.push_back(stones[i]);
        }
        if(odd.size()>=2){
            for(int i=1;i<odd.size();i++) ans=max(ans,odd[i]-odd[i-1]);
        }
        if(even.size()>=2){
            for(int i=1;i<even.size();i++) ans=max(ans,even[i]-even[i-1]);
        }
        return ans;
    }
};