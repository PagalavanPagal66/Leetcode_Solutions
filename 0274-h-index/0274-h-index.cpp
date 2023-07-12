class Solution {
public:
    int hIndex(vector<int>& citations) {
         int mx = *max_element(citations.begin(), citations.end());
         vector<int> post_sum(mx + 1, 0);
         
         for(int ele : citations){
             post_sum[ele]++;
         }
        
         for(int i=post_sum.size() - 2; i>0; i--){
              post_sum[i] = post_sum[i] + post_sum[i+1];
         }
        
         int ans = 0;
        
         for(int i=1; i<post_sum.size(); i++){
             if(post_sum[i] >= i){
                 ans = max(ans, i);
             }
         }
        return ans;
    }
};