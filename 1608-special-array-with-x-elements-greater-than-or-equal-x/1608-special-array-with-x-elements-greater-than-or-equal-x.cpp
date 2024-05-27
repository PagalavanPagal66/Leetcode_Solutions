class Solution {
public:
int find(int currElement,vector<int>& nums){
    int start=0,end=nums.size()-1;
    int index=-1;
    while(start<=end){
        int mid=start+(end-start);
        if(nums[mid]>=currElement){
            index=mid;
            end=mid-1;
        }else start=mid+1;
    }
    return index==-1 ? nums.size() : nums.size()-index;
}
    int specialArray(vector<int>& nums) {
        int maxi=*max_element(nums.begin(),nums.end());
        sort(nums.begin(),nums.end());
        for(int i=0;i<=maxi;i++){
            int x=find(i,nums);
           // cout<<x<<endl;
            if(i==x) return i;
        }
        return -1;
    }
};