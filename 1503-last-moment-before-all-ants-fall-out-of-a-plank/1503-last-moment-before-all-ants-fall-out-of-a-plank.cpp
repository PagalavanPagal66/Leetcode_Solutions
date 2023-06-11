class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        int res=0;
        for(int it:left)res=max(it,res);
        for(int it:right)res=max(n-it,res);
        return res;
    }
};