class Solution {
public:
    void com(vector<vector<int>>&v,int n,int k,int ind,vector<int> curr){
        if(ind+k>n+1){
            return;
        }
        if(ind>n){
            if(k==0){
                v.push_back(curr);
            }
            return;
        }
        curr.push_back(ind);
        com(v,n,k-1,ind+1,curr);
        curr.pop_back();
        com(v,n,k,ind+1,curr);
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>>res;
        vector<int>curr;
        com(res,n,k,1,curr);
        return res;
    }
};