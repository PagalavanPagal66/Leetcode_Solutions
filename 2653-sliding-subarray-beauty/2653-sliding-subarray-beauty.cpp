class Solution {
public:
    int it(int x,int mp[]){
            int ans=0;
            int cnt=0;
            for(int i=50;i>=1;i--){
                if(mp[i]>0){
                    cnt+=mp[i];
                    if(cnt>=x){
                        ans=(-i);
                        break;
                    }
                }
            }
            return ans;
    }
    vector<int> getSubarrayBeauty(vector<int>& nums, int k, int x) {
        int n=nums.size();
        int len=n-k+1;
        vector<int>ans(len);
        int mp[51]={0};
        for(int i=0;i<k;i++){
            if(nums[i]<0){
                mp[abs(nums[i])]++;
            }
        }
        ans[0]=it(x,mp);
        for(int i=1;i<=n-k;i++){
            if(nums[i+k-1]<0){
                mp[abs(nums[i+k-1])]++;
            }
            if(nums[i-1]<0){   
                mp[abs(nums[i-1])]--;
            }
            ans[i]=it(x,mp);
        }
        return ans;
    }
};