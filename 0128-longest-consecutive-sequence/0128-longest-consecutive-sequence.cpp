class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>s;
          int cnt;
          int maxi = 0;     
        for(int i  =0;i<nums.size();i++){
        s.insert(nums[i]);
        }
        for(auto x :s){
            
            if(s.find(x-1)==s.end()){
                cnt =1;
                while(s.find(x+1)!=s.end()){
                    x=x+1;
                    cnt++;
                }
                maxi = max(maxi,cnt);
            }
        }
        return maxi;
    }
};