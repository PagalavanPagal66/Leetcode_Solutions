class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        vector<int> ans;
        for(int i=0;i<nums.size();i++){
            if(!dq.empty() && dq.front() == i-k){
                // we have moved the sliding window away from the (i-k , which is the front element in the deque)
                dq.pop_front();
            }
            while(!dq.empty() && nums[dq.back()]<nums[i]){
                // we are having a larger element in our hand (i). So, we dont need the previous smaller elements
                dq.pop_back();
            }
            dq.push_back(i);
            // current element 1) larger -> this is the recent and largest. So it will travel with us. so updating
            //                 2) smaller -> this will be the next maximum
            if(i>=k-1)
            {
                // we have crossed the length of the sub array. so the answers will going to be the front element of the deque.
                ans.push_back(nums[dq.front()]);
            }
        }
        return ans;
    }
};
 