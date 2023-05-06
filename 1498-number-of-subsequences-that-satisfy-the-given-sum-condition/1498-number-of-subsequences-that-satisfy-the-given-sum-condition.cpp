class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
    sort(nums.begin(),nums.end());
    int i=0;
    int n=nums.size();
    vector<int>v(n,1);
    int mod = 1e9 + 7;
    long long int t=1000000;
    for(int i=1;i<n;i++)
    {
        v[i]=(2*v[i-1])%mod;
    }
    long long int count=0;
    int j=nums.size()-1;
    while(i<=j)
    {
        if(nums[i]+nums[j]<=target)
        {
            count+=v[j-i];
            count=count%mod;
            i++;
        }
        else
        {
            j--;
        }
    }
    return count;
    }
};