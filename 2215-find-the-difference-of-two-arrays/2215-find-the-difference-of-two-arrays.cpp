class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> n1, n2;
        vector<vector<int>> ans;
        for(auto i : nums1) n1[i]++;
        for(auto i : nums2) n2[i]++;
        unordered_set<int> st1, st2;
        vector<int> v1;
        for(int i = 0; i < nums1.size(); i++) {
            if(n2.find(nums1[i]) == n2.end()) {
                st1.insert(nums1[i]);
            }
        }
        for(auto i : st1) v1.push_back(i);
        ans.push_back(v1);

        vector<int> v2;
        for(int i = 0; i < nums2.size(); i++) {
            if(n1.find(nums2[i]) == n1.end()) {
                st2.insert(nums2[i]);
            }
        }
        for(auto i : st2) v2.push_back(i);
        ans.push_back(v2);
        return ans;
    }
};