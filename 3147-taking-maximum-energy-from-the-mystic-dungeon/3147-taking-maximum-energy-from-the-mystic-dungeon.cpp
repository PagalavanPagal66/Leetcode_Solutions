class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
        int n=energy.size();
        int ans=INT_MIN;
        vector<int> use(k,0);
        for(int i=n-1;i>=0;i--){
            use[i%k]+=energy[i];
            ans=max(ans,use[i%k]);
        }
        return ans;
    }
};