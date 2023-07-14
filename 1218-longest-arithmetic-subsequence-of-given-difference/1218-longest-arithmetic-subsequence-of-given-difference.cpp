class Solution
{
public:
    vector<vector<int>> dp;
    int longestSubsequence(vector<int> &arr, int difference)
    {
        unordered_map<int, int> Terms_till_now;
        int max_length = 1;
        for(int curr_element : arr)
        {
            Terms_till_now[curr_element] = Terms_till_now[curr_element - difference] + 1;
            max_length = max(max_length, Terms_till_now[curr_element]); 
        }
        return max_length;
    }
};