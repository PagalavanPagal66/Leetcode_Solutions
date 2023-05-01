class Solution {
public:
    double average(vector<int>& salary) {
        double res=0;
        int n=salary.size();
        sort(salary.begin(),salary.end());
        for(int i=1;i<n-1;i++){
            res+=salary[i];
        }
        return res/(1.0*(n-2));
    }
};