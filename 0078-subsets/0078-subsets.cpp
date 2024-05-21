class Solution {
public:
    void help(vector <int> &nums,vector <vector<int>> &ans,int i,vector<int>v){
    if(i>=nums.size()){
       ans.push_back(v);
        return;
    }
        
    help(nums,ans,i+1,v);
    v.push_back(nums[i]);
    help(nums,ans,i+1,v);
    v.pop_back();
}
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int>v;
        help(nums,ans,0,v);
        return ans;
        
    }
    
};