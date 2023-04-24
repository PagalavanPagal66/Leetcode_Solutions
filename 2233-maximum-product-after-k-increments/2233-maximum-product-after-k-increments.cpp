class Solution {
public:
    int maximumProduct(vector<int>& nums, int k) {
        long long ans=1;
        priority_queue<int,vector<int>,greater<int>>pq;
        for(auto i:nums){
            pq.push(i);
        }
        while(k--){
            int t=pq.top();
            t++;
            pq.pop();
            pq.push(t);
        }
        long long MOD=1000000007;
        while(!pq.empty()){
            ans*=pq.top();
            ans%=MOD;
            pq.pop();
        }
        return ans;
    }
};