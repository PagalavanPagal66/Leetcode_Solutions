class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int n=nums.size();
        int m=nums[0].size();
        vector<pair<int,int>>arr;
        for(int i=0;i<n;i++){
            for(auto j:nums[i]){
                arr.push_back({j,i});
            }
        }
        sort(arr.begin(),arr.end());
        int st=0,en=0;
        int tot=arr.size();
        int cnt=0;
        vector<int>ans;
        int dis=INT_MAX;
        unordered_map<int,int>mp;
        while(st!=tot){
            mp[arr[st].second]++;
            if(mp[arr[st].second]==1){
                cnt++;
            }
            if(cnt==n){
                int d=arr[st].first-arr[en].first+1;
                if(d<dis){
                    dis=d;
                    ans={arr[en].first,arr[st].first};
                }
            }
            if(cnt==n){
                while(cnt==n){
                    int t=arr[en].second;
                    if(mp[t] > 1)mp[t]--,en++;
                    else break;
                }
                int d=arr[st].first-arr[en].first+1;
                if(d<dis){
                    dis=d;
                    ans={arr[en].first,arr[st].first};
                }
            }
            st++;
        }
        return ans;
    }
};