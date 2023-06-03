class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,int>mp;
        int cnt=0;
        int maxi = 0;     
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        for(auto i :mp){
            int x=i.first;
            if(mp.find(x-1)==mp.end()){ //x-1 not found
                cnt=1;
                while(mp.find(x+1)!=mp.end()){ // x+1 found
                    x=x+1;
                    cnt++;
                }
                maxi = max(maxi,cnt);
            }
        }
        return maxi;
    }
};