class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int n=nums.size();
        int ans=0;
        for(auto i:nums){
            ans^=i;
        }
        int bit=1;
        int val=0;
        for(int i=0;i<32;i++){
            int mask = bit<<i; 
            if((ans&mask)!=(k&mask)){
                val++;
            }
        }
        return val;
    }
};