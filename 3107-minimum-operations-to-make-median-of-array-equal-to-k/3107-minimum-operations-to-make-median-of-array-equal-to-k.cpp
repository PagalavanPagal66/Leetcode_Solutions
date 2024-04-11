class Solution {
public:
    #define ll long long
    long long minOperationsToMakeMedianK(vector<int>& nums, int k) {
        ll ans=0;
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int mid = n/2;
        if(nums[mid] == k){
            //cout<<k<<endl;
            return ans;
        }
        if(nums[mid]>k){
            
            for(int i=mid-1;i>=0;i--){
                if(nums[i]>k){
                    ans += (ll)(nums[i]-k);
                }
            }
            ans+=(ll)(nums[mid]-k);
            return ans;
        }
        else{
            for(int i=mid+1;i<n;i++){
                if(nums[i]<k){
                    ans+=(ll)(k-nums[i]);
                }
            }
            ans+=(ll)(k-nums[mid]);
            return ans;
        }
        return ans;
    }
};