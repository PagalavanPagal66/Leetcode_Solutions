class Solution {
public:
    int sumDistance(vector<int>& nums, string s, int d) {
        long long mod=10e9+7;
        for(int i=0;i<s.size();i++){
            if(s[i]=='L'){
                nums[i]-=d;
            }
            else{
                nums[i]+=d;
            }
        }
        long long ans=0;
        long long diff=0;
        sort(nums.begin(),nums.end());
        for(long long i=0;i<nums.size();i++){
            ans+=((long long)i*(long long)nums[i]-(long long)diff);
            ans%=(long long)1e9+7;
            diff+=(long long)nums[i];
        }
        return ans;
    }
};