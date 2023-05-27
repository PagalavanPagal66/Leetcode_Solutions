class Solution {
public:
    int stoneGameVI(vector<int>& a, vector<int>& b) {
        vector<pair<int,int>>v;
        int n=a.size();
        for(int i=0;i<n;i++){
            v.push_back({a[i]+b[i],i});
        }
        sort(v.rbegin(),v.rend());
        int alice=0,bob=0;
        int f=0;
        for(auto i:v){
            if(!f){
                f=1;
                alice+=a[i.second];
            }
            else{
                f=0;
                bob+=b[i.second];
            }
        }
        if(alice>bob){
            return 1;
        }
        if(alice==bob){
            return 0;
        }
        return -1;
    }
};