class Solution {
public:
       bool find132pattern(vector<int>& nums) {
        int med = INT_MIN;
        stack<int> st;
        for( int i = nums.size()-1; i >= 0; i -- ){
            if( nums[i] < med ) return true;  // it will get possibility of true only when med value is subst other then int_min ( we have found large and medium borders) (only after a get executed)
            else
            {
              while( !st.empty() && nums[i] > st.top() ){ 
                    //a
                  med = st.top(); 
                  st.pop(); 
                }
            }
            st.push(nums[i]);
        }
        return false;
    }
};