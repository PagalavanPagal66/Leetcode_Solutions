class Solution {
public:
    int counter(vector<int>&nums,int k){
        int n=nums.size();
        unordered_map<int,int>mp;
        int i=0,j=0;
        int ans=0;
        while(i<n){
            mp[nums[i]]++;
            while(mp.size() == k+1){
                mp[nums[j]]--;
                if(mp[nums[j]]==0){
                    mp.erase(nums[j]);
                }
                j++;
            }
            ans+=i-j+1;
            i++;
        }
        return ans;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int a = counter(nums,k-1);
        int b = counter(nums,k);
        cout<<a<<" "<<b<<endl;
        return (b-a);
    }
};