class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int prod = 1, zeroCnt = count(begin(nums), end(nums), 0);
        if(zeroCnt > 1) return vector<int>(size(nums));               
        for(auto c : nums) 
            if(c) prod *= c;                                          
        for(auto& c : nums)
            if(zeroCnt) c = c ? 0 : prod;                             
            else c = prod / c;                                       
        return nums;
    }
};