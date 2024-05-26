class Solution {
public:
    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        unordered_map<int, int> map;
        for(auto& val : nums2) {
            map[val]++;
        }
        long long output = 0ll;
        for(int i = 0; i< nums1.size(); i++) {
            int x = nums1[i];
            for(int j = 1; j <= (int)(sqrt(x)); j++) {
                if (x%j == 0) {
                    int f1 =j, f2 = x/j;                    
                    if (map.count(f1) && x%(f1*k) == 0) {
                       output = output + 0ll + map[f1];
                    }                    
                    if (map.count(f2) && (x%(f2*k) == 0) && f1 != f2) {
                        output = output + 0ll + map[f2];
                    }
                }
            }
        }
        return output;
    }
};