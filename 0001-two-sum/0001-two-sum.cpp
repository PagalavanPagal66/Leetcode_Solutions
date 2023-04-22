class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int>v(2);
        unordered_map<int,int>mp;
        int n=nums.size();
        for(int i=0;i<n;i++){
            int a=nums[i]; //4
            int b=target-nums[i]; //2
            if(mp.find(b)!=mp.end()){ //true
                int second_value_index=mp[b];
                v[0]=second_value_index; //1
                v[1]=i; //2
                return v;
            }
            mp[nums[i]]=i; // 3-0 , 2-1 , 
        }
        return v;
    }
};