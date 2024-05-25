class Solution {
public:
    vector<int> occurrencesOfElement(vector<int>& nums, vector<int>& queries, int x) {
        vector<int>index;
        for(int i=0;i<nums.size();i++){
            if(nums[i] == x){
                index.push_back(i);
            }
        }
        vector<int>ans;
        for(auto& i:queries){
            if(i>index.size()){
                ans.push_back(-1);
            }
            else{
                ans.push_back(index[i-1]);
            }
        }
        return ans;
    }
};