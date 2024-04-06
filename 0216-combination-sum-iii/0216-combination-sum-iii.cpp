class Solution {
public:
    void help(vector<vector<int>>& ans,vector<int> a,int k, int n,int start,int s){
        if(a.size()==k && s==n){
            ans.push_back(a);
            return;
        }
        for(int i=start;i<=9;i++){
            s+=i;
            a.push_back(i);
            help(ans,a,k,n,i+1,s);
            a.pop_back();
            s-=i;
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> a;
        help(ans,a,k,n,1,0);
        return ans;
    }
};