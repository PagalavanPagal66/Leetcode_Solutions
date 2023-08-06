class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int m=0;
        for(auto i:nums){
            m = max(m,i);  
        }
        vector<int>a(m+1,0);
        for(auto i:nums){
            a[i]+=i;
        }
        int ind=2;
        for(ind;ind<=m;ind++){
            a[ind] = max(a[ind-1],a[ind]+a[ind-2]);
        }
        return a[m];
    }
};